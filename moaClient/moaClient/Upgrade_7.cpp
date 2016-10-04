//
//  Upgrade_7.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_7.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_7::Upgrade_7(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_7;
}


int Upgrade_7::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_7::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->setHeal(((StaticUnit_3*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3))->getHeal() + 50);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}