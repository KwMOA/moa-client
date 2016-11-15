//
//  Building_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_3.h"
#include "GameDefines.h"
#include "GamePlayer.h"

//test
#include "GameManager.h"
#include "ClientGamePacket.h"
#include "ClientInput.h"
#include "GameWorld.h"
#include "TaskManager.h"
//


Building_3::Building_3(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_3)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_1);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_2);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_3);
    
    objectLayer->setPositionY(DISPLAY_HEIGHT - 180);
}

void Building_3::click()
{
    
}

void Building_3::update(int updateCount)
{
    Building::update(updateCount);
}
