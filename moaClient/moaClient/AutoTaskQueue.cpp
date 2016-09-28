
#include <iostream>

#include "AutoTaskQueue.h"

AutoTaskQueue* AutoTaskQueue::instance = nullptr;

AutoTaskQueue::AutoTaskQueue() {
	front = NULL;
	rear = NULL;
}

bool AutoTaskQueue::QIsEmpty() {
	if (instance->front == NULL)
		return true;
	else
		return false;
}

void AutoTaskQueue::Enqueue(Packet* packet) {
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->packet = packet;
	if (instance->front == NULL) {
		instance->front = newNode;
		instance->rear = newNode;
	}
	else
	{
		instance->rear->next = newNode;
		instance->rear = newNode;
	}
}

Packet* AutoTaskQueue::Dequeue() {
	Node * delNode;
	Packet* retPacket;

	if (instance->QIsEmpty()) {
		std::cout << "Error1\n";
		return NULL;
	}
	else
	{
		delNode = instance->front;
		retPacket = delNode->packet;
		instance->front = delNode->next;

		delete(delNode);
		return retPacket;
	}

}

Packet* AutoTaskQueue::QPeek() {
	if (instance->QIsEmpty()) {
		std::cout << "Error2\n";
		return NULL;
	}
	
	return instance->front->packet;
}
