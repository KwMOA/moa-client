//
//  Upgrade_2.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_2.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_2.hpp"

Upgrade_2::Upgrade_2(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_2;
}


void Upgrade_2::upgradeComplete()
{
    
}


void Upgrade_2::update(long dt)
{
    upgrading(40);
}