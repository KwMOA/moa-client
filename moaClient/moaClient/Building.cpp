//
//  Building.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Building.hpp"
#include "GameDefines.h"
#include "Upgrade.hpp"
#include "Unit_1.hpp"
#include "Unit_2.hpp"
#include "Building_1.hpp"
#include "Building_2.hpp"
#include "Building_3.hpp"
#include "Building_4.hpp"
#include "Building_5.hpp"
#include "Building_6.hpp"
#include "Building_7.hpp"
#include "Building_8.hpp"
#include "Building_9.hpp"
#include "Building_10.hpp"
#include "Building_11.hpp"
#include "Building_12.hpp"


//test
#include "ClientGamePacket.h"
#include "GameManager.hpp"
#include "NetworkHandler.h"

Building::Building(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_CREATING;
    
    createPersent = 0;
    destroyTime = 0;
    
    upgradeList = new std::list<Upgrade*>;
    
    currentUpgrade = nullptr;
    
    unitTypeList = new std::list<int>;
    creatingUnit = nullptr;
}

void Building::update(long dt)
{
    if(state == OBJECT_STATE_CREATING) { // if building is creating
        
        createPersent += 10;
        
        if(createPersent == 800) {
            std::cout << "create building_1 - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_IDLE;
        }
        
        
    } else if(state == OBJECT_STATE_DESTROYING) {
        
        destroyTime += 1;
        
        if(destroyTime == 8) {
            std::cout << "destroy - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_DESTROY;
        }
        
    } else if(state == OBJECT_STATE_UPGRADING) {
        
        if(currentUpgrade != nullptr) {
            
            currentUpgrade->update(dt);
            
        } else {
            std::cout << "not exist currentUpgrade - " << objectNo <<std::endl;
            
        }
        
    } else if(state == OBJECT_STATE_CREATING_UNIT) { // now not use these
        
//        if(creatingUnit != nullptr) {
//            
//            for(int i = 0; i < creatingUnit->unitCount; i++) {
//            
//                Unit* unit = createUnitByUnitType(creatingUnit->unitType);
//                
//                if(unit == nullptr) {
//                    
//                    std::cout << "not exist unit - " << objectNo <<std::endl;
//                    
//                } else {
//                    
//                    //ToDo. set Unit in line
//                    
//                }
//                
//            }
//            
//            delete creatingUnit;
//            
//            creatingUnit = nullptr;
//
//            
//        } else {
//            std::cout << "not exist creatingUnit - " << objectNo <<std::endl;
//            
//        }
        
        
    } else {
        
    }
}

Upgrade* Building::getUpgradeByUpgradeType(int upgradeType)
{
    std::list<Upgrade*>::iterator itr;
    
    for(itr = upgradeList->begin(); itr != upgradeList->end(); itr++) {
        if((*itr)->getUpgradeType() == upgradeType) {
            return *itr;
        }
    }
    
    std::cout << "invalid upgrade - " << upgradeType <<std::endl;
    
    return nullptr;
}

Unit* Building::createUnitByUnitType(int unitType)
{
    switch (unitType) {
        case OBJECT_TYPE_UNIT_1:
            return new Unit_1(gamePlayer);
            
        case OBJECT_TYPE_UNIT_2:
            return new Unit_2(gamePlayer);
            
        default:
            return nullptr;
    }
}


void Building::startUpgrade(int upgradeType)
{
    state = OBJECT_STATE_UPGRADING;
    currentUpgrade = getUpgradeByUpgradeType(upgradeType);
}

void Building::cancelUpgrade(int upgradeType)
{
    state = OBJECT_STATE_IDLE;
    
    currentUpgrade->setUpgradePercent(0);
    currentUpgrade = nullptr;
}





Building* Building::createBuilding(GamePlayer* _gamePlayer, int _objectType)
{
    switch (_objectType) {
        case OBJECT_TYPE_BUILDING_1:
            return new Building_1(_gamePlayer);
        case OBJECT_TYPE_BUILDING_2:
            return new Building_2(_gamePlayer);
        case OBJECT_TYPE_BUILDING_3:
            return new Building_3(_gamePlayer);
        case OBJECT_TYPE_BUILDING_4:
            return new Building_4(_gamePlayer);
        case OBJECT_TYPE_BUILDING_5:
            return new Building_5(_gamePlayer);
        case OBJECT_TYPE_BUILDING_6:
            return new Building_6(_gamePlayer);
        case OBJECT_TYPE_BUILDING_7:
            return new Building_7(_gamePlayer);
        case OBJECT_TYPE_BUILDING_8:
            return new Building_8(_gamePlayer);
        case OBJECT_TYPE_BUILDING_9:
            return new Building_9(_gamePlayer);
        case OBJECT_TYPE_BUILDING_10:
            return new Building_10(_gamePlayer);
        case OBJECT_TYPE_BUILDING_11:
            return new Building_11(_gamePlayer);
        case OBJECT_TYPE_BUILDING_12:
            return new Building_12(_gamePlayer);
        default:
            return nullptr;
    }
}