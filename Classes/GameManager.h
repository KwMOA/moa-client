//
//  GameManager.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameManager_h
#define GameManager_h

#include <stddef.h>
#include <cocos2d.h>
class TaskManager;
class GameWorld;
class GameData;
class GameScene;

USING_NS_CC;

class GameManager
{
private:
    
    GameScene* gameScene;
    TaskManager* taskManager;
    GameWorld* gameWorld;
    GameData* gameData;
    
    
    int tempObjectNoCreator;
    bool aiMode;
    int myIndex;
    
    ////////////////
    
public:
    GameManager(GameScene* _gameScene, bool _isAiMode);
    
    bool init();
    
    void finishGame(int winIndex);
    
    /////////////////
    
    TaskManager* getTaskManager() { return taskManager; }
    GameWorld* getGameWorld() { return gameWorld; }
    GameScene* getGameScene() { return gameScene; }
    
    //////////////////
    
    bool isAiMode() { return aiMode; }

    
};

#endif /* GameManager_h */
