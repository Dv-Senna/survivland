#pragma once


#ifdef DEBUG
	#ifndef GM_DEBUG
		#define GM_DEBUG
	#endif
#else
	#ifdef GM_DEBUG
		#define DEBUG
	#else
		#ifndef NDEBUG
			#define NDEBUG
		#endif
	#endif
#endif