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
	int who;
	ClientGamePacket::EmptyPacket* packet;
		ClientGamePacket::CancelBuildingResPacket* canclePacket;
		ClientGamePacket::CreateBuildingResPacket* buildPacket;

		if (count == INTERUPT_NETWORK_FRAME) {
			packet = (ClientGamePacket::EmptyPacket*)autoTaskQueue.QPeek();

			int thisNo = packet->packetNo;
			int nextNo = packet->packetNo;
			while (!autoTaskQueue.QIsEmpty() || nextNo != thisNo) {
				packet = (ClientGamePacket::EmptyPacket*)autoTaskQueue.Dequeue();
				who = packet->isEnemy;
				nextNo = packet->packetNo;

				switch (packet->cmd) {

				case ClientGamePacket::CREATE_BUILDING_RES:
					buildPacket = (ClientGamePacket::CreateBuildingResPacket*)packet;
					switch (buildPacket->objectType) {
					case OBJECT_TYPE_BUILDING_1:
						Building_1* building = new Building_1();
						GameManager::GetInstance()->getGameWorld()->getGamePlayer(who)->setBuilding(building);

						break;
					}
					break;
				case ClientGamePacket::CANCEL_BUILDING_RES:
					canclePacket = (ClientGamePacket::CancelBuildingResPacket*)packet;
					GameManager::GetInstance()->getGameWorld()->getGamePlayer(who)->getBuildingByObjectNo(canclePacket->objectNo);
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

