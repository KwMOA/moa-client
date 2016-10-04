//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_11.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_11::Upgrade_11(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_11;
}


void Upgrade_11::upgradeComplete()
{
    ((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->setKnockBack(((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->getKnockBack() + 50);
}


void Upgrade_11::update(long dt)
{
    upgrading(40);
}