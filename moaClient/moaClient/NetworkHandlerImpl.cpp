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

NetworkHandlerImpl::NetworkHandlerImpl()
{
    tempAutoPacketNo = 1;
}
void NetworkHandlerImpl::sendInput(Packet* packet)
{
    receivePacketList.push_back(packet);
}

void NetworkHandlerImpl::update(long dt)
{
    
    // not exist received packet
    if(receivePacketList.empty()) {
        
        ClientGamePacket::EmptyPacket* p = new ClientGamePacket::EmptyPacket();
        
        p->packetNo = tempAutoPacketNo;
        tempAutoPacketNo++;
        
        p->isEnemy = 0;
        
        GameManager::GetInstance()->getTaskManager()->receiveFromNetwork(p);
        
    } else { // exist received packet
        
        
    }
}