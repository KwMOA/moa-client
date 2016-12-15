//
//  Building_2.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_2.h"
#include "Upgrade_2.h"
#include "GameDefines.h"
#include "GamePlayer.h"


Building_2::Building_2(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_2)
{
    upgradeList->push_back(new Upgrade_2(this));
    
    goldAquiredTime = 0;
    
    objectLayer->setPositionY(DISPLAY_HEIGHT - 120);
}

void Building_2::click()
{
    
}

void Building_2::update(int updateCount)
{
    Building::update(updateCount);
    
    if(state != OBJECT_STATE_CREATING && state != OBJECT_STATE_DESTROYING) { // if building can create gold
        
        goldAquiredTime += 1;
        
        if(goldAquiredTime == 8) {
            
            gamePlayer->setGold(gamePlayer->getGold() + 8 + (8 * getUpgradeByUpgradeType(OBJECT_TYPE_UPGRADE_2)->getUpgradeCount()));
            
//            std::cout << "acquired gold - " << gamePlayer->getGold() <<std::endl;
            
            goldAquiredTime = 0;
            
        }
    }
}
