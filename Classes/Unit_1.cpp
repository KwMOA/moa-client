//
//  Unit_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit_1.h"
#include "GameDefines.h"
#include "ActRun.h"
Unit_1::Unit_1(GamePlayer* _gamePlayer) : Unit(_gamePlayer, OBJECT_TYPE_UNIT_1)
{
}

void Unit_1::click()
{
    
}

void Unit_1::update(int updateCount)
{
    Unit::update(updateCount);
}

void Unit_1::updateImage(Layer *layer)
{

}
