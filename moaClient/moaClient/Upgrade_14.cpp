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


int Upgrade_14::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_14::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        // maybe is skill range up
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}