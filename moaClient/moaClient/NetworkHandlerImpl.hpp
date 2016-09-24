//
//  NetworkHandlerImpl.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef NetworkHandlerImpl_hpp
#define NetworkHandlerImpl_hpp

#include <stdio.h>
#include <list>

#include "NetworkHandler.h"

class NetworkHandlerImpl : public NetworkHandler
{
private:
    std::list<Packet*> receivePacketList;
    
    int tempAutoPacketNo;
    
public:
    NetworkHandlerImpl();
    void sendInput(Packet* packet);
    void update(long dt);
};

#endif /* NetworkHandlerImpl_hpp */
