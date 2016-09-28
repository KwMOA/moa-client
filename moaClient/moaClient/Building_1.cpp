//
//  Building_1.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building_1.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"

Building_1::Building_1()
{    
    quantity = 1;
    createPersent = 0;
    goldAquiredTime = 0;
}

void Building_1::click()
{
    
}
void Building_1::update(long dt)
{
    if(state == OBJECT_STATE_CREATEING) { // if building is creating
        
        createPersent += 10;
        
        if(createPersent == 800) {
            std::cout << "create building_1 - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_WORK;
        }
        
        
    } else if(state == OBJECT_STATE_WORK) { // if building is working
        
        goldAquiredTime += 1;
        
        if(goldAquiredTime == 40) {
            std::cout << "aquired gold - " << objectNo <<std::endl;
            
            gamePlayer->addGold(100);
            
            goldAquiredTime = 0;
        }
        
    }
}