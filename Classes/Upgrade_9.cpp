//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_9.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_9::Upgrade_9(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_9;
}


void Upgrade_9::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->getAtk() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->getAtk() + 2);
}


void Upgrade_9::update(int updateCount)
{
    upgrading(40);
}
