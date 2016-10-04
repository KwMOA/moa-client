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
    
    std::list<Unit*> unitList[3];
    std::list<Unit*>::iterator unitItr[3];
    
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
    
    int createBuilding(int objectType);
    int cancelCreateBuilding(int objectNo);
    int upgradeBuilding(int objectNo, int upgradeType);
    int cancelUpgradeBuilding(int objectNo, int upgradeType);
    
    
    int createUnit(int objectNo, int objectType, int objectCount, int lineNo);
    
    void addGold(int plus) { gold += plus; }
    
    int getGold() { return gold; }
    
    std::list<Unit*> getUnitListByUnitType(int unitType);
    
    StaticUnit* getStaticUnitByUnitType(int unitType);
    
    void update(long dt);
    
    
};
#endif /* GamePlayer_hpp */
