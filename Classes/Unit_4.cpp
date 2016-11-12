//
//  Unit_4.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_4.hpp"
#include "GameDefines.h"

Unit_4::Unit_4(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_4)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_4::click()
{
    
}

void Unit_4::update(long dt)
{
    
}