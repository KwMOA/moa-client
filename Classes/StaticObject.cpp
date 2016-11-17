//
//  StaticObject.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 5..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "StaticObject.h"

#include "GameDefines.h"

StaticUnit_1::StaticUnit_1()
{
    unitType = OBJECT_TYPE_UNIT_1;
    
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

StaticUnit_2::StaticUnit_2()
{
    unitType = OBJECT_TYPE_UNIT_2;
    
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

StaticUnit_3::StaticUnit_3()
{
    unitType = OBJECT_TYPE_UNIT_3;
    
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

StaticUnit_4::StaticUnit_4()
{
    unitType = OBJECT_TYPE_UNIT_4;
    
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

StaticUnit_5::StaticUnit_5()
{
    unitType = OBJECT_TYPE_UNIT_5;
    
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

StaticUnit_6::StaticUnit_6()
{
    unitType = OBJECT_TYPE_UNIT_6;
    
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

StaticUnit_7::StaticUnit_7()
{
    unitType = OBJECT_TYPE_UNIT_7;
    
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

StaticUnit_8::StaticUnit_8()
{
    unitType = OBJECT_TYPE_UNIT_8;
    
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

StaticUnit_9::StaticUnit_9()
{
    unitType = OBJECT_TYPE_UNIT_9;
    
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

StaticBuilding_1::StaticBuilding_1()
{
    objectType = OBJECT_TYPE_BUILDING_1;
    
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

StaticBuilding_2::StaticBuilding_2()
{
    objectType = OBJECT_TYPE_BUILDING_2;
    
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

StaticBuilding_3::StaticBuilding_3()
{
    objectType = OBJECT_TYPE_BUILDING_3;
    
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

StaticBuilding_4::StaticBuilding_4()
{
    objectType = OBJECT_TYPE_BUILDING_4;
    
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

StaticBuilding_5::StaticBuilding_5()
{
    objectType = OBJECT_TYPE_BUILDING_5;
    
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

StaticBuilding_6::StaticBuilding_6()
{
    objectType = OBJECT_TYPE_BUILDING_6;
    
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

StaticBuilding_7::StaticBuilding_7()
{
    objectType = OBJECT_TYPE_BUILDING_7;
    
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

StaticBuilding_8::StaticBuilding_8()
{
    objectType = OBJECT_TYPE_BUILDING_8;
    
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

StaticBuilding_9::StaticBuilding_9()
{
    objectType = OBJECT_TYPE_BUILDING_9;
    
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

StaticBuilding_10::StaticBuilding_10()
{
    objectType = OBJECT_TYPE_BUILDING_10;
    
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

StaticBuilding_11::StaticBuilding_11()
{
    objectType = OBJECT_TYPE_BUILDING_11;
    
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

StaticBuilding_12::StaticBuilding_12()
{
    objectType = OBJECT_TYPE_BUILDING_12;
    
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
