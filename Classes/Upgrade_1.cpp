//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_1.h"

#include <iostream>
#include "GameDefines.h"
#include "Building_1.h"

Upgrade_1::Upgrade_1(Building* building) : Upgrade(building, OBJECT_TYPE_UPGRADE_1)
{

}


void Upgrade_1::upgradeComplete()
{
    
}


void Upgrade_1::update(int updateCount)
{
    upgrading(40);
}
