//
//  Upgrade_7.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_7.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_7::Upgrade_7(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_7)
{
}


void Upgrade_7::upgradeComplete()
{
    ((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->setHeal(((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->getHeal() + 50);
}


void Upgrade_7::update(int updateCount)
{
    upgrading(40);
}
