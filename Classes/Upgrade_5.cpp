//
//  Upgrade_5.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_5.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_5::Upgrade_5(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_5;
}


void Upgrade_5::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->setAtkSpeed(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->getAtkSpeed() - 4);
}


void Upgrade_5::update(long dt)
{
    upgrading(40);
}