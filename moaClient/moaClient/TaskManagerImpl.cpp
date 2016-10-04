#include "TaskManagerImpl.h"
#include "ClientGamePacket.h"
#include "AutoTaskPacket.h"
#include "GameManager.hpp"
#include "GameWorld.h"
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
                {
                    ClientGamePacket::CreateBuildingResPacket* createBuildingPacket = (ClientGamePacket::CreateBuildingResPacket*)packet;
                    GameManager::GetInstance()->getGameWorld()->createBuilding(who, createBuildingPacket->objectType);
                    
                    break;
                }
                case ClientGamePacket::CANCEL_CREATE_BUILDING_RES:
                {
                    ClientGamePacket::CancelCreateBuildingResPacket* cancelCreateBuildingPacket = (ClientGamePacket::CancelCreateBuildingResPacket*)packet;
                    GameManager::GetInstance()->getGameWorld()->cancelCreateBuilding(who, cancelCreateBuildingPacket->objectNo);
                    
                    break;
                }
                case ClientGamePacket::UPGRADE_BUILDING_RES:
                {
                    ClientGamePacket::UpgradeBuildingResPacket* upgradeBuildingPacket = (ClientGamePacket::UpgradeBuildingResPacket*)packet;
                    GameManager::GetInstance()->getGameWorld()->upgradeBuilding(who, upgradeBuildingPacket->objectNo, upgradeBuildingPacket->upgradeType);
                    
                    break;
                }
                case ClientGamePacket::CANCEL_UPGRADE_BUILDING_RES:
                {
                    ClientGamePacket::CancelUpgradeBuildingResPacket* cancelUpgradeBuildingPacket = (ClientGamePacket::CancelUpgradeBuildingResPacket*)packet;
                    GameManager::GetInstance()->getGameWorld()->cancelUpgradeBuilding(who, cancelUpgradeBuildingPacket->objectNo, cancelUpgradeBuildingPacket->upgradeType);
                    
                    break;
                }
                case ClientGamePacket::CREATE_UNIT_RES:
                {
                    ClientGamePacket::CreateUnitResPacket* createUnitPacket = (ClientGamePacket::CreateUnitResPacket*)packet;
                    GameManager::GetInstance()->getGameWorld()->createUnit(who, createUnitPacket->objectNo, createUnitPacket->objectType, createUnitPacket->objectCount, createUnitPacket->lineNo);
                    
                    break;
                }
                default:
                {                    
                    break;
                }
            }
            
            count = 0;
        }
    }
    else { // not process network
    
    }

    GameManager::GetInstance()->getGameLogic()->update(dt);

    count++;

}

