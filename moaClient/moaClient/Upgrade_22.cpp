//
//  Upgrade_22.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_22.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_22::Upgrade_22(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_22;
}


int Upgrade_22::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_22::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_9)->getAtk() + 2);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}