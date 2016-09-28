//
//  GameLogic.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameLogicImpl.hpp"
#include "GameManager.hpp"
#include "GamePlayer.hpp"


GameLogicImpl::GameLogicImpl()
{

}


void GameLogicImpl::update(long dt)
{
    //building update
    
    GameManager::GetInstance()->getGameWorld()->getGamePlayer(0)->update(dt);
    GameManager::GetInstance()->getGameWorld()->getGamePlayer(1)->update(dt);
    
    
    //check all object if exist to change state
    
    GameManager::GetInstance()->getGameWorld()->checkState();
    
    
    //act all object
    
    GameManager::GetInstance()->getGameWorld()->actState();
    
    
    //apply influence each object
    
    GameManager::GetInstance()->getGameWorld()->applyInfluence();
}