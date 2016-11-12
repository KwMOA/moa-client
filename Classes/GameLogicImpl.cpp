//
//  GameLogic.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameLogicImpl.hpp"
#include "GameManager.hpp"
#include "AiPlayer.h"
#include "GameWorld.h"


GameLogicImpl::GameLogicImpl(GameManager* _gameManager)
{
    gameManager = _gameManager;
}


void GameLogicImpl::update(long dt)
{
    //buildings and units updates
    gameManager->getGameWorld()->getGamePlayer(0)->update(dt);
    ((AIPlayer*)gameManager->getGameWorld()->getGamePlayer(1))->update(dt);
    
    
    // check collusion
    gameManager->getGameWorld()->checkCollusion();
    
    // apply influence
    gameManager->getGameWorld()->getGamePlayer(0)->applyInfluenceUnit();
    gameManager->getGameWorld()->getGamePlayer(1)->applyInfluenceUnit();
    
    // TODO. check is finish game
    
    if(gameManager->getGameWorld()->isFinished()) {
        gameManager->finishGame();
    }
    
    // print all sprite
//    gameManager->getGameWorld()->updateImage();
}
