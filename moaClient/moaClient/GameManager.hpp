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
#include "GameData.h"

class GameManager
{
private:
    GameManager();
    GameManager(const GameManager& other);
    
    static GameManager* instance;
    
    
    
    ////////////////
    
    
    NetworkHandler* networkHandler;
    TaskManager* taskManager;
    GameLogic* gameLogic;
    GameWorld* gameWorld;
    GameData* gameData;
    
    
    int tempObjectNoCreator;
    int myIndex;
    
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
    
    //////////////////
    

    
};

#endif /* GameManager_hpp */
