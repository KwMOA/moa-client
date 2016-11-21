//
//  StaticObject.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 5..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "StaticObject.h"

#include "GameDefines.h"
#include "GameWorld.h"
#include "GameManager.h"
#include "GameScene.h"
#include "ControlLayer.h"
#include "CustomButton.h"
#include "Building.h"


StaticObject::StaticObject(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer)
{
    objectType = _objectType;
    memset(name, 0, 20);
    memcpy(name, _name.c_str(), _name.length());
    staticObjectState = _staticObjectState;
    gamePlayer = _gamePlayer;
}

StaticVisibleObject::StaticVisibleObject(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer)
: StaticObject(_objectType, _name, _staticObjectState, _gamePlayer)
{
    
}


StaticUpgrade::StaticUpgrade(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer)
: StaticObject(_objectType, _name, _staticObjectState, _gamePlayer)
{
    upgrade = nullptr;
}

void StaticUpgrade::startUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_UPGRADE_UPGRADING;
}

void StaticUpgrade::cancelUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_ABLE;
}

void StaticUpgrade::completeUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_ABLE;
}


StaticUnit::StaticUnit(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer)
: StaticVisibleObject(_objectType, _name, _staticObjectState, _gamePlayer)
{
    
}


StaticBuilding::StaticBuilding(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer)
: StaticVisibleObject(_objectType, _name, _staticObjectState, _gamePlayer)
{
    building = nullptr;
}

void StaticBuilding::startCreate(Building* _building)
{
    staticObjectState = STATIC_OBJECT_STATE_BUILDING_CREATING;
    building = _building;
}

void StaticBuilding::cancelCreate()
{
    staticObjectState = STATIC_OBJECT_STATE_ABLE;
    building = nullptr;
}
void StaticBuilding::completeCreate()
{
    staticObjectState = STATIC_OBJECT_STATE_ACTIVE;
}

void StaticBuilding::startUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_BUILDING_UPGRADING;
}


void StaticBuilding::cancelUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_ACTIVE;
}


void StaticBuilding::completeUpgrade()
{
    staticObjectState = STATIC_OBJECT_STATE_ACTIVE;
}



StaticUnit_1::StaticUnit_1(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_1, "unit_1", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_1;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_1", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 5;
    def = 20;
    isVisible = 1;
    population = 1;
    
}

StaticUnit_2::StaticUnit_2(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_2, "unit_2", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_2;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_2", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
}


StaticUnit_3::StaticUnit_3(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_3, "unit_3", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_3;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_3", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    heal = 50;
    isDetecting = 0;
}


StaticUnit_4::StaticUnit_4(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_4, "unit_4", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_4;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_4", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    knockBack = 50;
}


StaticUnit_5::StaticUnit_5(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_5, "unit_5", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_5;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_5", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    skillRange = 100;
    skillCount = 3;
}


StaticUnit_6::StaticUnit_6(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_6, "unit_6", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_6;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_6", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    graveCount = 3;
}


StaticUnit_7::StaticUnit_7(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_7, "unit_7", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_7;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_7", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    isIgnoreDef = false;
}


StaticUnit_8::StaticUnit_8(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_8, "unit_8", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_8;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_8", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    shield = 0;
    autoAroundHeal = 50;
}


StaticUnit_9::StaticUnit_9(GamePlayer* _gamePlayer) : StaticUnit(OBJECT_TYPE_UNIT_9, "unit_9", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UNIT_9;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    runImageCount = 6;
    attackImageCount = 6;
    deathImageCount = 6;
    
    memset(name, 0, 20);
    memcpy(name, "unit_9", 6);
    price = 100;
    width = 50;
    maxHp = 100;
    atk = 30;
    atkSpeed = 8;
    atkLoadSpeed = 8;
    atkRange = 0;
    speed = 10;
    def = 20;
    isVisible = 1;
    population = 1;
    
    aroundAtk = 50;
    aroundAtkRange = 100;
}


StaticBuilding_1::StaticBuilding_1(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_1, "building_1", STATIC_OBJECT_STATE_ACTIVE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_1;
    staticObjectState = STATIC_OBJECT_STATE_ACTIVE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_1", 10);
    
    x = 60;
    y = DISPLAY_HEIGHT - 60;
    
    price = 400;
}

void StaticBuilding_1::completeCreate()
{
    StaticBuilding::completeCreate();
//    if(state == OBJECT_STATE_IDLE)
//    gamePlayer->getGameWorld()->getGameManager()->getGameScene()->getControlLayer()->setState(OBJECT_TYPE_BUILDING_1, STATIC_);
}

StaticBuilding_2::StaticBuilding_2(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_2, "building_2", STATIC_OBJECT_STATE_ACTIVE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_2;
    staticObjectState = STATIC_OBJECT_STATE_ACTIVE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_2", 10);
    
    x = 60;
    y = DISPLAY_HEIGHT - 120;
    
    price = 100;
}

void StaticBuilding_2::completeCreate()
{
StaticBuilding::completeCreate();
}

StaticBuilding_3::StaticBuilding_3(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_3, "building_3", STATIC_OBJECT_STATE_ABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_3;
    staticObjectState = STATIC_OBJECT_STATE_ABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_3", 10);
    
    x = 60;
    y = DISPLAY_HEIGHT - 180;
    
    price = 200;
}

void StaticBuilding_3::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_4::StaticBuilding_4(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_4, "building_4", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_4;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_4", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 240;
    
    price = 250;
}

void StaticBuilding_4::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_5::StaticBuilding_5(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_5, "building_5", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_5;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_5", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 300;
    
    price = 300;
}

void StaticBuilding_5::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_6::StaticBuilding_6(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_6, "building_6", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_6;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_6", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 360;
    
    
    price = 400;
}

void StaticBuilding_6::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_7::StaticBuilding_7(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_7, "building_7", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_7;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_7", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 420;
    
    price = 250;
}

void StaticBuilding_7::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_8::StaticBuilding_8(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_8, "building_8", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_8;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_8", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 480;
    
    price = 300;
}

void StaticBuilding_8::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_9::StaticBuilding_9(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_9, "building_9", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_9;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_9", 10);
    
    x = 120;
    y = DISPLAY_HEIGHT - 540;
    
    price = 300;
}

void StaticBuilding_9::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_10::StaticBuilding_10(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_10, "building_10", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_10;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_10", 11);
    
    x = 120;
    y = DISPLAY_HEIGHT - 600;
    
    price = 300;
}

void StaticBuilding_10::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_11::StaticBuilding_11(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_11, "building_11", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_11;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_11", 11);
    
    x = 120;
    y = DISPLAY_HEIGHT - 660;
    
    price = 400;
}

void StaticBuilding_11::completeCreate()
{
StaticBuilding::completeCreate();    
}

StaticBuilding_12::StaticBuilding_12(GamePlayer* _gamePlayer) : StaticBuilding(OBJECT_TYPE_BUILDING_12, "building_12", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_BUILDING_12;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;

    createImageCount = 3;
    workImageCount = 2;
    destroyImageCount = 3;
    
    createCompleteTime = 10;
    
    memset(name, 0, 20);
    memcpy(name, "building_12", 11);
    
    x = 120;
    y = DISPLAY_HEIGHT - 720;
    
    price = 400;
}

void StaticBuilding_12::completeCreate()
{
StaticBuilding::completeCreate();    
}



StaticUpgrade_1::StaticUpgrade_1(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_1, "upgrade_1", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_1;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_1", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_1::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_2::StaticUpgrade_2(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_2, "upgrade_2", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_2;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_2", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
    
    acquiredGoldCount = 100;
}

void StaticUpgrade_2::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_3::StaticUpgrade_3(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_3, "upgrade_3", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_3;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_3", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_3::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_4::StaticUpgrade_4(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_4, "upgrade_4", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_4;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_4", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_4::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_5::StaticUpgrade_5(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_5, "upgrade_5", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_5;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_5", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_5::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_6::StaticUpgrade_6(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_6, "upgrade_6", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_6;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_6", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_6::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_7::StaticUpgrade_7(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_7, "upgrade_7", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_7;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_7", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_7::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_8::StaticUpgrade_8(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_8, "upgrade_8", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_8;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_8", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_8::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_9::StaticUpgrade_9(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_9, "upgrade_9", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_9;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_9", 9);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_9::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_10::StaticUpgrade_10(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_10, "upgrade_10", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_10;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_10", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_10::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_11::StaticUpgrade_11(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_11, "upgrade_11", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_11;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_11", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_11::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_12::StaticUpgrade_12(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_12, "upgrade_12", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_12;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_12", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_12::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_13::StaticUpgrade_13(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_13, "upgrade_13", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_13;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_13", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_13::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_14::StaticUpgrade_14(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_14, "upgrade_14", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_14;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_14", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_14::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_15::StaticUpgrade_15(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_15, "upgrade_15", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_15;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_15", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_15::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_16::StaticUpgrade_16(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_16, "upgrade_16", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_16;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_16", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_16::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_17::StaticUpgrade_17(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_17, "upgrade_17", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_17;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_17", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_17::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_18::StaticUpgrade_18(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_18, "upgrade_18", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_18;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_18", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_18::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_19::StaticUpgrade_19(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_19, "upgrade_19", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_19;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_19", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_19::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_20::StaticUpgrade_20(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_20, "upgrade_20", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_20;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_20", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_20::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_21::StaticUpgrade_21(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_21, "upgrade_21", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_21;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_21", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_21::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_22::StaticUpgrade_22(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_22, "upgrade_22", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_22;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_22", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_22::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_23::StaticUpgrade_23(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_23, "upgrade_23", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_23;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_23", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_23::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}

StaticUpgrade_24::StaticUpgrade_24(GamePlayer* _gamePlayer) : StaticUpgrade(OBJECT_TYPE_UPGRADE_24, "upgrade_24", STATIC_OBJECT_STATE_DISABLE, _gamePlayer)
{
    objectType = OBJECT_TYPE_UPGRADE_24;
    staticObjectState = STATIC_OBJECT_STATE_DISABLE;
    
    memset(name, 0, 20);
    memcpy(name, "upgrade_24", 10);
    
    maxUpgardeCount = 3;
    completeTimeAndPriceArray = new std::pair<int, int>[maxUpgardeCount];
    
    for(int i = 0; i < maxUpgardeCount; i++) {
        completeTimeAndPriceArray[i] = std::make_pair(100, 100);
    }
}

void StaticUpgrade_24::completeUpgrade()
{
    StaticUpgrade::completeUpgrade();    
}


