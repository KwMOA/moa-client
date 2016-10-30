//
//  GamePlayer.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GamePlayer.hpp"
#include "BaseObject.hpp"
#include "GameDefines.h"
#include "Building.hpp"
#include "Unit.hpp"
#include "StaticObject.hpp"
#include "GameWorldImpl.hpp"

GamePlayer::GamePlayer(GameWorld* _gameWorld, int _playerIndex)
{
    objectNoCreator = 1;
    
    gameWorld = _gameWorld;
    
    playerIndex = _playerIndex;
    
    // set static unit
    
    staticUnitList.push_back(new StaticUnit_1());
    staticUnitList.push_back(new StaticUnit_2());
    staticUnitList.push_back(new StaticUnit_3());
    staticUnitList.push_back(new StaticUnit_4());
    staticUnitList.push_back(new StaticUnit_5());
    staticUnitList.push_back(new StaticUnit_6());
    staticUnitList.push_back(new StaticUnit_7());
    staticUnitList.push_back(new StaticUnit_8());
    staticUnitList.push_back(new StaticUnit_9());

	gold = 0;
    
    ////////////////////
    
    gold = 0;
}

BaseObject* GamePlayer::getBuildingByObjectNo(int objectNo)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo) {
            return baseObject;
        }
    }
    
    return nullptr;
}



BaseObject* GamePlayer::getUnitByObjectNo(int objectNo)
{
    return nullptr;
}

BaseObject* GamePlayer::getBuildingByObjectType(int objectType)
{
	for (buildingItr = buildingList.begin(); buildingItr != buildingList.end(); buildingItr++)
	{
		BaseObject* baseObject = (BaseObject*)*buildingItr;

		if (baseObject->getObjectType() == objectType) {
			return baseObject;
		}
	}

	return nullptr;
}

int GamePlayer::createBuilding(int objectType)
{
    Building* building = Building::createBuilding(this, objectType);
    
    if(building == nullptr) {
        std::cout<< "invalid building type - " << objectType <<std::endl;
        
        return -1;
    }
    
    building->setObjectNo(objectNoCreator);
    
     buildingList.push_back(building);
    
    return objectNoCreator++;
}

int GamePlayer::cancelCreateBuilding(int objectNo)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_CREATING) {
            baseObject->setState(OBJECT_STATE_DESTROYING);
            
            buildingList.remove(*buildingItr);
            destroyBuildingList.push_back(baseObject);
            
            std::cout<< "destroy building start - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}

int GamePlayer::upgradeBuilding(int objectNo, int upgradeType)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_IDLE) {
            ((Building*)baseObject)->startUpgrade(upgradeType);
            
            std::cout<< "upgrade building start - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}


int GamePlayer::cancelUpgradeBuilding(int objectNo, int upgradeType)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_UPGRADING) {
            ((Building*)baseObject)->cancelUpgrade(upgradeType);
            
            std::cout<< "cancel upgrade building - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}



int GamePlayer::createUnit(int objectNo, int objectType, int objectCount, int lineNo)
{
    for(int i = 0; i < objectCount; i++) {
        
        Unit* unit = Unit::createUnit(this, objectType);
        
        if(unit == nullptr) {
            std::cout<< "invalid unit type - " << objectType <<std::endl;
            
            return -1;
        }
        
        unit->setObjectNo(objectNoCreator++);
        unit->setLineNo(lineNo);
        
        unitList[lineNo - 1].push_back(unit);
        
        std::cout<< "create unit - objectNo : " << unit->getObjectNo() << ", objectType : " << objectType <<std::endl;
    
    }
    
    return objectNoCreator;
}


std::list<Unit*> GamePlayer::getUnitListByUnitType(int unitType)
{
    std::list<Unit*> sendUnitList;
    
    for(int i = 0; i < 3; i++) {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            if((*unitItr[i])->getObjectType() == unitType)
            {
                sendUnitList.push_back(*unitItr[i]);
            }
            
        }
    }
    
    return sendUnitList;
}



StaticUnit* GamePlayer::getStaticUnitByUnitType(int unitType)
{
    for(staticUnitItr = staticUnitList.begin(); staticUnitItr != staticUnitList.end(); staticUnitItr++)
    {
        if((*staticUnitItr)->getUnitType() == unitType)
        {
            return *staticUnitItr;
        }
        
    }
    
    return nullptr;
}





void GamePlayer::update(long dt)
{
    
    // update buildings
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        baseObject->update(dt);
    }
    
    
    // update destorying building
    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; )
    {
        Building* building = (Building*)*destroyBuildingItr;
        
        building->update(dt);
        
        if(building->getState() == OBJECT_STATE_DESTROY) {
            destroyBuildingItr = destroyBuildingList.erase(destroyBuildingItr);
            
            delete building;
            
        } else {
            destroyBuildingItr++;
        }
    }
    
    
    
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); i++)
        {
            Unit* unit = *unitItr[i];
            
            unit->update(dt);
        }
    }
}

void GamePlayer::applyInfluenceUnit()
{
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); i++)
        {
            Unit* unit = *unitItr[i];
            
            unit->applyInfluence();
        }
    }
}



Unit* GamePlayer::checkEnemyInRange(int lineNo, int x, int width, int range)
{
    Unit* unit;
    if(playerIndex == 0) {
        unit = gameWorld->getGamePlayer(1)->getBestCloseUnit(lineNo, x, width, range);
    } else {
        unit = gameWorld->getGamePlayer(0)->getBestCloseUnit(lineNo, x, width, range);
    }
    
    return unit;
}

Unit* GamePlayer::getBestCloseUnit(int lineNo, int x, int width, int range)
{
    Unit* closeUnit = nullptr;
    int i = lineNo - 1;
    
    if(playerIndex == 0) {
     
        int closeX = x + width + range + 1;
        
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); i++)
        {
            Unit* unit = *unitItr[i];
            
            if(unit->getX() - unit->getWidth() < closeX && unit->getIsVisible()) { // if find close unit
                closeX = unit->getX() - unit->getWidth();
                
                closeUnit = unit;
            }
        }
        
    } else {
    
        int closeX = x - (width + range + 1);
        
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); i++)
        {
            Unit* unit = *unitItr[i];
            
            if(unit->getX() + unit->getWidth() > closeX && unit->getIsVisible()) { // if find close unit
                closeX = unit->getX() + unit->getWidth();
                
                closeUnit = unit;
            }
        }
        
    }
    
    return closeUnit;
}


