//
//  GamePlayer.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GamePlayer.h"
#include "BaseObject.h"
#include "BasicDefines.h"
#include "GameDefines.h"
#include "Building.h"
#include "Unit.h"
#include "StaticObject.h"
#include "GameWorld.h"
#include "TechChecker.h"
#include "GameManager.h"
#include "GameScene.h"
#include "TopLayer.h"

GamePlayer::GamePlayer(GameWorld* _gameWorld, int _playerIndex)
{
    objectNoCreator = 1;
    
    gameWorld = _gameWorld;
    
    playerIndex = _playerIndex;
    
    buildingList.clear();
    destroyBuildingList.clear();
    
    unitList[0].clear();
    unitList[1].clear();
    unitList[2].clear();
    
    
    // set static object
    
    staticUnitList.push_back(new StaticUnit_1(this));
    staticUnitList.push_back(new StaticUnit_2(this));
    staticUnitList.push_back(new StaticUnit_3(this));
    staticUnitList.push_back(new StaticUnit_4(this));
    staticUnitList.push_back(new StaticUnit_5(this));
    staticUnitList.push_back(new StaticUnit_6(this));
    staticUnitList.push_back(new StaticUnit_7(this));
    staticUnitList.push_back(new StaticUnit_8(this));
    staticUnitList.push_back(new StaticUnit_9(this));
    
    staticBuildingList.push_back(new StaticBuilding_1(this));
    staticBuildingList.push_back(new StaticBuilding_2(this));
    staticBuildingList.push_back(new StaticBuilding_3(this));
    staticBuildingList.push_back(new StaticBuilding_4(this));
    staticBuildingList.push_back(new StaticBuilding_5(this));
    staticBuildingList.push_back(new StaticBuilding_6(this));
    staticBuildingList.push_back(new StaticBuilding_7(this));
    staticBuildingList.push_back(new StaticBuilding_8(this));
    staticBuildingList.push_back(new StaticBuilding_9(this));
    staticBuildingList.push_back(new StaticBuilding_10(this));
    staticBuildingList.push_back(new StaticBuilding_11(this));
    staticBuildingList.push_back(new StaticBuilding_12(this));
    
    
    staticUpgradeList.push_back(new StaticUpgrade_1(this));
    staticUpgradeList.push_back(new StaticUpgrade_2(this));
    staticUpgradeList.push_back(new StaticUpgrade_3(this));
    staticUpgradeList.push_back(new StaticUpgrade_4(this));
    staticUpgradeList.push_back(new StaticUpgrade_5(this));
    staticUpgradeList.push_back(new StaticUpgrade_6(this));
    staticUpgradeList.push_back(new StaticUpgrade_7(this));
    staticUpgradeList.push_back(new StaticUpgrade_8(this));
    staticUpgradeList.push_back(new StaticUpgrade_9(this));
    staticUpgradeList.push_back(new StaticUpgrade_10(this));
    staticUpgradeList.push_back(new StaticUpgrade_11(this));
    staticUpgradeList.push_back(new StaticUpgrade_12(this));
    staticUpgradeList.push_back(new StaticUpgrade_13(this));
    staticUpgradeList.push_back(new StaticUpgrade_14(this));
    staticUpgradeList.push_back(new StaticUpgrade_15(this));
    staticUpgradeList.push_back(new StaticUpgrade_16(this));
    staticUpgradeList.push_back(new StaticUpgrade_17(this));
    staticUpgradeList.push_back(new StaticUpgrade_18(this));
    staticUpgradeList.push_back(new StaticUpgrade_19(this));
    staticUpgradeList.push_back(new StaticUpgrade_20(this));
    staticUpgradeList.push_back(new StaticUpgrade_21(this));
    staticUpgradeList.push_back(new StaticUpgrade_22(this));
    staticUpgradeList.push_back(new StaticUpgrade_23(this));
    staticUpgradeList.push_back(new StaticUpgrade_24(this));
    
    ////////////////////
    
    setGold(getStaticBuildingByBuildingType(OBJECT_TYPE_BUILDING_1)->getPrice() + getStaticBuildingByBuildingType(OBJECT_TYPE_BUILDING_2)->getPrice());
    setPopulation(0);
    
    checker = new TechChecker(this);
    
    
    ////////////////////////////////////// init start building
    
    int objectNo = createBuilding(OBJECT_TYPE_BUILDING_1);
    Building* building = (Building*)getBuildingByObjectNo(objectNo);
    
    building->completeCreate();
    
    building->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
    building->objectLayer->addChild(building->images[1][0], 0, TAG_IMAGE_OBJECT);
    
    
    objectNo = createBuilding(OBJECT_TYPE_BUILDING_2);
    building = (Building*)getBuildingByObjectNo(objectNo);
    
    building->completeCreate();
    
    building->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
    building->objectLayer->addChild(building->images[1][0], 0, TAG_IMAGE_OBJECT);
    
    //////////////////////////////////////
}

BaseObject* GamePlayer::getBuildingByObjectNo(int objectNo)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo) {
            return baseObject;
        }
    }
    
    return nullptr;
}



BaseObject* GamePlayer::getUnitByObjectNo(int objectNo)
{
    return nullptr;
}

BaseObject* GamePlayer::getBuildingByObjectType(int objectType)
{
	for (buildingItr = buildingList.begin(); buildingItr != buildingList.end(); buildingItr++)
	{
		BaseObject* baseObject = (BaseObject*)*buildingItr;

		if (baseObject->getObjectType() == objectType) {
			return baseObject;
		}
	}

	return nullptr;
}

int GamePlayer::createBuilding(int objectType)
{
    Building* building = Building::createBuilding(this, objectType);
    
    if(building == nullptr) {
        std::cout<< "invalid building type - " << objectType <<std::endl;
        
        return -1;
    }
    
    building->setObjectNo(objectNoCreator);
    
    buildingList.push_back(building);
    
    gameWorld->addChild(building);
    
    return objectNoCreator++;
}

int GamePlayer::cancelCreateBuilding(int objectNo)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_CREATING) {
            ((Building*)baseObject)->cancelCreate();
            baseObject->setState(OBJECT_STATE_DESTROYING);
            
            buildingList.remove(*buildingItr);
            destroyBuildingList.push_back(baseObject);
            
//            cancelCreatingBuildingNotify((Building*)baseObject);
            
            std::cout<< "destroy building start - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}

int GamePlayer::upgradeBuilding(int objectNo, int upgradeType)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_IDLE) {
            ((Building*)baseObject)->startUpgrade(upgradeType);
            
            std::cout<< "upgrade building start - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}


int GamePlayer::cancelUpgradeBuilding(int objectNo, int upgradeType)
{
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        if(baseObject->getObjectNo() == objectNo && baseObject->getState() == OBJECT_STATE_UPGRADING) {
            ((Building*)baseObject)->cancelUpgrade(upgradeType);
            
            std::cout<< "cancel upgrade building - " << baseObject->getObjectNo() <<std::endl;
            
            return 1;
        }
    }
    
    return -1;
}



int GamePlayer::createUnit(int objectNo, int objectType, int objectCount, int lineNo)
{
    for(int i = 0; i < objectCount; i++) {
        
        Unit* unit = Unit::createUnit(this, objectType);
        
        if(unit == nullptr) {
            std::cout<< "invalid unit type - " << objectType <<std::endl;
            
            return -1;
        }
        
        unit->setObjectNo(objectNoCreator++);
        unit->setLineNo(lineNo);
        unit->setX(sameXPlayerIndex(64));
        
        unitList[lineNo - 1].push_back(unit);
        
        std::cout<< "create unit - objectNo : " << unit->getObjectNo() << ", objectType : " << objectType <<std::endl;
    
        gameWorld->addChild(unit);
    }
    
    return objectNoCreator;
}


std::list<Unit*> GamePlayer::getUnitListByUnitType(int unitType)
{
    std::list<Unit*> sendUnitList;
    
    for(int i = 0; i < 3; i++) {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            if((*unitItr[i])->getObjectType() == unitType)
            {
                sendUnitList.push_back(*unitItr[i]);
            }
            
        }
    }
    
    return sendUnitList;
}



StaticUnit* GamePlayer::getStaticUnitByUnitType(int unitType)
{
    for(staticUnitItr = staticUnitList.begin(); staticUnitItr != staticUnitList.end(); staticUnitItr++)
    {
        if((*staticUnitItr)->getObjectType() == unitType)
        {
            return *staticUnitItr;
        }
        
    }
    
    return nullptr;
}

StaticBuilding* GamePlayer::getStaticBuildingByBuildingType(int buildingType)
{
    for(staticBuildingItr = staticBuildingList.begin(); staticBuildingItr != staticBuildingList.end(); staticBuildingItr++)
    {
        if((*staticBuildingItr)->getObjectType() == buildingType)
        {
            return *staticBuildingItr;
        }
        
    }
    
    return nullptr;
}

StaticUpgrade* GamePlayer::getStaticUpgradeByUpgradeType(int upgradeType)
{
    for(staticUpgradeItr = staticUpgradeList.begin(); staticUpgradeItr != staticUpgradeList.end(); staticUpgradeItr++)
    {
        if((*staticUpgradeItr)->getObjectType() == upgradeType)
        {
            return *staticUpgradeItr;
        }
        
    }
    
    return nullptr;
}



void GamePlayer::update(int updateCount)
{
    
    // update buildings
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        baseObject->update(updateCount);
    }
    
    
    // update destorying building
    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; )
    {
        Building* building = (Building*)*destroyBuildingItr;
        
        building->update(updateCount);
        
        if(building->getState() == OBJECT_STATE_DESTROY) {
            destroyBuildingItr = destroyBuildingList.erase(destroyBuildingItr);
            
            delete building;
            
        } else {
            destroyBuildingItr++;
        }
    }
    
    
    
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            Unit* unit = *unitItr[i];
            
            unit->update(updateCount);
        }
    }
}

void GamePlayer::applyInfluenceUnit()
{
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end();)
        {
            Unit* unit = *unitItr[i];
            
            unit->applyInfluence();
            
            if(unit->getState() == OBJECT_STATE_DEAD) {
                unitItr[i] = unitList[i].erase(unitItr[i]);
            } else {
                unitItr[i]++;
            }
        }
    }
}



//Unit* GamePlayer::checkEnemyInRange(int lineNo, int x, int width, int range)
//{
//    Unit* unit;
//    if(playerIndex == 0) {
//        unit = gameWorld->getGamePlayer(1)->getBestCloseUnit(lineNo, x, width, range);
//    } else {
//        unit = gameWorld->getGamePlayer(0)->getBestCloseUnit(lineNo, x, width, range);
//    }
//    
//    return unit;
//}

Unit* GamePlayer::getBestCloseUnit(Unit* otherUnit)
{
    Unit* closeUnit = nullptr;
    int i = otherUnit->getLineNo() - 1;
    
    if(playerIndex == 0) {
     
        int closeX = otherUnit->getX() - (otherUnit->getWidth() + otherUnit->getAtkRange() + 1); // 1 is max attack range + 1 to find max attack unit
        
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            Unit* unit = *unitItr[i];
            
            if(otherUnit->isPossibleToAttack(unit)) { // if find close unit
                
                int x;
                
                if(unit->getUpdateCount() != otherUnit->getUpdateCount()) { // if otherUnit is already update
                    x = unit->getPX();
                } else {
                    x = unit->getX();
                }
                
                if(closeX < x + unit->getWidth()) // check that unit is best close
                {
                    closeX = x + unit->getWidth();
                
                    closeUnit = unit;
                }
            }
        }
        
    } else {
    
        int closeX = otherUnit->getX() + (otherUnit->getWidth() + otherUnit->getAtkRange() + 1); // 1 is max attack range + 1 to find max attack unit
        
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            Unit* unit = *unitItr[i];
            
            if(otherUnit->isPossibleToAttack(unit)) { // if find close unit
                
                int x;
                
                if(unit->getUpdateCount() != otherUnit->getUpdateCount()) { // if otherUnit is already update
                    x = unit->getPX();
                } else {
                    x = unit->getX();
                }
                
                if(closeX > x - unit->getWidth()) // check that unit is best close
                {
                    closeX = x - unit->getWidth();
                    
                    closeUnit = unit;
                }
            }
        }
        
    }
    
    return closeUnit;
}


void GamePlayer::updateImage(Layer* layer)
{
    // update buildings
    for(buildingItr = buildingList.begin(); buildingItr != buildingList.end() ; buildingItr++)
    {
        BaseObject* baseObject = (BaseObject*)*buildingItr;
        
        baseObject->updateImage(layer);
    }
    
    
    // update destorying building
    for(destroyBuildingItr = destroyBuildingList.begin(); destroyBuildingItr != destroyBuildingList.end() ; )
    {
        Building* building = (Building*)*destroyBuildingItr;
        
        building->updateImage(layer);
    }
    
    
    
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            Unit* unit = *unitItr[i];
            
            unit->updateImage(layer);
        }
    }

}

bool GamePlayer::isFinished()
{
    
    
    for(int i = 0; i < 3; i++)
    {
        for(unitItr[i] = unitList[i].begin(); unitItr[i] != unitList[i].end(); unitItr[i]++)
        {
            Unit* unit = *unitItr[i];
            
            if(playerIndex == 0) {
                if(unit->getX() > DISPLAY_WIDTH - 80) {
                    return true;
                }
            } else {
                if(unit->getX() < 80) {
                    return true;
                }
            }
            
        }
    }
    
    return false;
}


void GamePlayer::finishUnitDead()
{
    
}

void GamePlayer::setGold(int _gold)
{
    gold = _gold;
    
    if(playerIndex == 0)
        gameWorld->getGameManager()->getGameScene()->getTopLayer()->changeGold(gold);
}

void GamePlayer::setPopulation(int _population)
{
    population = _population;
    
    if(playerIndex == 0)
        gameWorld->getGameManager()->getGameScene()->getTopLayer()->changePopulation(population);
}
