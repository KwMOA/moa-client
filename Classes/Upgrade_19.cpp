//
//  Upgrade_19.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_19.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_19::Upgrade_19(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_19;
}


void Upgrade_19::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8)->getDef() + 2);
}


void Upgrade_19::update(long dt)
{
    upgrading(40);
}