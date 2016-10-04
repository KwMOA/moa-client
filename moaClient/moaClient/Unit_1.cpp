//
//  Unit_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_1.hpp"
#include "GameDefines.h"

Unit_1::Unit_1(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_1)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_1::click()
{
    
}

void Unit_1::update(long dt)
{
    
}