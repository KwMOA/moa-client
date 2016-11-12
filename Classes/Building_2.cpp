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
    
    
    
    
    images = new Sprite**[4];
    
    char buf[128];
    
    images[0] = new Sprite*[3];
    for(int i = 0; i < 3; i++) {
        
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_create_%d.png", i + 1);
        
        images[0][i] = Sprite::create(buf);
        images[0][i]->retain();
        
        images[0][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[1] = new Sprite*[1];
    for(int i = 0; i < 1; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_idle_%d.png", i + 1);
        
        images[1][i] = Sprite::create(buf);
        images[1][i]->retain();
        
        
        
        images[1][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    
    images[2] = new Sprite*[2];
    for(int i = 0; i < 2; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_run_%d.png", i + 1);
        
        images[2][i] = Sprite::create(buf);
        images[2][i]->retain();
        
        images[2][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[3] = new Sprite*[3];
    for(int i = 0; i < 3; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "building/b_1_destroy_%d.png", i + 1);
        
        images[3][i] = Sprite::create(buf);
        images[3][i]->retain();
        
        images[3][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    objectLayer->setAnchorPoint(Vec2(0.5, 0));
    objectLayer->setPosition(Vec2(60, DISPLAY_HEIGHT - 240));
    objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
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
