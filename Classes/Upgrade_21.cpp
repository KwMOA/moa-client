//
//  Upgrade_21.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_21.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_21::Upgrade_21(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_21)
{
}


void Upgrade_21::upgradeComplete()
{
    ((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->setAutoAroundHeal(((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->getAutoAroundHeal() + 20);
}


void Upgrade_21::update(int updateCount)
{
    upgrading(40);
}
