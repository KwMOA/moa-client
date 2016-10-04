//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_1.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_1.hpp"

Upgrade_1::Upgrade_1(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_1;
}


void Upgrade_1::upgradeComplete()
{
    
}


void Upgrade_1::update(long dt)
{
    upgrading(40);
}