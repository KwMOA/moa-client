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
		CREATE_BUILDING_REQ = 10,
		CREATE_BUILDING_RES,
        
        CANCEL_BUILDING_REQ,
        CANCEL_BUILDING_RES,
        
        WORK_BUILDING_REQ,
        WORK_BUILDING_RES,
	};


	///////////////////////////////////

#pragma pack(push, 1)

	///////////////////////////////////


    struct CreateBuildingReqPacket : public Packet
	{
        CreateBuildingReqPacket() { cmd = CREATE_BUILDING_REQ; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t position;
	};
    
    struct CreateBuildingResPacket : public Packet
    {
        CreateBuildingResPacket() { cmd = CREATE_BUILDING_RES; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t position;
    };

    struct CancelBuildingReqPacket : public Packet
	{
        CancelBuildingReqPacket() { cmd = CANCEL_BUILDING_REQ; }

        int32_t objectNo;
	};
    
    struct CancelBuildingResPacket : public Packet
    {
        CancelBuildingResPacket() { cmd = CANCEL_BUILDING_RES; }
        
        int32_t objectNo;
    };
    
    struct WorkBuildingReqPakcet : public Packet
    {
        WorkBuildingReqPacket() { cmd = WORK_BUILDING_REQ; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t lineNo;
    };
    
    struct WorkBuildingResPakcet : public Packet
    {
        WorkBuildingResPakcet() { cmd = WORK_BUILDING_RES; }
        
        int32_t objectNo;
        int8_t buttonNo;
        int16_t lineNo;
    };
    
    
};

#pragma pack(pop)
#endif //__CLIENT_LOBBY_PACKET_H__
