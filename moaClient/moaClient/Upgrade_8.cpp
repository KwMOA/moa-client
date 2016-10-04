//
//  Upgrade_8.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_8.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_8::Upgrade_8(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_8;
}


int Upgrade_8::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_8::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->setIsDetecting(true);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}