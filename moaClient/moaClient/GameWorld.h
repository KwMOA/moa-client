//
//  GameWorld.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameWorld_h
#define GameWorld_h

class GamePlayer;

class GameWorld {
public:
    virtual void update(long dt) = 0;
    
    virtual GamePlayer* getGamePlayer(int index) = 0;
    
    
    virtual void createBuilding(int userIndex, int objectType) = 0;
    virtual void cancelCreateBuilding(int userIndex, int objectNo) = 0;
    virtual void upgradeBuilding(int userIndex, int objectNo, int upgradeType) = 0;
    virtual void cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType) = 0;
    virtual void createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo) = 0;
    
};


#endif /* GameWorld_h */
