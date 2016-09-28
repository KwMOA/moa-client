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

GamePlayer::GamePlayer()
{
    objectNoCreator = 1;
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
            baseObject->setState(OBJECT_STATE_DESTROY);
            
            buildingList.remove(*buildingItr);
            destroyBuildingList.push_back(baseObject);
            
            std::cout<< "destroy building start - " << baseObject->getObjectNo() <<std::endl;
        }
    }
    
    return -1;
}

int GamePlayer::removeBuilding(int objectNo)
{
    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; destroyBuildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*destroyBuildingItr;
        
        if(baseObject->getObjectNo() == objectNo) {
            destroyBuildingList.remove(*buildingItr);
            
            delete baseObject;
        }
    }
    
    return -1;
}



int GamePlayer::setUnit(BaseObject* unit)
{
    return 0;
}

void GamePlayer::update(long dt)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        baseObject->update(dt);
    }

    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; destroyBuildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*destroyBuildingItr;
        
        baseObject->update(dt);
    }
}