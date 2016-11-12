//
//  Unit_6.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_6.hpp"
#include "GameDefines.h"

Unit_6::Unit_6(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_6)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_6::click()
{
    
}

void Unit_6::update(long dt)
{
    
}