//
//  Upgrade_23.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_23.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_23::Upgrade_23(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_23;
}


void Upgrade_23::upgradeComplete()
{
    ((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->setAroundAtkRange(((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->getAroundAtkRange() + 50);
}


void Upgrade_23::update(int updateCount)
{
    upgrading(40);
}
