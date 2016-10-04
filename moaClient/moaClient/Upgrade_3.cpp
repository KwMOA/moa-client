//
//  Upgrade_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Upgrade_3.hpp"

#include <iostream>
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "Building_7.hpp"
#include "StaticObject.h"


Upgrade_3::Upgrade_3(Building* building) : Upgrade(building)
{
    upgradeType = UPGRADE_TYPE_3;
}


int Upgrade_3::isPossibleUpgrade()
{
    
    return 0;
}


void Upgrade_3::update(long dt)
{
    upgradePercent += 1;

    if(upgradePercent == 400) {
        std::cout << "upgrade complete" <<std::endl;

        upgradePercent = 0;
        upgradeCount++;
        upgradeType = 0;
        
        
        //upgrade something
        
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_1)->getAtk() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_2)->getAtk() + 2);
        owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->setAtk(owner->getGamePlayer()->getStaticUnitByUnitType(OBJECT_TYPE_UNIT_3)->getAtk() + 2);
        
        
        ////////////////////////
        
        
        owner->setState(OBJECT_STATE_IDLE);
    }
}