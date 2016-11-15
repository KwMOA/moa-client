//
//  Building_6.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_6.h"
#include "GameDefines.h"
#include "GamePlayer.h"

Building_6::Building_6(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_6)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_8);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_9);
}

void Building_6::click()
{
    
}

void Building_6::update(int updateCount)
{
    Building::update(updateCount);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}
