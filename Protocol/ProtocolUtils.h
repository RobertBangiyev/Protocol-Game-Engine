#pragma once

#ifdef PROTOCOL_WINDOWS
	#ifdef PROTOCOL_LIB
		#define PROTOCOL_API __declspec(dllexport)
	#else
		#define PROTOCOL_API __declspec(dllimport)
	#endif
#else
	#define PROTOCOL_API
#endif

#ifdef PROTOCOL_DEBUG
	#define PROTOCOL_LOG(x) std::cout<<x<<std::endl;
#else
	#define PROTOCOL_LOG(x)
#endif