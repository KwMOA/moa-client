//
//  Unit_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_3.hpp"
#include "GameDefines.h"

Unit_3::Unit_3(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_3)
{
    w = 50;
    h = 70;
    hp = staticUnit->getMaxHp();
}

void Unit_3::click()
{
    
}

void Unit_3::update(long dt)
{
    
}