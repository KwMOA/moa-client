//
//  GamePlayer.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GamePlayer_hpp
#define GamePlayer_hpp

#include <stdio.h>
#include <list>

class BaseObject;

class GamePlayer
{
private:
    std::list<BaseObject*> buildingList;
    std::list<BaseObject*>::iterator buildingItr;
    
    std::list<BaseObject*> destroyBuildingList;
    std::list<BaseObject*>::iterator destroyBuildingItr;
    
    std::list<BaseObject*> unitList;
    std::list<BaseObject*>::iterator unitItr;
    
    std::list<BaseObject*> destroyUnitList;
    std::list<BaseObject*>::iterator destoryUnitItr;
    
    int gold;
    int unitPopulation;
    
    int objectNoCreator;
    
    int removeBuilding(int objectNo);
    
public:
    GamePlayer();
    
    BaseObject* getBuildingByObjectNo(int objectNo);
    BaseObject* getUnitByObjectNo(int objectNo);
    
    int setBuilding(BaseObject* building);
    int setUnit(BaseObject* unit);
    int destoryBuilding(int objectNo);
    
    void addGold(int plus) { gold += plus; }
    
    int getGold() { return gold; }
    
    void update(long dt);
    
    
};
#endif /* GamePlayer_hpp */
