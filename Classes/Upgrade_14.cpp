//
//  Upgrade_14.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_14.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.h"
#include "GamePlayer.h"
#include "StaticObject.h"
Upgrade_14::Upgrade_14(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_14)
{
}


void Upgrade_14::upgradeComplete()
{
    // maybe... skill range up
}


void Upgrade_14::update(int updateCount)
{
    upgrading(40);
}
