//
//  Upgrade_22.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_22.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_22::Upgrade_22(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_22;
}


void Upgrade_22::upgradeComplete()
{
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9)->getAtk() + 2);
}


void Upgrade_22::update(long dt)
{
    upgrading(40);
}
