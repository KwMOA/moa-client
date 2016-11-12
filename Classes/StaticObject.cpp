//
//  StaticObject.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 5..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "StaticObject.hpp"

#include "GameDefines.h"

StaticUnit_1::StaticUnit_1()
{
    unitType = OBJECT_TYPE_UNIT_1;
    
    name = "unit_1";
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
    
    name = "unit_2";
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
    
    name = "unit_3";
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
    
    name = "unit_4";
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
    
    name = "unit_5";
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
    
    name = "unit_6";
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
    
    name = "unit_7";
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
    
    name = "unit_8";
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
    
    name = "unit_9";
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

