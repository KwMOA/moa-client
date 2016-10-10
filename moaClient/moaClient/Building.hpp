//
//  Building.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include <list>
#include "BaseObject.hpp"

class Upgrade;
class Unit;

struct CreatingUnit {
    int unitCount;
    int unitType;
    int lineNo;
};

class Building : public BaseObject {
protected:
    int createPersent;
    int destroyTime;
    
    std::list<Upgrade*>* upgradeList;
    Upgrade* currentUpgrade;
    
    std::list<int>* unitTypeList;
    CreatingUnit* creatingUnit;
    
   
    Unit* createUnitByUnitType(int unitType);
    
public:
    Building(GamePlayer* _gamePlayer, int _objectType);
    virtual ~Building() {}
   
	Upgrade* getUpgradeByUpgradeType(int upgradeType);

    void startUpgrade(int upgradeType);
    void cancelUpgrade(int upgradeType);
    
    void update(long dt);

    
    
    static Building* createBuilding(GamePlayer* _gamePlayer, int objectType);
};

#endif /* Building_hpp */
