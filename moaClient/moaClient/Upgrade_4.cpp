//
//  Upgrade_4.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_4.hpp"

#include <iostream>
#include "GameDefines.h"
#include "Building_7.hpp"
#include "GamePlayer.hpp"
#include "StaticObject.h"


Upgrade_4::Upgrade_4(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_4;
}


int Upgrade_4::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_4::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        //upgrade something
        
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->getDef() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->getDef() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->setDef(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->getDef() + 2);
        
        
        ////////////////////////
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}