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
	std::cout << "���ú� ��Ʈ��ũ\n";
	
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
// ���࿡ Ȧ����° ȣ���̸� ���� ������ ������Ʈ ȣ��
// ���࿡ ¦�����̸� ���ú� ��Ʈ��ũ�� ���͹��� ��Ŷ�� �ִ��� Ȯ���ϰ�
// �ָ� ó���ϰ� ���� ���� ȣ��
	// gameLogicManager->update() ȣ��

	
}

