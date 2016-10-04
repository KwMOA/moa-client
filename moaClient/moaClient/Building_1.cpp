//
//  Building_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_1.hpp"
#include "GameDefines.h"
#include "Upgrade_1.hpp"


Building_1::Building_1(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_1)
{
    upgradeList->push_back(new Upgrade_1(this));
}

void Building_1::click()
{
    
}

void Building_1::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}