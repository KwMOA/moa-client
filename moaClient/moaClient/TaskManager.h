//
//  TaskManager.h
//  moa
//
//  Created by kimyongchan on 2016. 9. 23..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef TaskManager_h
#define TaskManager_h

#include "BasicPakcet.h"

class TaskManager {
public:
    virtual void receiveFromNetwork(Packet* packet) = 0;
    virtual void update(long dt) = 0;
};

#endif /* TaskManager_h */
