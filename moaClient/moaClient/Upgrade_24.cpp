//
//  Upgrade_24.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_24.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_24::Upgrade_24(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_24;
}


int Upgrade_24::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_24::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->setAroundAtk(((StaticUnit_9*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9))->getAroundAtk() + 25);
        
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}