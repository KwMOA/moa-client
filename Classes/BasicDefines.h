#ifndef __BASIC_DEFINES_H__
#define __BASIC_DEFINES_H__


//network defines
#define PLATFORM_LINUX 1
#define PLATFORM_WINDOWS 2

#define OS_PLATFORM PLATFORM_LINUX

#if OS_PLATFORM == PLATFORM_WINDOWS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#endif

//display defines

#define DISPLAY_WIDTH 1280
#define DISPLAY_HEIGHT 720

#define NETWORK_FPS 18

#define PLAY_ALONE 1
#define NOT_CONNECT_WITH_SERVER 1


#endif //__BASIC_DEFINES_H__
