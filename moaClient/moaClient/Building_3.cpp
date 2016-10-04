//
//  Building_3.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_3.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"

//test
#include "GameManager.hpp"
#include "ClientGamePacket.h"
#include "NetworkHandler.h"
//


Building_3::Building_3(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_3)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_1);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_2);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_3);
}

void Building_3::click()
{
    
}

void Building_3::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    }

}