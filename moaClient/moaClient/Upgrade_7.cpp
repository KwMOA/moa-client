//
//  Upgrade_7.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_7.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_7::Upgrade_7(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_7;
}


void Upgrade_7::upgradeComplete()
{
    ((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->setHeal(((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->getHeal() + 50);
}


void Upgrade_7::update(long dt)
{
    upgrading(40);
}