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
#include <cocos2d.h>

USING_NS_CC;

class BaseObject;
class Unit;
class StaticUnit;
class GameWorld;
class CheckAvailable;

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

    int gold;
    int unitPopulation;
    
    int objectNoCreator;
    
    int playerIndex;
    GameWorld* gameWorld;
    
    CheckAvailable* checker;

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
    
    std::list<Unit*> getUnitListByUnitType(int unitType);
    
    StaticUnit* getStaticUnitByUnitType(int unitType);
    
    void update(long dt);
    void updateImage(Layer* layer);
    void applyInfluenceUnit();
    
    
    
    Unit* checkEnemyInRange(int lineNo, int x, int width, int range);
    Unit* getBestCloseUnit(int lineNo, int x, int width, int range);
    GameWorld* getGameWorld() { return gameWorld; }
    
    int getPlayerIndex() { return playerIndex; }
    
    CheckAvailable* getChecker() { return checker; }
    
    bool isFinished();
    
    void finishUnitDead();
};
#endif /* GamePlayer_hpp */
