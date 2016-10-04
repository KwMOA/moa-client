//
//  Upgrade_18.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_18.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_18::Upgrade_18(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_18;
}


int Upgrade_18::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_18::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        ((StaticUnit_7*)owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7))->setIsIgnoreDef(true);
        
        
        ////////////////////////
        
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}