//
//  Building_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_1.h"
#include "GameDefines.h"
#include "Upgrade_1.h"



Building_1::Building_1(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_1)
{
    upgradeList->push_back(new Upgrade_1(this));
    
    objectLayer->setPositionY(DISPLAY_HEIGHT - 60);
}

void Building_1::click()
{
    
}

void Building_1::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }
}


void Building_1::updateImage(Layer* layer)
{
//    objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
//    
//    if(state == OBJECT_STATE_IDLE) { // if building is idle
//        objectLayer->addChild(images[1][0], 0, TAG_IMAGE_OBJECT);
//    } else if (state == OBJECT_STATE_CREATING) {
//        if(createPersent < 200) {
//            objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
//        } else if(createPersent < 500) {
//            objectLayer->addChild(images[0][1], 0, TAG_IMAGE_OBJECT);
//        } else {
//            objectLayer->addChild(images[0][2], 0, TAG_IMAGE_OBJECT);
//        }
//    } else if(state == OBJECT_STATE_UPGRADING) {
//        if(currentUpgrade != nullptr) {
//            currentUpgrade->updateImage();
//        } else {
//            std::cout << "not exist currentUpgrade - " << objectNo <<std::endl;
//        }
//    }    
}


