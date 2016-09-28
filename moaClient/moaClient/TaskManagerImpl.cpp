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
	std::cout << "리시브 네트워크\n";
	
}



void TaskManagerImpl::update(long dt)
{
	
	if (count == CHECK_COUNT) {
		

		GameManager::GetInstance()->getGameLogic()->update(dt);

		count = 0;
	}
	else {
		GameManager::GetInstance()->getGameLogic()->update(dt);

	}
	count++;
// 만약에 홀수번째 호출이면 게임 로직에 업데이트 호출
// 만약에 짝수번이면 리시브 네트워크로 부터받은 페킷이 있는지 확인하고
// 있면 처리하고 게임 로직 호출
	// gameLogicManager->update() 호출

	
}

