//
//  Upgrade_12.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_12.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_12::Upgrade_12(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_12;
}


int Upgrade_12::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_12::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->setAtkRange(((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->getAtkRange() + 50);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}