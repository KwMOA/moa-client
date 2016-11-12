//
//  GameWorldImpl.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef __GAME_WORLD_H__
#define __GAME_WORLD_H__

#include <stdio.h>

class GamePlayer;
class GameLogic;
class TaskManager;
class BaseObject;

class GameWorld
{
public:
    
    virtual void createBuilding(int userIndex, int objectType) = 0;
    virtual void cancelCreateBuilding(int userIndex, int objectNo) = 0;
    virtual void upgradeBuilding(int userIndex, int objectNo, int upgradeType) = 0;
    virtual void cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType) = 0;
    virtual void createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo) = 0;
    virtual void checkCollusion() = 0;
    virtual void updateImage() = 0;
    virtual GamePlayer* getGamePlayer(int index) = 0;
    virtual void addChild(BaseObject* object) = 0;
    virtual bool isFinished() = 0;
};


#endif /* __GAME_WORLD_H__ */
