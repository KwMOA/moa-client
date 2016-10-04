//
//  Upgrade_10.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_10.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"

Upgrade_10::Upgrade_10(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_10;
}


int Upgrade_10::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_10::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_4)->getDef() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_5)->getDef() + 2);
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}