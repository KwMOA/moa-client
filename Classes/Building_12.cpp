//
//  Building_12.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_12.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "Upgrade_22.hpp"
#include "Upgrade_23.hpp"
#include "Upgrade_24.hpp"

Building_12::Building_12(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_12)
{
    upgradeList->push_back(new Upgrade_22(this));
    upgradeList->push_back(new Upgrade_23(this));
    upgradeList->push_back(new Upgrade_24(this));
}

void Building_12::click()
{
    
}

void Building_12::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}
