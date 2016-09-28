
#include <iostream>

#include "AutoTaskQueue.h"

AutoTaskQueue::AutoTaskQueue() {
	front = NULL;
	rear = NULL;
}


void AutoTaskQueue::Enqueue(Packet* packet) {
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->packet = packet;
	if (this->front == NULL) {
		this->front = newNode;
		this->rear = newNode;
	}
	else
	{
		this->rear->next = newNode;
		this->rear = newNode;
	}
}

bool AutoTaskQueue::QIsEmpty() {
	if (front->packet == NULL) {
		return true;
	}else
	return false;
}

Packet* AutoTaskQueue::Dequeue() {
	Node * delNode;
	Packet* retPacket;

	if (this->QIsEmpty()) {
		std::cout << "Error1\n";
		return NULL;
	}
	else
	{
		delNode = this->front;
		retPacket = delNode->packet;
		this->front = delNode->next;

		delete(delNode);
		return retPacket;
	}

}

Packet* AutoTaskQueue::QPeek() {
	if (this->QIsEmpty()) {
		std::cout << "Error2\n";
		return NULL;
	}
	
	return this->front->packet;
}
