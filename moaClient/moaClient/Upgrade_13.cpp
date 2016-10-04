//
//  Upgrade_13.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_13.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_13::Upgrade_13(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_13;
}


int Upgrade_13::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_13::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->setAtk(((StaticUnit_5*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5))->getAtk() + 20); // set atk is skill atk
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}