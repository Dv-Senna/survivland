workspace "challenge1"
	configurations {"Debug", "Release"}
	newoption {
		trigger     = "platform",
		value       = "PLATFORM",
		description = "Set build platform",
		allowed = {
			{ "Windows",     "Windows" },
			{ "Linux",       "Linux" },
			{ "MacOS_Intel", "Intel MacOSX" },
			{ "MacOS_M1",    "M1 MacOSX" },
		}
	}

	filter "options:platform=MacOS_M1"
		architecture "arm64"
		system "macosx"

	filter "not options:platform=MacOS_M1"
		architecture "x86_64"

	filter "options:platform=MacOS_Intel"
		system "macosx"

	filter "options:platform=Linux"
		system "linux"

	filter "options:platform=Windows"
		system "windows"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "challenge1"
	location "."
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetname "prog"
	targetdir("bin/" .. outputdir)
	objdir("obj/" .. outputdir)

	files {
		"src/**.cpp",
		"src/**.inl",

		"include/%{prj.name}/**.hpp",
		"include/%{prj.name}/**.inl"
	}

	includedirs {
		"include",
		"include/%{prj.name}"
	}

	libdirs {
		"lib"
	}

	links {
		"mingw32",
		"SDL2main",
		"SDL2",
		"opengl32",
		"glad"
	}




	filter "system:windows"
		defines {
			"GM_PLATFORM_WINDOWS"
		}

	filter "system:macosx"
		defines {
			"GM_PLATFORM_MACOS"
		}
		
	filter "system:linux"
		defines {
			"GM_PLATFORM_LINUX"
		}


	filter "configurations:Debug"
		defines {
			"GM_DEBUG",
			"DEBUG"
		}

		symbols "On"

	filter "configurations:Release"
		defines {
			"GM_RELEASE",
			"NDEBUG"
		}

		optimize "On"