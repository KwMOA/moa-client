//
//  Upgrade_24.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_24.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_24::Upgrade_24(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_24;
}


void Upgrade_24::upgradeComplete()
{
    ((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->setAroundAtk(((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->getAroundAtk() + 25);
}


void Upgrade_24::update(long dt)
{
    upgrading(40);
}