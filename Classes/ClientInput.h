

#ifndef __CLIENT_INPUT_H__
#define __CLIENT_INPUT_H__

#include <stdio.h>


////////////Packet Command//////////////

static const int32_t CLIENT_INPUT_PACKET_VERSION = 1;

enum CLIENT_INPUT_TYPE // start number is at least 3.
{
    CLIENT_INPUT_TYPE_EMPTY = 1,
    
    CLIENT_INPUT_TYPE_CREATE_BUILDING,
    
    CLIENT_INPUT_TYPE_CANCEL_CREATE_BUILDING,
    
    CLIENT_INPUT_TYPE_UPGRADE_BUILDING,
    
    CLIENT_INPUT_TYPE_CANCEL_UPGRADE_BUILDING,
    
    CLIENT_INPUT_TYPE_CREATE_UNIT,
};


///////////////////////////////////

#pragma pack(push, 1)

///////////////////////////////////

struct ClientInput
{
    ClientInput() {  }
    
    int8_t inputType;
};

struct CreateBuildingCI : public ClientInput
{
    CreateBuildingCI() { inputType = CLIENT_INPUT_TYPE_CREATE_BUILDING; }
    
    int8_t objectType;
};

struct CancelCreateBuildingCI : public ClientInput
{
    CancelCreateBuildingCI() { inputType = CLIENT_INPUT_TYPE_CANCEL_CREATE_BUILDING; }
    
    int32_t objectNo;
};


struct UpgradeBuildingCI : public ClientInput
{
    UpgradeBuildingCI() { inputType = CLIENT_INPUT_TYPE_UPGRADE_BUILDING; }
    
    int32_t objectNo;
    int8_t upgradeType;
};


struct CancelUpgradeBuildingCI : public ClientInput
{
    CancelUpgradeBuildingCI() { inputType = CLIENT_INPUT_TYPE_CANCEL_UPGRADE_BUILDING; }
    
    int32_t objectNo;
    int8_t upgradeType;
};


struct CreateUnitCI : public ClientInput
{
    CreateUnitCI() { inputType = CLIENT_INPUT_TYPE_CREATE_UNIT; }
    
    int32_t objectNo; // building number
    int8_t objectType; // unit type
    int8_t objectCount;
    int8_t lineNo;
};


#pragma pack(pop)




//패킷 번호가 붙여진 메시지
class ClientInputWithPacketNo{
public:
    int packetNo;
    ClientInput* ci;
    ClientInputWithPacketNo(int pn, ClientInput* _ci)
    {
        packetNo = pn;
        ci = _ci;
    }
};


#endif //__CLIENT_INPUT_H__
