//
//  Upgrade_21.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_21.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_21::Upgrade_21(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_21;
}


int Upgrade_21::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_21::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->setAutoAroundHeal(((StaticUnit_8*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_8))->getAutoAroundHeal() + 20);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}