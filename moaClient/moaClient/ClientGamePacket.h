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
        
        CANCEL_CREATE_BUILDING_REQ,
        CANCEL_CREATE_BUILDING_RES,
        
        UPGRADE_BUILDING_REQ,
        UPGRADE_BUILDING_RES,
        
        CANCEL_UPGRADE_BUILDING_REQ,
        CANCEL_UPGRADE_BUILDING_RES,
        
        CREATE_UNIT_REQ,
        CREATE_UNIT_RES,
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
	};
    
    struct CreateBuildingResPacket : public EmptyPacket
    {
        CreateBuildingResPacket() { cmd = CREATE_BUILDING_RES; }
        
        int8_t objectType;
    };

    struct CancelCreateBuildingReqPacket : public EmptyPacket
	{
        CancelCreateBuildingReqPacket() { cmd = CANCEL_CREATE_BUILDING_REQ; }

        int32_t objectNo;
	};
    
    struct CancelCreateBuildingResPacket : public EmptyPacket
    {
        CancelCreateBuildingResPacket() { cmd = CANCEL_CREATE_BUILDING_RES; }
        
        int32_t objectNo;
    };
    
    struct UpgradeBuildingReqPakcet : public EmptyPacket
    {
        UpgradeBuildingReqPakcet() { cmd = UPGRADE_BUILDING_REQ; }
        
        int32_t objectNo;
        int8_t upgradeType;
    };
    
    struct UpgradeBuildingResPakcet : public EmptyPacket
    {
        UpgradeBuildingResPakcet() { cmd = UPGRADE_BUILDING_RES; }
        
        int32_t objectNo;
        int8_t upgradeType;
    };
    
    struct CancelUpgradeBuildingReqPakcet : public EmptyPacket
    {
        CancelUpgradeBuildingReqPakcet() { cmd = CANCEL_UPGRADE_BUILDING_REQ; }
        
        int32_t objectNo;
        int8_t upgradeType;
    };
    
    struct CancelUpgradeBuildingResPakcet : public EmptyPacket
    {
        CancelUpgradeBuildingResPakcet() { cmd = CANCEL_UPGRADE_BUILDING_RES; }
        
        int32_t objectNo;
        int8_t upgradeType;
    };
    
    struct CreateUnitReqPacket : public EmptyPacket
    {
        CreateUnitReqPacket() { cmd = CREATE_UNIT_REQ; }
        
        int32_t objectNo; // building number
        int8_t objectType; // unit type
        int8_t objectCount;
        int16_t lineNo;
    };
    
    struct CreateUnitResPacket : public EmptyPacket
    {
        CreateUnitResPacket() { cmd = CREATE_UNIT_RES; }
        
        int32_t objectNo;
        int8_t objectType;
        int8_t objectCount;
        int16_t lineNo;
    };
};

#pragma pack(pop)
#endif //__CLIENT_LOBBY_PACKET_H__
