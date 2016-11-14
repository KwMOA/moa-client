//
//  Building_10.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_10.h"
#include "GameDefines.h"
#include "GamePlayer.h"
#include "Upgrade_15.h"
#include "Upgrade_16.h"
#include "Upgrade_17.h"
#include "Upgrade_18.h"

Building_10::Building_10(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_10)
{
    upgradeList->push_back(new Upgrade_15(this));
    upgradeList->push_back(new Upgrade_16(this));
    upgradeList->push_back(new Upgrade_17(this));
    upgradeList->push_back(new Upgrade_18(this));
}

void Building_10::click()
{
    
}

void Building_10::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}
