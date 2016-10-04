//
//  Unit.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit.hpp"
#include "GamePlayer.hpp"

Unit::Unit(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_RUN;
    staticUnit = gamePlayer->getStaticUnitByUnitType(_objectType);
}