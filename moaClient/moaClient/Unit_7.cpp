//
//  Unit_7.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_7.hpp"
#include "GameDefines.h"

Unit_7::Unit_7(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_7)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_7::click()
{
    
}

void Unit_7::update(long dt)
{
    
}