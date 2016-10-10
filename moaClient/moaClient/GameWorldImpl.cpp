//
//  GameWorldImpl.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameWorldImpl.hpp"
#include "CheckAvavilable.hpp"

GameWorldImpl::GameWorldImpl()
{
    gamePlayers[0] = new GamePlayer(this, 0);
    gamePlayers[1] = new GamePlayer(this, 1);
	checker = CheckAvailable(*gamePlayers);
}

void GameWorldImpl::update(long dt)
{
    
}


void GameWorldImpl::createBuilding(int userIndex, int objectType)
{
	if(checker.checkCreateBuilding(userIndex, objectType))
		gamePlayers[userIndex]->createBuilding(objectType);
}


void GameWorldImpl::cancelCreateBuilding(int userIndex, int objectNo)
{
	if(checker.checkCancelBuilding(userIndex, objectNo))
    gamePlayers[userIndex]->cancelCreateBuilding(objectNo);
}


void GameWorldImpl::upgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (checker.ckeckUpgradeBuilding(userIndex, objectNo))
    gamePlayers[userIndex]->upgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::cancelUpgradeBuilding(int userIndex, int objectNo, int upgradeType)
{
	if (checker.checkCancleUpgradeBuilding(userIndex, objectNo))
    gamePlayers[userIndex]->cancelUpgradeBuilding(objectNo, upgradeType);
}


void GameWorldImpl::createUnit(int userIndex, int objectNo, int objectType, int objectCount, int lineNo)
{
	if(checker.checkCreateUnit(userIndex, objectNo))
    gamePlayers[userIndex]->createUnit(objectNo, objectType, objectCount, lineNo);
}
