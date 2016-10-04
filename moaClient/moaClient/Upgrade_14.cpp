//
//  Upgrade_14.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_14.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_14::Upgrade_14(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_14;
}


void Upgrade_14::upgradeComplete()
{
    // maybe... skill range up
}


void Upgrade_14::update(long dt)
{
    upgrading(40);
}