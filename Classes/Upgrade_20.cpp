//
//  Upgrade_20.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_20.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_20::Upgrade_20(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_20;
}


void Upgrade_20::upgradeComplete()
{
    ((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->setShield(((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->getShield() + 100);
}


void Upgrade_20::update(long dt)
{
    upgrading(40);
}