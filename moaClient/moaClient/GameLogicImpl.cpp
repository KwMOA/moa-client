//
//  GameLogic.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameLogicImpl.hpp"
#include "GameManager.hpp"


GameLogicImpl::GameLogicImpl()
{

}


void GameLogicImpl::update(long dt)
{
    //check all object if exist to change state
    
    GameManager::GetInstance()->getGameWorld()->checkState();
    
    
    //act all object
    
    GameManager::GetInstance()->getGameWorld()->actState();
    
    
    //apply influence each object
    
    GameManager::GetInstance()->getGameWorld()->applyInfluence();
}