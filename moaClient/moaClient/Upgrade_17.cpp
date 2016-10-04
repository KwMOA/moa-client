//
//  Upgrade_17.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_17.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_17::Upgrade_17(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_17;
}


void Upgrade_17::upgradeComplete()
{
    ((StaticUnit_6*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6))->setGraveCount(((StaticUnit_6*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6))->getGraveCount() + 1);
}


void Upgrade_17::update(long dt)
{
    upgrading(40);
}