#include "TaskManagerImpl.h"
#include "ClientGamePacket.h"
#include "AutoTaskPacket.h"
#include "GameManager.hpp"
#include "GamePlayer.hpp"
#include "Building_1.hpp"

#include <iostream>

TaskManagerImpl::TaskManagerImpl()
{
	isFirst = false;
	count = 1;
	autoTaskQueue = AutoTaskQueue();
}

void TaskManagerImpl::receiveFromNetwork(Packet* packet)
{
	autoTaskQueue.Enqueue(packet);
	
}



void TaskManagerImpl::update(long dt)
{
	ClientGamePacket::CancelBuildingResPacket* canclePacket;
		ClientGamePacket::CreateBuildingResPacket* buildPacket;
		if (count == INTERUPT_NETWORK_FRAME) {
		switch (autoTaskQueue.Dequeue()->cmd) {
		case ClientGamePacket::CREATE_BUILDING_RES:
			buildPacket = (ClientGamePacket::CreateBuildingResPacket*)autoTaskQueue.Dequeue();
			switch (buildPacket->objectType) {
			case 1:
				Building_1* building = new Building_1();
				GameManager::GetInstance()->getGameWorld()->getGamePlayer(0)->setBuilding(building);

				break;
			}
			break;
		case ClientGamePacket::CANCEL_BUILDING_RES:
			 canclePacket = (ClientGamePacket::CancelBuildingResPacket*)autoTaskQueue.Dequeue();			
			GameManager::GetInstance()->getGameWorld()->getGamePlayer(0)->getBuildingByObjectNo(canclePacket->objectNo);
			break;
		default:
			break;
		} 

	


		count = 0;
	}
	else {

	}

    GameManager::GetInstance()->getGameLogic()->update(dt);
    
	count++;
    
}

