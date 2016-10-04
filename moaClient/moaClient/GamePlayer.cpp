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
#include "StaticObject.h"

GamePlayer::GamePlayer()
{
    objectNoCreator = 1;
    
    
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
    
    ////////////////////
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
    
    
}