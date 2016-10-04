//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_11.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_11::Upgrade_11(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_11;
}


int Upgrade_11::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_11::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->setKnockBack(((StaticUnit_4*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4))->getKnockBack() + 50);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}