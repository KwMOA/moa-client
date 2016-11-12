//
//  Upgrade_23.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_23.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_23::Upgrade_23(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_23;
}


void Upgrade_23::upgradeComplete()
{
    ((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->setAroundAtkRange(((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->getAroundAtkRange() + 50);
}


void Upgrade_23::update(long dt)
{
    upgrading(40);
}