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
    gamePlayers[0] = new GamePlayer();
    gamePlayers[1] = new GamePlayer();
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
    
}


void GameWorldImpl::cancelCreateBuilding(int userIndex, int objectType)
{
    
}


void GameWorldImpl::upgradeBuilding(int userIndex, int objectType, int upgradeType)
{
    
}


void GameWorldImpl::cancelUpgradeBuilding(int userIndex, int objectType, int upgradeType)
{
    
}


void GameWorldImpl::createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo)
{
    
}
