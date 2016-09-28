//
//  GamePlayer.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GamePlayer.hpp"
#include "BaseObject.hpp"

GamePlayer::GamePlayer()
{
    objectNoCreator = 1;
}

BaseObject* GamePlayer::getBuildingByObjectNo(int objectNo)
{
    for(buildingitr = buildingList.begin(); buildingitr != buildingList.end() ; buildingitr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingitr;
        
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


int GamePlayer::setUnit(BaseObject* unit)
{
    return 0;
}

void GamePlayer::update(long dt)
{
    for(buildingitr = buildingList.begin(); buildingitr != buildingList.end() ; buildingitr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingitr;
        
        baseObject->update(dt);
    }
}