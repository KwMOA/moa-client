//
//  Building.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building.h"
#include "GameDefines.h"
#include "Upgrade.h"
#include "GamePlayer.h"
#include "StaticObject.h"
#include "Unit_1.h"
#include "Unit_2.h"
#include "Building_1.h"
#include "Building_2.h"
#include "Building_3.h"
#include "Building_4.h"
#include "Building_5.h"
#include "Building_6.h"
#include "Building_7.h"
#include "Building_8.h"
#include "Building_9.h"
#include "Building_10.h"
#include "Building_11.h"
#include "Building_12.h"


//test
#include "ClientGamePacket.h"
#include "GameManager.h"

Building::Building(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_CREATING;
    
    staticBuilding = gamePlayer->getStaticBuildingByBuildingType(_objectType);

    createPersent = 0;
    destroyTime = 0;
    
    upgradeList = new std::list<Upgrade*>;
    
    currentUpgrade = nullptr;
    
    unitTypeList = new std::list<int>;
    
    
    //set images
    
    images = new Sprite**[4];
    
    char buf[128];
    
    images[0] = new Sprite*[staticBuilding->getCreateImageCount()];
    for(int i = 0; i < staticBuilding->getCreateImageCount(); i++) {
        
        memset(buf, 0, 128);
        sprintf(buf, "%s_create_%d.png", staticBuilding->getName(), i + 1);
        
        images[0][i] = Sprite::createWithSpriteFrameName(buf);
        images[0][i]->retain();
        
        images[0][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[1] = new Sprite*[1];
    for(int i = 0; i < 1; i++) {
        memset(buf, 0, 128);
        sprintf(buf, "%s_idle_%d.png", staticBuilding->getName(), i + 1);
        
        images[1][i] = Sprite::createWithSpriteFrameName(buf);
        images[1][i]->retain();
        
        
        
        images[1][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    
    images[2] = new Sprite*[staticBuilding->getWorkImageCount()];
    for(int i = 0; i < staticBuilding->getWorkImageCount(); i++) {
        memset(buf, 0, 128);
        sprintf(buf, "%s_work_%d.png", staticBuilding->getName(), i + 1);
        
        images[2][i] = Sprite::createWithSpriteFrameName(buf);
        images[2][i]->retain();
        
        images[2][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    images[3] = new Sprite*[staticBuilding->getDestroyImageCount()];
    for(int i = 0; i < staticBuilding->getDestroyImageCount(); i++) {
        memset(buf, 0, 128);
        sprintf(buf, "%s_destroy_%d.png", staticBuilding->getName(), i + 1);
        
        images[3][i] = Sprite::createWithSpriteFrameName(buf);
        images[3][i]->retain();
        
        images[3][i]->setScale(128 / (double)1701, 128 / (double)1701);
    }
    
    objectLayer->setAnchorPoint(Vec2(0.5, 0));
    objectLayer->setPositionX(gamePlayer->sameXPlayerIndex(60));
    objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
}

void Building::update(int updateCount)
{
    if(state == OBJECT_STATE_CREATING) { // if building is creating
        
        createPersent += 10;
        
        if(createPersent < 200) {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
        } else if(createPersent < 500) {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[0][1], 0, TAG_IMAGE_OBJECT);
        } else {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[0][2], 0, TAG_IMAGE_OBJECT);
        }
        
        if(createPersent == 800) {
            std::cout << "create building - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_IDLE;
            
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[1][0], 0, TAG_IMAGE_OBJECT);
        }
        
        
    } else if(state == OBJECT_STATE_DESTROYING) {
        
        destroyTime += 1;
        
        if(destroyTime < 2) {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[3][0], 0, TAG_IMAGE_OBJECT);
        } else if(destroyTime < 5) {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[3][1], 0, TAG_IMAGE_OBJECT);
        } else {
            objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            objectLayer->addChild(images[3][2], 0, TAG_IMAGE_OBJECT);
        }
        
        if(destroyTime == 8) {
            std::cout << "destroy - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_DESTROY;
        }
        
    } else if(state == OBJECT_STATE_UPGRADING) {
        
        if(currentUpgrade != nullptr) {
            
            currentUpgrade->update(updateCount);
            
        } else {
            std::cout << "not exist currentUpgrade - " << objectNo <<std::endl;
            
        }
        
    } else if(state == OBJECT_STATE_CREATING_UNIT) { // now not use these
        
    } else {
        
    }
}

Upgrade* Building::getUpgradeByUpgradeType(int upgradeType)
{
    std::list<Upgrade*>::iterator itr;
    
    for(itr = upgradeList->begin(); itr != upgradeList->end(); itr++) {
        if((*itr)->getUpgradeType() == upgradeType) {
            return *itr;
        }
    }
    
    std::cout << "invalid upgrade - " << upgradeType <<std::endl;
    
    return nullptr;
}

Unit* Building::createUnitByUnitType(int unitType)
{
    switch (unitType) {
        case OBJECT_TYPE_UNIT_1:
            return new Unit_1(gamePlayer);
            
        case OBJECT_TYPE_UNIT_2:
            return new Unit_2(gamePlayer);
            
        default:
            return nullptr;
    }
}


void Building::startUpgrade(int upgradeType)
{
    state = OBJECT_STATE_UPGRADING;
    currentUpgrade = getUpgradeByUpgradeType(upgradeType);
}

void Building::cancelUpgrade(int upgradeType)
{
    state = OBJECT_STATE_IDLE;
    
    currentUpgrade->setUpgradePercent(0);
    currentUpgrade = nullptr;
}





Building* Building::createBuilding(GamePlayer* _gamePlayer, int _objectType)
{
    switch (_objectType) {
        case OBJECT_TYPE_BUILDING_1:
            return new Building_1(_gamePlayer);
        case OBJECT_TYPE_BUILDING_2:
            return new Building_2(_gamePlayer);
        case OBJECT_TYPE_BUILDING_3:
            return new Building_3(_gamePlayer);
        case OBJECT_TYPE_BUILDING_4:
            return new Building_4(_gamePlayer);
        case OBJECT_TYPE_BUILDING_5:
            return new Building_5(_gamePlayer);
        case OBJECT_TYPE_BUILDING_6:
            return new Building_6(_gamePlayer);
        case OBJECT_TYPE_BUILDING_7:
            return new Building_7(_gamePlayer);
        case OBJECT_TYPE_BUILDING_8:
            return new Building_8(_gamePlayer);
        case OBJECT_TYPE_BUILDING_9:
            return new Building_9(_gamePlayer);
        case OBJECT_TYPE_BUILDING_10:
            return new Building_10(_gamePlayer);
        case OBJECT_TYPE_BUILDING_11:
            return new Building_11(_gamePlayer);
        case OBJECT_TYPE_BUILDING_12:
            return new Building_12(_gamePlayer);
        default:
            return nullptr;
    }
}


