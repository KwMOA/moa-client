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
    std::list<BaseObject*>::iterator buildingitr;
    
    std::list<BaseObject*> unitList;
    std::list<BaseObject*>::iterator unititr;
    
    int gold;
    int unitPopulation;
    
    int objectNoCreator;
    
public:
    GamePlayer();
    
    BaseObject* getBuildingByObjectNo(int objectNo);
    BaseObject* getUnitByObjectNo(int objectNo);
    
    int setBuilding(BaseObject* building);
    int setUnit(BaseObject* unit);
    
    void addGold(int plus) { gold += plus; }
    
    void update(long dt);
    
    
};
#endif /* GamePlayer_hpp */
