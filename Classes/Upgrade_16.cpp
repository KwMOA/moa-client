//
//  Upgrade_16.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_16.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.hpp"
Upgrade_16::Upgrade_16(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_16;
}


void Upgrade_16::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->getDef() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->getDef() + 2);
}


void Upgrade_16::update(long dt)
{
    upgrading(40);
}