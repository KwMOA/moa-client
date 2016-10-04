//
//  Unit_9.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_9.hpp"
#include "GameDefines.h"

Unit_9::Unit_9(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_9)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_9::click()
{
    
}

void Unit_9::update(long dt)
{
    
}