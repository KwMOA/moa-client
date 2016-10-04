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

#include "GameWorld.h"

#include "GamePlayer.hpp"

class GameWorldImpl : public GameWorld
{
private:
    GamePlayer* gamePlayers[2];
    
public:
    GameWorldImpl();
    
    void checkState();
    void actState();
    void applyInfluence();
    
    GamePlayer* getGamePlayer(int index) { return gamePlayers[index]; }
    
    
    
    void createBuilding(int userIndex, int objectType);
    void cancelCreateBuilding(int userIndex, int objectNo);
    void upgradeBuilding(int userIndex, int objectNo, int upgradeType);
    void cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType);
    void createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo);
};


#endif /* GameWorldImpl_hpp */
