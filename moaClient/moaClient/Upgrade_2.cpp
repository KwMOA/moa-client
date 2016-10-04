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


int Upgrade_2::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_2::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //ToDo. upgrade something
        
        //not exist to do something
        
        /////////////////////////
        owner->setState(OBJECT_STATE_IDLE);
    }
}