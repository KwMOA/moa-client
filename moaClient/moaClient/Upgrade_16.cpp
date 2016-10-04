//
//  Upgrade_16.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_16.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_16::Upgrade_16(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_16;
}


int Upgrade_16::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_16::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        
        //upgrade something
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_6)->getDef() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_7)->getDef() + 2);
        
        ////////////////////////
        
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}