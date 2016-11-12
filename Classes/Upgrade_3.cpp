//
//  Upgrade_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_3.hpp"

#include <iostream>
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "Building_7.hpp"
#include "StaticObject.hpp"

Upgrade_3::Upgrade_3(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_3;
}


void Upgrade_3::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->getAtk() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->getAtk() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->getAtk() + 2);
}


void Upgrade_3::update(long dt)
{
    upgrading(40);
}