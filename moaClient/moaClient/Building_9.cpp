//
//  Building_9.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_9.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "Upgrade_9.hpp"
#include "Upgrade_10.hpp"
#include "Upgrade_11.hpp"
#include "Upgrade_12.hpp"
#include "Upgrade_13.hpp"
#include "Upgrade_14.hpp"

Building_9::Building_9(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_9)
{
    upgradeList->push_back(new Upgrade_9(this));
    upgradeList->push_back(new Upgrade_10(this));
    upgradeList->push_back(new Upgrade_11(this));
    upgradeList->push_back(new Upgrade_12(this));
    upgradeList->push_back(new Upgrade_13(this));
    upgradeList->push_back(new Upgrade_14(this));
}

void Building_9::click()
{
    
}

void Building_9::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}