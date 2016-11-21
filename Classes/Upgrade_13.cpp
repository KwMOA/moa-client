//
//  Upgrade_13.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_13.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_13::Upgrade_13(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_13)
{
}


void Upgrade_13::upgradeComplete()
{
    ((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->setAtk(((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->getAtk() + 20); // set atk is skill atk
}


void Upgrade_13::update(int updateCount)
{
    upgrading(40);
}
