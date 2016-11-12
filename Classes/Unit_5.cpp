//
//  Unit_5.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_5.hpp"
#include "GameDefines.h"

Unit_5::Unit_5(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_5)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_5::click()
{
    
}

void Unit_5::update(long dt)
{
    
}