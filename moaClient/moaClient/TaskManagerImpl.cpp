#include "TaskManagerImpl.h"
#include "ClientGamePacket.h"
#include "AutoTaskPacket.h"
#include "AutoTaskQueue.h"
#include "GameManager.hpp"

#include <iostream>

TaskManagerImpl::TaskManagerImpl()
{
	isFirst = false;
	count = 1;
	AutoTaskQueue::GetInstance();
}

void TaskManagerImpl::receiveFromNetwork(Packet* packet)
{
	AutoTaskQueue::GetInstance()->Enqueue(packet);
	
}



void TaskManagerImpl::update(long dt)
{
	
	if (count == INTERUPT_NETWORK_FRAME) {
		
        //TODO. process network input
        
		count = 0;
	}
	else {

	}

    GameManager::GetInstance()->getGameLogic()->update(dt);
    
	count++;
    
}

