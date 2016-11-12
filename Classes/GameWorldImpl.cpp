//
//  GameWorldImpl.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameWorldImpl.hpp"
#include "CheckAvailable.hpp"
#include "GameDefines.h"
#include "GamePlayer.hpp"
#include "GameManager.hpp"
#include "GameScene.h"
#include "BaseObject.hpp"
#include "AiPlayer.h"

GameWorldImpl::GameWorldImpl(GameManager* _gameManager)
{
    gameManager = _gameManager;

    
    gameMap = Layer::create();

    gameMap->setAnchorPoint(Vec2(0,0));
    gameMap->setPosition(Vec2(0,0));
    
    gameManager->getGameScene()->addChild(gameMap, 1);

    
    if(gameManager->isAiMode()) {
        gamePlayers[0] = new GamePlayer(this, 0);
        gamePlayers[1] = new AIPlayer(this, 1, 1);
    } else {
        gamePlayers[0] = new GamePlayer(this, 0);
        gamePlayers[1] = new GamePlayer(this, 1);
    }
    
}

void GameWorldImpl::update(long dt)
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
}


void GameWorldImpl::createBuilding(int userIndex, int objectType)
{
	if(gamePlayers[userIndex]->getChecker()->checkCreateBuilding(userIndex, objectType))
		gamePlayers[userIndex]->createBuilding(objectType);
}


void GameWorldImpl::cancelCreateBuilding(int userIndex, int objectNo)
{
	if(gamePlayers[userIndex]->getChecker()->checkCancelBuilding(userIndex, objectNo))
        gamePlayers[userIndex]->cancelCreateBuilding(objectNo);
}


void GameWorldImpl::upgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (gamePlayers[userIndex]->getChecker()->ckeckUpgradeBuilding(userIndex, objectNo))
        gamePlayers[userIndex]->upgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (gamePlayers[userIndex]->getChecker()->checkCancleUpgradeBuilding(userIndex, objectNo))
        gamePlayers[userIndex]->cancelUpgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo)
{
	if(gamePlayers[userIndex]->getChecker()->checkCreateUnit(userIndex, objectNo))
        gamePlayers[userIndex]->createUnit(objectNo, objectType, objectCount, lineNo);
}

void GameWorldImpl::checkCollusion()
{
    
    
    
    
}

void GameWorldImpl::updateImage()
{
    gameMap->removeAllChildren();
    
    gamePlayers[0]->updateImage(gameMap);
    gamePlayers[1]->updateImage(gameMap);
}

void GameWorldImpl::addChild(BaseObject* object)
{
    gameMap->addChild(object->objectLayer);
}

void GameWorldImpl::removeChild(BaseObject* object)
{
    gameMap->removeChild(object->objectLayer);
}


bool GameWorldImpl::isFinished()
{
    bool finish0 = gamePlayers[0]->isFinished();
    bool finish1 = gamePlayers[1]->isFinished();
    
    if(finish0 || finish1) {
        return true;
    }
    
    return false;
    
}
