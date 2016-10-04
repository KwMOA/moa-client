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

Building::Building(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_CREATEING;
    
    createPersent = 0;
    destroyTime = 0;
    
    upgradeList = new std::list<Upgrade*>;
    
    currentUpgrade = nullptr;
    
    unitTypeList = new std::list<int>;
    creatingUnit = nullptr;
}

void Building::update(long dt)
{
    if(state == OBJECT_STATE_CREATEING) { // if building is creating
        
        createPersent += 10;
        
        if(createPersent == 800) {
            std::cout << "create building_1 - " << objectNo <<std::endl;
            
            state = OBJECT_STATE_IDLE;
        }
        
        
    } else if(state == OBJECT_STATE_DESTROYING) {
        
        destroyTime += 1;
        
        if(destroyTime == 8) {
            std::cout << "destroy - " << objectNo <<std::endl;
            
            //TODO. think that how to remove in building list
        }
        
    } else if(state == OBJECT_STATE_UPDATEING) {
       
        if(currentUpgrade != nullptr) {
            
            currentUpgrade->update(dt);
            
        } else {
            std::cout << "not exist currentUpgrade - " << objectNo <<std::endl;
            
        }
        
    } else if(state == OBJECT_STATE_CREATEING_UNIT) {
        
        if(creatingUnit != nullptr) {
            
            for(int i = 0; i < creatingUnit->unitCount; i++) {
            
                Unit* unit = createUnitByUnitType(creatingUnit->unitType);
                
                if(unit == nullptr) {
                    
                    std::cout << "not exist unit - " << objectNo <<std::endl;
                    
                } else {
                    
                    //ToDo. set Unit in line
                    
                }
                
            }
            
            delete creatingUnit;
            
            creatingUnit = nullptr;

            
        } else {
            std::cout << "not exist creatingUnit - " << objectNo <<std::endl;
            
        }
        
        
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