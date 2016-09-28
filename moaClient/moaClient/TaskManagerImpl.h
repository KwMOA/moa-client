#ifndef TaskManagerImpl_hpp
#define TaskManagerImpl_hpp

#include <stdio.h>

#include "BasicDefines.h"
#include "TaskManager.h"

class TaskManagerImpl : public TaskManager
{
private:

	int32_t count;
	bool isFirst;

public:
	TaskManagerImpl();
	void update(long dt);
	void receiveFromNetwork(Packet* packet);
	void receiveFromClient(Packet* packet);
	void autoInputQueue(Packet* packet);
	
};

#endif
