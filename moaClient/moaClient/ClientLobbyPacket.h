#ifndef __CLIENT_LOBBY_PACKET_H__
#define __CLIENT_LOBBY_PACKET_H__

#include "BasicPacket.h"

class ClientGamePacket
{
public:

	////////////Packet Command//////////////

	static const int32_t PACKET_VERSION = 1;

	enum EnumCommand // start number is at least 3.
	{
		FIRST_CONNECT_REQ = 10,
		FIRST_CONNECT_RES,
		FIRST_CONNECT_FAIL,
        FIRST_CONNECT_OK,
        FIRST_CONNECT_OUT,
	};


	///////////////////////////////////

#pragma pack(push, 1)

	///////////////////////////////////


    struct FirstConnectReqPacket : public Packet
	{
        FirstConnectReqPacket() { cmd = FIRST_CONNECT_REQ; }
        
		SessionId_t sid;
	};

    struct FirstConnectResPacket : public Packet
	{
        FirstConnectResPacket() { cmd = FIRST_CONNECT_RES; }

        char chattingIp[MAX_IP_ADDRESS_LEN];
        int16_t chattingPort;
        
        UserInfo userInfo;
        
        int8_t friendCount;
        NickNameInfoWithOnline nickNameInfoWithOnlineList[MAX_FRIEND_COUNT];
        
        ClanInfo clanInfo;
	};
    
    struct FirstConnectOkPacket : public Packet
    {
        FirstConnectOkPacket() { cmd = FIRST_CONNECT_OK; }
        
    };
    
    struct FirstConnectOutPacket : public Packet
    {
        FirstConnectOutPacket() { cmd = FIRST_CONNECT_OUT; }
        
    };

    struct GetChannelListReqPacket : public Packet
    {
        GetChannelListReqPacket() { cmd = GET_CHANNEL_LIST_REQ; }
        
    };
};

#pragma pack(pop)
#endif //__CLIENT_LOBBY_PACKET_H__
