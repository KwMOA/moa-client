//
//  GameWorldImpl.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameWorldImpl_hpp
#define GameWorldImpl_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameWorld.h"

USING_NS_CC;

class GamePlayer;
class CheckAvailable;
class GameManager;

class GameWorldImpl : public GameWorld
{
private:
    GamePlayer* gamePlayers[2];
    
    GameManager* gameManager;
    Layer* gameMap;
    
public:
    GameWorldImpl(GameManager* _gameManager);
    
    void update(long dt);
    
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
    bool isFinished();
    GameManager* getGameManager() { return gameManager; }
};


#endif /* GameWorldImpl_hpp */
