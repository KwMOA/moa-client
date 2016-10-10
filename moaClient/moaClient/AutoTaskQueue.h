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


	Node * front;
	Node * rear;
public:

	AutoTaskQueue();
	bool QIsEmpty();

	void Enqueue(Packet* packet);
	void DelayQueue(Packet* packet);

	Packet* Dequeue();
	Packet* QPeek();
	

};

#endif //__AUTO_TASK_QUEUE_H__
