//
//  Building_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_3.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"

//test
#include "GameManager.hpp"
#include "ClientGamePacket.h"
#include "ClientInput.h"
#include "GameWorldImpl.hpp"
#include "TaskManager.h"
//


Building_3::Building_3(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_3)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_1);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_2);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_3);
    
    
    
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
    objectLayer->setPosition(Vec2(60, DISPLAY_HEIGHT - 360));
    objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
    
    testNum = 0;
}

void Building_3::click()
{
    
}

void Building_3::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        if(testNum == 0) {
            CreateUnitCI* p3 = new CreateUnitCI();
            p3->objectType = OBJECT_TYPE_UNIT_1;
            p3->objectNo = objectNo;
            p3->objectCount = 1;
            p3->lineNo = 1;
            if(getGamePlayer()->getPlayerIndex() == 0) {
                ((GameWorldImpl*)gamePlayer->getGameWorld())->getGameManager()->getTaskManager()->pushBackMessage(p3);
            }
            
            testNum++;
        }
    }

}
