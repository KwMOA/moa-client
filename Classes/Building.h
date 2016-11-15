//
//  Building.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_h
#define Building_h

#include <stdio.h>
#include <list>
#include "BaseObject.h"

class Upgrade;
class Unit;
class StaticBuilding;

class Building : public BaseObject {
protected:
    StaticBuilding* staticBuilding;
    int createPersent;
    int destroyTime;
    
    std::list<Upgrade*>* upgradeList;
    Upgrade* currentUpgrade;
    
    std::list<int>* unitTypeList;
   
    Unit* createUnitByUnitType(int unitType);
    
public:
    Building(GamePlayer* _gamePlayer, int _objectType);
    virtual ~Building() {}
   
	Upgrade* getUpgradeByUpgradeType(int upgradeType);

    void startUpgrade(int upgradeType);
    void cancelUpgrade(int upgradeType);
    
    void update(int updateCount);
    void updateImage(Layer* layer) {}

    
    
    static Building* createBuilding(GamePlayer* _gamePlayer, int objectType);
    
};

#endif /* Building_h */
