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
#include <map>

class BaseObject;
class Unit;
class StaticUnit;

class GamePlayer
{
private:
    std::list<BaseObject*> buildingList;
    std::list<BaseObject*>::iterator buildingItr;
    
    std::list<BaseObject*> destroyBuildingList;
    std::list<BaseObject*>::iterator destroyBuildingItr;
    
    std::list<Unit*> unitList1;
    std::list<Unit*>::iterator unitItr1;
    
    std::list<Unit*> unitList2;
    std::list<Unit*>::iterator unitItr2;
    
    std::list<Unit*> unitList3;
    std::list<Unit*>::iterator unitItr3;
    
    
    std::list<Unit*> destroyUnitList;
    std::list<Unit*>::iterator destoryUnitItr;
    
    int gold;
    int unitPopulation;
    
    int objectNoCreator;
    
    std::list<StaticUnit*> staticUnitList;
    std::list<StaticUnit*>::iterator staticUnitItr;

    
public:
    GamePlayer();
    
    BaseObject* getBuildingByObjectNo(int objectNo);
    BaseObject* getUnitByObjectNo(int objectNo);
    
    int setBuilding(BaseObject* building);
    int setUnit(BaseObject* unit);
    int destoryBuilding(int objectNo);
    
    void addGold(int plus) { gold += plus; }
    
    int getGold() { return gold; }
    
    std::list<Unit*> getUnitListByUnitType(int unitType);
    
    StaticUnit* getStaticUnitByUnitType(int unitType);
    
    void update(long dt);
    
    
};
#endif /* GamePlayer_hpp */
