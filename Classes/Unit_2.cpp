//
//  Unit_2.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_2.hpp"
#include "GameDefines.h"

Unit_2::Unit_2(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_2)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_2::click()
{
    
}

void Unit_2::update(long dt)
{
    
}