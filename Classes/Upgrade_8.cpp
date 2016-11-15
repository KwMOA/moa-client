//
//  Upgrade_8.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_8.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_8::Upgrade_8(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_8;
}


void Upgrade_8::upgradeComplete()
{
    ((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->setIsDetecting(true);
}


void Upgrade_8::update(int updateCount)
{
    upgrading(40);
}
