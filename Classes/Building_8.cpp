//
//  Building_8.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_8.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "Upgrade_6.hpp"
#include "Upgrade_7.hpp"
#include "Upgrade_8.hpp"


Building_8::Building_8(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_8)
{
    upgradeList->push_back(new Upgrade_6(this));
    upgradeList->push_back(new Upgrade_7(this));
    upgradeList->push_back(new Upgrade_8(this));
}

void Building_8::click()
{
    
}

void Building_8::update(long dt)
{
    Building::update(dt);
}