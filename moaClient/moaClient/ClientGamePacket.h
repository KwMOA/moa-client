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
        EMPTY_RES = 10,
        
		CREATE_BUILDING_REQ,
		CREATE_BUILDING_RES,
        
        CANCEL_BUILDING_REQ,
        CANCEL_BUILDING_RES,
        
        WORK_BUILDING_REQ,
        WORK_BUILDING_RES,
	};


	///////////////////////////////////

#pragma pack(push, 1)

	///////////////////////////////////

    struct EmptyPacket : public Packet
    {
        EmptyPacket() { cmd = EMPTY_RES; }
        
        int32_t packetNo;
        int8_t isEnemy;
    };

    struct CreateBuildingReqPacket : public EmptyPacket
	{
        CreateBuildingReqPacket() { cmd = CREATE_BUILDING_REQ; }
        
        int8_t objectType;
        int16_t position;
	};
    
    struct CreateBuildingResPacket : public EmptyPacket
    {
        CreateBuildingResPacket() { cmd = CREATE_BUILDING_RES; }
        
        int8_t objectType;
        int16_t position;
    };

    struct CancelBuildingReqPacket : public EmptyPacket
	{
        CancelBuildingReqPacket() { cmd = CANCEL_BUILDING_REQ; }

        int32_t objectNo;
	};
    
    struct CancelBuildingResPacket : public EmptyPacket
    {
        CancelBuildingResPacket() { cmd = CANCEL_BUILDING_RES; }
        
        int32_t objectNo;
    };
    
    struct WorkBuildingReqPakcet : public EmptyPacket
    {
        WorkBuildingReqPakcet() { cmd = WORK_BUILDING_REQ; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t lineNo;
    };
    
    struct WorkBuildingResPacket : public EmptyPacket
    {
        WorkBuildingResPacket() { cmd = WORK_BUILDING_RES; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t lineNo;
    };
    
    
};

#pragma pack(pop)
#endif //__CLIENT_LOBBY_PACKET_H__
