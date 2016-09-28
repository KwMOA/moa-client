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
#include "GameDefines.h"

#include "NetworkHandler.h"
#include "TaskManager.h"
#include "GameLogic.h"
#include "GameWorld.h"

class GameManager
{
private:
    GameManager();
    GameManager(const GameManager& other);
    
    static GameManager* instance;
    
    
    
    ////////////////
    
    ObjectInfo objectInfos[1];
    
    NetworkHandler* networkHandler;
    TaskManager* taskManager;
    GameLogic* gameLogic;
    GameWorld* gameWorld;
    
    
    int tempObjectNoCreator;
    
    ////////////////
    
public:
    static GameManager* GetInstance()
    {
        if(instance == NULL) instance = new GameManager();
        return instance;
    }
    
    bool init();
    void run();
    
    
    
    /////////////////
    
    
    NetworkHandler* getNetworkHandler() { return networkHandler; }
    TaskManager* getTaskManager() { return taskManager; }

    GameLogic* getGameLogic() { return gameLogic; }
    GameWorld* getGameWorld() { return gameWorld; }
    
    ObjectInfo getObjectInfoByObjectType(int objectType) const { return objectInfos[objectType]; }
    
    //////////////////
};

#endif /* GameManager_hpp */
