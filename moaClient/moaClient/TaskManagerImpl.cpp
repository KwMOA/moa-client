#include "TaskManagerImpl.h"
#include "ClientGamePacket.h"
#include "AutoTaskPacket.h"
#include "GameManager.hpp"
#include "GamePlayer.hpp"
#include "Building_1.hpp"
#include "Process.h"
#include "IProcessBuilding_1.hpp"

#include <iostream>

TaskManagerImpl::TaskManagerImpl()
{
	isFirst = false;
	count = 1;
	autoTaskQueue = AutoTaskQueue();
	resPacketHandler = ResPacketHandler();
	map[1] = new IProcessBuilding_1();
}

void TaskManagerImpl::receiveFromNetwork(Packet* packet)
{
	autoTaskQueue.Enqueue(packet);
	
}



void TaskManagerImpl::update(long dt)
{
		int who;
		
		if (count == INTERUPT_NETWORK_FRAME) {
			resPacketHandler.setEmpty((ClientGamePacket::EmptyPacket*)autoTaskQueue.QPeek());
			
			int thisNo = resPacketHandler.getPacketNo();
			int nextNo = resPacketHandler.getPacketNo();

			while (!autoTaskQueue.QIsEmpty() || nextNo != thisNo) {
				resPacketHandler.setEmpty((ClientGamePacket::EmptyPacket*)autoTaskQueue.Dequeue());
				nextNo = resPacketHandler.getPacketNo();

				switch (resPacketHandler.getEmpty()->cmd) {

				case ClientGamePacket::CREATE_BUILDING_RES:
					resPacketHandler.resCreateBuilding();
					break;
				case ClientGamePacket::CANCEL_BUILDING_RES:
					resPacketHandler.resCancelBuilding();
					break;
				default:
					break;
				}
				count = 0;
			}
		}
		else {}

		GameManager::GetInstance()->getGameLogic()->update(dt);

		count++;
	
}

