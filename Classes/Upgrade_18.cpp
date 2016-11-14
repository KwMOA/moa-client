//
//  Upgrade_18.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_18.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_18::Upgrade_18(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_18;
}


void Upgrade_18::upgradeComplete()
{
    ((StaticUnit_7*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7))->setIsIgnoreDef(true);
}


void Upgrade_18::update(long dt)
{
    upgrading(40);
}
