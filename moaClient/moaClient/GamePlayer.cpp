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

int GamePlayer::setBuilding(BaseObject* building)
{
    building->setObjectNo(objectNoCreator);
    building->setGamePlayer(this);
    
    buildingList.push_back(building);
    
    return objectNoCreator++;
}

int GamePlayer::destoryBuilding(int objectNo)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo) {
            baseObject->setState(OBJECT_STATE_DESTROYING);
            
            buildingList.remove(*buildingItr);
            destroyBuildingList.push_back(baseObject);
            
            std::cout<< "destroy building start - " << baseObject->getObjectNo() <<std::endl;
        }
    }
    
    return -1;
}


int GamePlayer::setUnit(BaseObject* unit)
{
    return 0;
}


std::list<Unit*> GamePlayer::getUnitListByUnitType(int unitType)
{
    std::list<Unit*> unitList;
    
    for(unitItr1 = unitList1.begin(); unitItr1 != unitList1.end(); unitItr1++)
    {
        if((*unitItr1)->getObjectType() == unitType)
        {
            unitList.push_back(*unitItr1);
        }
        
    }
    
    for(unitItr2 = unitList2.begin(); unitItr2 != unitList2.end(); unitItr2++)
    {
        if((*unitItr2)->getObjectType() == unitType)
        {
            unitList.push_back(*unitItr2);
        }
        
    }
    
    for(unitItr3 = unitList3.begin(); unitItr3 != unitList3.end(); unitItr3++)
    {
        if((*unitItr3)->getObjectType() == unitType)
        {
            unitList.push_back(*unitItr3);
        }
        
    }
    
    return unitList;
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
    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; destroyBuildingItr++)
    {
        Building* building = (Building*)*destroyBuildingItr;
        
        building->update(dt);
        
        if(building->getState() == OBJECT_STATE_DESTROY) {
            destroyBuildingList.remove(*buildingItr);
            
            delete building;
        }
    }
    
    
}