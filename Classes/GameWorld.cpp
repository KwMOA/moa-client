//
//  GameWorld.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameWorld.h"
#include "TechChecker.h"
#include "GameDefines.h"
#include "GamePlayer.h"
#include "GameManager.h"
#include "GameScene.h"
#include "BaseObject.h"
#include "AiPlayer.h"

GameWorld::GameWorld(GameManager* _gameManager)
{
    gameManager = _gameManager;
    
    gameMap = Layer::create();
    
    auto bg = Sprite::create("fefefe.png");
    gameMap->addChild(bg);
    bg->setAnchorPoint(Vec2(0.5, 0.5));
    bg->setPosition(Vec2((DISPLAY_WIDTH / 2), (DISPLAY_HEIGHT / 2) - 120));
    
    gameMap->setAnchorPoint(Vec2(0,0));
    gameMap->setPosition(Vec2(0,0));
    
    gameManager->getGameScene()->addChild(gameMap, 0);

    
    if(gameManager->isAiMode()) {
        gamePlayers[0] = new GamePlayer(this, 0);
        gamePlayers[1] = new AIPlayer(this, 1, 1);
    } else {
        gamePlayers[0] = new GamePlayer(this, 0);
        gamePlayers[1] = new GamePlayer(this, 1);
    }
}

void GameWorld::update(int updateCount)
{    
    //buildings and units updates
    if(gameManager->isAiMode()) {
        gameManager->getGameWorld()->getGamePlayer(0)->update(updateCount);
        ((AIPlayer*)gameManager->getGameWorld()->getGamePlayer(1))->update(updateCount);
    } else {
        gameManager->getGameWorld()->getGamePlayer(0)->update(updateCount);
        gameManager->getGameWorld()->getGamePlayer(1)->update(updateCount);
    }
    
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


void GameWorld::createBuilding(int userIndex, int objectType)
{
	if(gamePlayers[userIndex]->getChecker()->checkCreateBuilding(objectType))
		gamePlayers[userIndex]->createBuilding(objectType);
}


void GameWorld::cancelCreateBuilding(int userIndex, int objectNo)
{
	if(gamePlayers[userIndex]->getChecker()->checkCancelBuilding(objectNo))
        gamePlayers[userIndex]->cancelCreateBuilding(objectNo);
}


void GameWorld::upgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (gamePlayers[userIndex]->getChecker()->ckeckUpgradeBuilding(objectNo))
        gamePlayers[userIndex]->upgradeBuilding(objectNo, upgradeType);
}


void GameWorld::cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (gamePlayers[userIndex]->getChecker()->checkCancleUpgradeBuilding(objectNo))
        gamePlayers[userIndex]->cancelUpgradeBuilding(objectNo, upgradeType);
}


void GameWorld::createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo)
{
	if(gamePlayers[userIndex]->getChecker()->checkCreateUnit(objectNo, objectType, objectCount, lineNo))
        gamePlayers[userIndex]->createUnit(objectNo, objectType, objectCount, lineNo);
}

void GameWorld::checkCollusion()
{
    
    
    
    
}

void GameWorld::updateImage()
{
    gameMap->removeAllChildren();
    
    gamePlayers[0]->updateImage(gameMap);
    gamePlayers[1]->updateImage(gameMap);
}

void GameWorld::addChild(BaseObject* object)
{
    gameMap->addChild(object->objectLayer);
}

void GameWorld::removeChild(BaseObject* object)
{
    gameMap->removeChild(object->objectLayer);
}


bool GameWorld::isFinished()
{
    bool finish0 = gamePlayers[0]->isFinished();
    bool finish1 = gamePlayers[1]->isFinished();
    
    if(finish0 || finish1) {
        return true;
    }
    
    return false;
    
}
