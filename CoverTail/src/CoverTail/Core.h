#pragma once

#ifdef CT_PLATFORM_WINDOWS
	#ifdef CT_BUILD_DLL
		#define CoreTail_API __declspec(dllexport)
	#else 
		#define CoreTail_API __declspec(dllimport)
	#endif
 
#else 
	#error CoreTail only support Windows platform!
#endif

#define BIT(x) (1 << x)