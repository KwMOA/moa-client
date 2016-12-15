//
//  GameWorld.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef __GAME_WORLD_H__
#define __GAME_WORLD_H__

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class GamePlayer;
class TechChecker;
class GameManager;
class BaseObject;

class GameWorld
{
private:
    GamePlayer* gamePlayers[2];
    
    GameManager* gameManager;
    Layer* gameMap;
    
public:
    GameWorld(GameManager* _gameManager);
    
    void update(int updateCount);
    
    GamePlayer* getGamePlayer(int index) { return gamePlayers[index]; }
    
    void createBuilding(int userIndex, int objectType);
    void cancelCreateBuilding(int userIndex, int objectNo);
    void upgradeBuilding(int userIndex, int objectNo, int upgradeType);
    void cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType);
    void createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo);
    void checkCollusion();
    void updateImage();
    void addChild(BaseObject* object);
    void removeChild(BaseObject* object);
    int isFinished();
    GameManager* getGameManager() { return gameManager; }
};


#endif /* __GAME_WORLD_H__ */
