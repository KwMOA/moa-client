#ifndef __AUTO_TASK_PACKET_H__
#define __AUTO_TASK_PACKET_H__

#include "BasicPacket.h"

class AutoTaskPacket
{
public:

	////////////Packet Command//////////////

	static const int32_t PACKET_VERSION = 1;

	enum EnumCommand // start number is at least 3.
	{
		EMPTY_RES = 10,

		BUILD_BUILDING_REQ,
		BUILD_BUILDING_RES,

	};


	///////////////////////////////////


	///////////////////////////////////

	struct EmptyPacket : public Packet
	{
		EmptyPacket() { cmd = EMPTY_RES; }

		int32_t packetNo;
		int8_t isEnemy;
	};

	struct BuildBuildingPacket : public EmptyPacket {
		BuildBuildingPacket(int32_t startTime, int32_t coolTime) {
			cmd = BUILD_BUILDING_REQ; 
			packetNo += startTime+coolTime;

		}

	};
/*
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
*/



};

#endif //__CLIENT_LOBBY_PACKET_H__
