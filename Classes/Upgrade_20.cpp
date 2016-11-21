//
//  Upgrade_20.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_20.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_20::Upgrade_20(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_20)
{
}


void Upgrade_20::upgradeComplete()
{
    ((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->setShield(((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->getShield() + 100);
}


void Upgrade_20::update(int updateCount)
{
    upgrading(40);
}
