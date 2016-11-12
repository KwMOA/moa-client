//
//  Building_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_1.hpp"
#include "GameDefines.h"
#include "Upgrade_1.hpp"



Building_1::Building_1(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_1)
{
    upgradeList->push_back(new Upgrade_1(this));
    
    images = new Sprite**[4];
    
    char buf[128];

    images[0] = new Sprite*[3];
    for(int i = 0; i < 3; i++) {
        
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_create_%d.png", i + 1);
        
        images[0][i] = Sprite::create(buf);
        images[0][i]->retain();
        
        images[0][i]->setAnchorPoint(Vec2(0.5, 0));
        images[0][i]->setPosition(Vec2(60, 300));
        images[0][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[1] = new Sprite*[1];
    for(int i = 0; i < 1; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_idle_%d.png", i + 1);
        
        images[1][i] = Sprite::create(buf);
        images[1][i]->retain();
        
        
        
        images[1][i]->setAnchorPoint(Vec2(0.5, 0));
        images[1][i]->setPosition(Vec2(60, 300));
        images[1][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    
    images[2] = new Sprite*[2];
    for(int i = 0; i < 2; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_run_%d.png", i + 1);
        
        images[2][i] = Sprite::create(buf);
        images[2][i]->retain();
        
        images[2][i]->setAnchorPoint(Vec2(0.5, 0));
        images[2][i]->setPosition(Vec2(60, 300));
        images[2][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[3] = new Sprite*[3];
    for(int i = 0; i < 3; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_destroy_%d.png", i + 1);
        
        images[3][i] = Sprite::create(buf);
        images[3][i]->retain();
        
        images[3][i]->setAnchorPoint(Vec2(0.5, 0));
        images[3][i]->setPosition(Vec2(60, 300));
        images[3][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
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


