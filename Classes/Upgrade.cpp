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
#include "GamePlayer.h"
#include "StaticObject.h"

Upgrade::Upgrade(Building* building, int _upgradeType) : BaseObject(building->getGamePlayer(), _upgradeType)
{
    owner = building;
    upgradeType = _upgradeType;
    
    upgradeCount = 0;
    upgradePercent = 0;
    upgradeCompleteNum = 40;
    
    staticUpgrade = building->getGamePlayer()->getStaticUpgradeByUpgradeType(_upgradeType);
    staticUpgrade->setUpgrade(this);
}

void Upgrade::upgrading(int upgradeTime)
{
    upgradePercent += 1;
    
    if(upgradePercent == upgradeCompleteNum) {
        std::cout << "upgrade complete" <<std::endl;
        
        completeUpgrade();
    } else {
    
        //ToDo. change image
        if(upgradePercent % 8 == 0) {
            owner->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            owner->objectLayer->addChild(owner->images[1][0]);
        } else if(upgradePercent % 8 == 4) {
            owner->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            owner->objectLayer->addChild(owner->images[1][0]);
        }
    }
    
}

void Upgrade::updateImage()
{

}


void Upgrade::setState(int _state)
{
    BaseObject::setState(_state);
}


void Upgrade::startUpgrade()
{
    owner->getGamePlayer()->setGold(owner->getGamePlayer()->getGold() - staticUpgrade->getCompleteTimeArray()[upgradeCount].second);
    
    staticUpgrade->startUpgrade();
}

void Upgrade::cancelUpgrade()
{
    upgradePercent = 0;
    
    staticUpgrade->cancelUpgrade();
}

void Upgrade::completeUpgrade()
{
    upgradePercent = 0;
    upgradeCount++;
    
    //ToDo. upgrade something
    upgradeComplete();
    
    //
    owner->completeUpgrade(objectType);
    
    staticUpgrade->completeUpgrade();
}



