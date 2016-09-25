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
//    ((ClientGamePacket::EmptyPacket*)packet)->isEnemy = 0;
    receivePacketList.push_back(packet);
}

void NetworkHandlerImpl::update(long dt)
{
    
    // not exist received packet
    if(receivePacketList.empty()) {
        
        ClientGamePacket::EmptyPacket* p = new ClientGamePacket::EmptyPacket();
        
        p->packetNo = tempAutoPacketNo;
        p->isEnemy = 0;
        
        GameManager::GetInstance()->getTaskManager()->receiveFromNetwork(p);
        
    } else { // exist received packet
        
        for(itr = receivePacketList.begin(); itr != receivePacketList.end() ; itr++)
        {
            ClientGamePacket::EmptyPacket* p = (ClientGamePacket::EmptyPacket*)*itr;
            
            p->packetNo = tempAutoPacketNo;
            
            GameManager::GetInstance()->getTaskManager()->receiveFromNetwork(p);
        }
        
        receivePacketList.clear();
    }
    
    tempAutoPacketNo++;
}