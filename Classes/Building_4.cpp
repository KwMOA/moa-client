//
//  Building_4.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_4.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"

Building_4::Building_4(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_4)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_4);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_5);
    
    
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

void Building_4::click()
{
    
}

void Building_4::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    
    }
}
