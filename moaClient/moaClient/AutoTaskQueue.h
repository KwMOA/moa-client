#ifndef __AUTO_TASK_QUEUE_H__
#define __AUTO_TASK_QUEUE_H__

#include "BasicPacket.h"


typedef struct _node
{
	Packet* packet;
	struct _node * next;
	_node() { packet = NULL; next = NULL; }
} Node;

class AutoTaskQueue{

private:

	AutoTaskQueue();
	static AutoTaskQueue* instance;


	Node * front;
	Node * rear;
public:

	static AutoTaskQueue* GetInstance()
	{
		if (instance == NULL) instance = new AutoTaskQueue();
		return instance;
	}

	
	bool QIsEmpty();

	void Enqueue(Packet* packet);
	Packet* Dequeue();
	Packet* QPeek();

};

#endif //__AUTO_TASK_QUEUE_H__
