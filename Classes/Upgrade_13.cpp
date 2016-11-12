//
//  Upgrade_13.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_13.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_13::Upgrade_13(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_13;
}


void Upgrade_13::upgradeComplete()
{
    ((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->setAtk(((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->getAtk() + 20); // set atk is skill atk
}


void Upgrade_13::update(long dt)
{
    upgrading(40);
}