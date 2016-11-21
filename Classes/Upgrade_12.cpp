//
//  Upgrade_12.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_12.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_12::Upgrade_12(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_12)
{
}


void Upgrade_12::upgradeComplete()
{
    ((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->setAtkRange(((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->getAtkRange() + 50);
}


void Upgrade_12::update(int updateCount)
{
    upgrading(40);
}

