//
//  Unit_8.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_8.hpp"
#include "GameDefines.h"

Unit_8::Unit_8(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_8)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_8::click()
{
    
}

void Unit_8::update(long dt)
{
    
}