//
//  NetworkHandlerImpl.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "NetworkHandlerImpl.hpp"
#include "ClientGamePacket.h"
#include "GameManager.hpp"

void NetworkHandlerImpl::sendInput(Packet* packet)
{
    receivePacketList.push_back(packet);
}

void NetworkHandlerImpl::update(long dt)
{
    
    // not exist received packet
    if(receivePacketList.empty()) {
        
        GameManager::GetInstance()->getTaskManager()->receiveFromNetwork(new ClientGamePacket::EmptyPacket());
        
    } else { // exist received packet
        
        
    }
}