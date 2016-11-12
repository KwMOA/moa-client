//
//  Unit_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_1.hpp"
#include "GameDefines.h"
#include "ActRun.hpp"
Unit_1::Unit_1(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_1)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
    
    images = new Sprite**[4];
    
    char buf[128];
    
    images[0] = new Sprite*[1];
    for(int i = 0; i < 1; i++) {
        
        memset(buf, 0, 128);
        sprintf(buf, "unit_1_idle_%d.png", i + 1);
        
        images[0][i] = Sprite::createWithSpriteFrameName(buf);
        images[0][i]->retain();
        
        images[0][i]->setAnchorPoint(Vec2(0.5, 0));
//        images[0][i]->setPosition(Vec2(60, 300));
//        images[0][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[1] = new Sprite*[6];
    for(int i = 0; i < 6; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "unit_1_run_%d.png", i + 1);
        
        images[1][i] = Sprite::createWithSpriteFrameName(buf);
        images[1][i]->retain();
        
        
        
        images[1][i]->setAnchorPoint(Vec2(0.5, 0));
//        images[1][i]->setPosition(Vec2(60, 300));
//        images[1][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    
    images[2] = new Sprite*[6];
    for(int i = 0; i < 6; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "unit_1_attack_%d.png", i + 1);
        
        images[2][i] = Sprite::createWithSpriteFrameName(buf);
        images[2][i]->retain();
        
        images[2][i]->setAnchorPoint(Vec2(0.5, 0));
//        images[2][i]->setPosition(Vec2(60, 300));
//        images[2][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[3] = new Sprite*[6];
    for(int i = 0; i < 6; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "unit_1_run_%d.png", i + 1);
        
        images[3][i] = Sprite::createWithSpriteFrameName(buf);
        images[3][i]->retain();
        
        images[3][i]->setAnchorPoint(Vec2(0.5, 0));
//        images[3][i]->setPosition(Vec2(60, 300));
//        images[3][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
    
    ActRun* act = new ActRun(this);
    actList.push_back(act);
}

void Unit_1::click()
{
    
}

void Unit_1::update(long dt)
{
    Unit::update(dt);
}

void Unit_1::updateImage(Layer *layer)
{

}
