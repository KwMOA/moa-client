//
//  NetworkHandler.h
//  moa
//
//  Created by kimyongchan on 2016. 9. 23..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef NetworkHandler_h
#define NetworkHandler_h

#include "BasicPacket.h"

class NetworkHandler {
public:
    virtual void sendInput(Packet* packet) = 0;
    virtual void update(long dt) = 0;
};

#endif /* NetworkHandler_h */
