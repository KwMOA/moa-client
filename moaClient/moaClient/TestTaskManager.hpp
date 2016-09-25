//
//  TestTaskManager.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef TestTaskManager_hpp
#define TestTaskManager_hpp

#include <iostream>

#include "TaskManager.h"

class TestTaskManager : public TaskManager
{
private:
    
public:
    TestTaskManager();
    void receiveFromNetwork(Packet* packet);
    void update(long dt);
};

#endif /* TestTaskManager_hpp */
