//
//  Upgrade_10.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_10.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_10::Upgrade_10(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_10;
}


void Upgrade_10::upgradeComplete()
{
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->getDef() + 2);
    owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->getDef() + 2);
}


void Upgrade_10::update(int updateCount)
{
    upgrading(40);
}
