//
//  Building_2.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_2.hpp"
#include "Upgrade_2.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"


Building_2::Building_2(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_2)
{
    upgradeList->push_back(new Upgrade_2(this));
    
    goldAquiredTime = 0;
}

void Building_2::click()
{
    
}

void Building_2::update(long dt)
{
    Building::update(dt);
    
    if(state != OBJECT_STATE_CREATING && state != OBJECT_STATE_DESTROYING) { // if building can create gold
        
        goldAquiredTime += 1;
        
        if(goldAquiredTime == 40) {
            
            gamePlayer->addGold(100 + (100 * getUpgradeByUpgradeType(UPGRADE_TYPE_2)->getUpgradeCount()));
            
            std::cout << "acquired gold - " << gamePlayer->getGold() <<std::endl;
            
            goldAquiredTime = 0;
            
        }
    }
}