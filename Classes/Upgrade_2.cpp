//
//  Upgrade_2.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_2.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_2.h"

Upgrade_2::Upgrade_2(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_2)
{
}


void Upgrade_2::upgradeComplete()
{
    
}


void Upgrade_2::update(int updateCount)
{
    upgrading(40);
}
