//
//  Upgrade.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include <iostream>
#include "Upgrade.hpp"
#include "Building.hpp"
#include "GameDefines.h"

Upgrade::Upgrade(Building* building)
{
    owner = building;
    
    upgradeCount = 0;
    upgradePercent = 0;
}

void Upgrade::upgrading(int upgradeTime)
{
    upgradePercent += 1;
    
    if(upgradePercent == upgradeTime) {
        std::cout << "upgrade complete" <<std::endl;
        
        upgradePercent = 0;
        upgradeCount++;
        
        //ToDo. upgrade something
        upgradeComplete();
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}