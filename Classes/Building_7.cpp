//
//  Building_7.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_7.h"
#include "GameDefines.h"
#include "GamePlayer.h"
#include "Upgrade_3.h"
#include "Upgrade_4.h"
#include "Upgrade_5.h"

Building_7::Building_7(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_7)
{
    upgradeList->push_back(new Upgrade_3(this));
    upgradeList->push_back(new Upgrade_4(this));
    upgradeList->push_back(new Upgrade_5(this));
}

void Building_7::click()
{
    
}

void Building_7::update(long dt)
{
    Building::update(dt);
    
}
