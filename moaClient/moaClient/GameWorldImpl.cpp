//
//  GameWorldImpl.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameWorldImpl.hpp"

GameWorldImpl::GameWorldImpl()
{
    gamePlayers[0] = new GamePlayer(this, 0);
    gamePlayers[1] = new GamePlayer(this, 1);
}

void GameWorldImpl::checkState()
{
    
}

void GameWorldImpl::actState()
{
    
}

void GameWorldImpl::applyInfluence()
{
    
}

void GameWorldImpl::createBuilding(int userIndex, int objectType)
{
    gamePlayers[userIndex]->createBuilding(objectType);
}


void GameWorldImpl::cancelCreateBuilding(int userIndex, int objectNo)
{
    gamePlayers[userIndex]->cancelCreateBuilding(objectNo);
}


void GameWorldImpl::upgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
    gamePlayers[userIndex]->upgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
    gamePlayers[userIndex]->cancelUpgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo)
{
    gamePlayers[userIndex]->createUnit(objectNo, objectType, objectCount, lineNo);
}
