//
//  Upgrade_6.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_6.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_6::Upgrade_6(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_6;
}


void Upgrade_6::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->setSpeed(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->getSpeed() + 10);
}


void Upgrade_6::update(long dt)
{
    upgrading(40);
}