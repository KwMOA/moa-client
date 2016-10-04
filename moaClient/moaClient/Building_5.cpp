//
//  Building_5.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_5.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"

Building_5::Building_5(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_5)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_6);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_7);
}

void Building_5::click()
{
    
}

void Building_5::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle

    }
}