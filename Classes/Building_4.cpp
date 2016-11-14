//
//  Building_4.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_4.h"
#include "GameDefines.h"
#include "GamePlayer.h"

Building_4::Building_4(GamePlayer* _gamePlayer) : Building(_gamePlayer, OBJECT_TYPE_BUILDING_4)
{
    unitTypeList->push_back(OBJECT_TYPE_UNIT_4);
    unitTypeList->push_back(OBJECT_TYPE_UNIT_5);
    
    
    objectLayer->setPositionY(DISPLAY_HEIGHT - 240);
}

void Building_4::click()
{
    
}

void Building_4::update(long dt)
{
    Building::update(dt);
    
    if(state == OBJECT_STATE_IDLE) { // if building is idle
        
    
    }
}
