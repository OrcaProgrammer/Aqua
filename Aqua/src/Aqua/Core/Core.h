#pragma once

#ifdef AQ_PLATFORM_WINDOWS
	#ifdef AQ_BUILD_DLL
		#define AQUA_API __declspec(dllexport)
	#else
		#define AQUA_API __declspec(dllimport)
	#endif
#endif