//
//  Upgrade_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_9.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_8.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_9::Upgrade_9(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_9;
}


int Upgrade_9::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_9::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->getAtk() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->getAtk() + 2);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}