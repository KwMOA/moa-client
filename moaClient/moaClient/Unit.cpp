//
//  Unit.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit.hpp"
#include "GamePlayer.hpp"
#include "Unit_1.hpp"
#include "Unit_2.hpp"
#include "Unit_3.hpp"
#include "Unit_4.hpp"
#include "Unit_5.hpp"
#include "Unit_6.hpp"
#include "Unit_7.hpp"
#include "Unit_8.hpp"
#include "Unit_9.hpp"


Unit::Unit(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_RUN;
    staticUnit = gamePlayer->getStaticUnitByUnitType(_objectType);
}

Unit* Unit::createUnit(GamePlayer* _gamePlayer, int _objectType)
{
    switch (_objectType) {
        case OBJECT_TYPE_UNIT_1:
            return new Unit_1(_gamePlayer);
        case OBJECT_TYPE_UNIT_2:
            return new Unit_2(_gamePlayer);
        case OBJECT_TYPE_UNIT_3:
            return new Unit_3(_gamePlayer);
        case OBJECT_TYPE_UNIT_4:
            return new Unit_4(_gamePlayer);
        case OBJECT_TYPE_UNIT_5:
            return new Unit_5(_gamePlayer);
        case OBJECT_TYPE_UNIT_6:
            return new Unit_6(_gamePlayer);
        case OBJECT_TYPE_UNIT_7:
            return new Unit_7(_gamePlayer);
        case OBJECT_TYPE_UNIT_8:
            return new Unit_8(_gamePlayer);
        case OBJECT_TYPE_UNIT_9:
            return new Unit_9(_gamePlayer);
        default:
            return nullptr;
    }
}