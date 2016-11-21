//
//  GamePlayer.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GamePlayer_h
#define GamePlayer_h

#include <stdio.h>
#include <list>
#include <map>
#include <cocos2d.h>
#include "GameDefines.h"

USING_NS_CC;

class BaseObject;
class Unit;
class StaticUnit;
class StaticBuilding;
class StaticUpgrade;
class GameWorld;
class TechChecker;

class GamePlayer
{
protected:
    std::list<BaseObject*> buildingList;
    std::list<BaseObject*>::iterator buildingItr;
    
    std::list<BaseObject*> destroyBuildingList;
    std::list<BaseObject*>::iterator destroyBuildingItr;
    
    std::list<Unit*> unitList[3];
    std::list<Unit*>::iterator unitItr[3];
    
    std::list<Unit*> destroyUnitList;
    std::list<Unit*>::iterator destoryUnitItr;
    
    
    std::list<StaticUnit*> staticUnitList;
    std::list<StaticUnit*>::iterator staticUnitItr;
    
    std::list<StaticBuilding*> staticBuildingList;
    std::list<StaticBuilding*>::iterator staticBuildingItr;
    
    std::list<StaticUpgrade*> staticUpgradeList;
    std::list<StaticUpgrade*>::iterator staticUpgradeItr;
    
    
    

    int gold;
    int population;
    
    int objectNoCreator;
    
    int playerIndex;
    GameWorld* gameWorld;
    
    TechChecker* checker;

public:
    GamePlayer(GameWorld* _gameWorld, int _playerIndex);
    
    BaseObject* getBuildingByObjectNo(int objectNo);
    BaseObject* getUnitByObjectNo(int objectNo);

	BaseObject* getBuildingByObjectType(int objectType);
    
    int createBuilding(int objectType);
    int cancelCreateBuilding(int objectNo);
    int upgradeBuilding(int objectNo, int upgradeType);
    int cancelUpgradeBuilding(int objectNo, int upgradeType);
    
    
    int createUnit(int objectNo, int objectType, int objectCount, int lineNo);
    
    void addGold(int plus) { gold += plus; }
    
    int getGold() { return gold; }
    void setGold(int _gold);
    int getPopulation() { return population; }
    void setPopulation(int _population);
    
    std::list<Unit*> getUnitListByUnitType(int unitType);
    
    StaticUnit* getStaticUnitByUnitType(int unitType);
    StaticBuilding* getStaticBuildingByBuildingType(int buildingType);
    StaticUpgrade* getStaticUpgradeByUpgradeType(int upgradeType);
    
    void update(int updateCount);
    void updateImage(Layer* layer);
    void applyInfluenceUnit();
    
    
    
//    Unit* checkEnemyInRange(int lineNo, int x, int width, int range);
    Unit* getBestCloseUnit(Unit* otherUnit);
    GameWorld* getGameWorld() { return gameWorld; }
    
    int getPlayerIndex() { return playerIndex; }
    
    TechChecker* getChecker() { return checker; }
    
    bool isFinished();
    
    void finishUnitDead();
    
    
    int sameXPlayerIndex(int newX) {if(playerIndex == 0) return newX; else return MAP_WIDTH - newX;}
    
    
    
    
    
    
    
//    creatingBuildingNotify(this)
//    sendCreateCompleteNotify(this);
//    cancelCreatingBuildingNotify((Building*)baseObject);
//startUpgardeNotify(currentUpgrade);
//    cancelUpgardeNotify(currentUpgrade);
//    
    
};
#endif /* GamePlayer_h */
