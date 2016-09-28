//
//  Building.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building.hpp"
#include "GameDefines.h"

Building::Building(GamePlayer* _gamePlayer) :BaseObject(_gamePlayer)
{
    state = OBJECT_STATE_CREATEING;
}
