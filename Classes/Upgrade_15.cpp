//
//  Upgrade_15.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_15.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_15::Upgrade_15(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_15)
{
}


void Upgrade_15::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->getAtk() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->getAtk() + 2);
}


void Upgrade_15::update(int updateCount)
{
    upgrading(40);
}
