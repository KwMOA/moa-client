//
//  GameManager.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stddef.h>
#include "BasicDefines.h"

#include "NetworkHandlerImpl.hpp"
#include "TaskManager.h"

class GameManager
{
private:
    GameManager();
    GameManager(const GameManager& other);
    
    static GameManager* instance;
    
    ////////////////
    
    NetworkHandler* networkHandler;
    TaskManager* taskManager;

    ////////////////
    
public:
    static GameManager* GetInstance()
    {
        if(instance == NULL) instance = new GameManager();
        return instance;
    }
    
    void run();
    
    
    
    /////////////////
    
    
    NetworkHandler* getNetworkHandler() { return networkHandler; }
    TaskManager* getTaskManager() { return taskManager; }
    
    //////////////////
};

#endif /* GameManager_hpp */
