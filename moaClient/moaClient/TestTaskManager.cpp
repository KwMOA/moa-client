//
//  TestTaskManager.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "TestTaskManager.hpp"


#include "ClientGamePacket.h"
#include "GameManager.hpp"

TestTaskManager::TestTaskManager()
{

}


void TestTaskManager::receiveFromNetwork(Packet* packet)
{
    std::cout<<"packet cmd : " << packet->cmd << ", packet number : " << ((ClientGamePacket::EmptyPacket*)packet)->packetNo
    << std::endl;
    
}

void TestTaskManager::update(long dt)
{

}