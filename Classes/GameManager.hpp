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
#include <cocos2d.h>
class TaskManager;
class GameLogic;
class GameWorld;
class GameData;
class GameScene;
USING_NS_CC;

class GameManager
{
private:
    
    GameScene* gameScene;
    TaskManager* taskManager;
    GameLogic* gameLogic;
    GameWorld* gameWorld;
    GameData* gameData;
    
    
    int tempObjectNoCreator;
    bool aiMode;
    int myIndex;
    
    ////////////////
    
public:
    GameManager(GameScene* _gameScene, bool _isAiMode);
    
    bool init();
    void run();
    
    void finishGame();
    
    /////////////////
    
    TaskManager* getTaskManager() { return taskManager; }
    GameLogic* getGameLogic() { return gameLogic; }
    GameWorld* getGameWorld() { return gameWorld; }
    GameScene* getGameScene() { return gameScene; }
    
    //////////////////
    
    bool isAiMode() { return aiMode; }

    
};

#endif /* GameManager_hpp */
