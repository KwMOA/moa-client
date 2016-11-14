//
//  Building_11.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_11.h"
#include "GameDefines.h"
#include "GamePlayer.h"
#include "Upgrade_19.h"
#include "Upgrade_20.h"
#include "Upgrade_21.h"

Building_11::Building_11(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_11)
{
    upgradeList->push_back(new Upgrade_19(this));
    upgradeList->push_back(new Upgrade_20(this));
    upgradeList->push_back(new Upgrade_21(this));

}

void Building_11::click()
{
    
}

void Building_11::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}
