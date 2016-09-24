#ifndef __BASIC_PACKET_H__
#define __BASIC_PACKET_H__

#include <stdint.h>
#include <limits.h>

typedef uint32_t command_t;

////////////Packet Command//////////////

static const int32_t PACKET_VERSION = 1;


///////////////////////////////////

#pragma pack(push, 1)

struct Packet
{
    command_t cmd;
};

#pragma pack(pop)


#endif //__CLIENT_LOBBY_PACKET_H__

