//
//  Upgrade.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include <iostream>
#include "Upgrade.h"
#include "Building.h"
#include "GameDefines.h"

Upgrade::Upgrade(Building* building)
{
    owner = building;
    
    upgradeCount = 0;
    upgradePercent = 0;
    upgradeCompleteNum = 40;
}

void Upgrade::upgrading(int upgradeTime)
{
    upgradePercent += 1;
    
    if(upgradePercent == upgradeCompleteNum) {
        std::cout << "upgrade complete" <<std::endl;
        
        upgradePercent = 0;
        upgradeCount++;
        
        
        //ToDo. change image
        if(upgradePercent % 8 == 0) {
            owner->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            owner->objectLayer->addChild(owner->images[2][0]);
        } else if(upgradePercent % 8 == 4) {
            owner->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            owner->objectLayer->addChild(owner->images[2][1]);
        }
        
        //ToDo. upgrade something
        upgradeComplete();
        
        owner->setState(OBJECT_STATE_IDLE);
        
        owner->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        owner->objectLayer->addChild(owner->images[1][0]);
    }
}

void Upgrade::updateImage()
{

}
