//
//  Upgrade.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_hpp
#define Upgrade_hpp

#include <stdio.h>

class Building;

class Upgrade
{
protected:
    int upgradePercent;
    int upgradeCount;
    int upgradeType;
    
    Building* owner;
    
public:
    Upgrade(Building* building);
    virtual void upgradeComplete() = 0;
    virtual void update(long dt) = 0;
    
    void upgrading(int upgradeTime);

    int getUpgradePercent() { return upgradePercent; }
    int getUpgradeCount() { return upgradeCount; }
    int getUpgradeType() { return upgradeType; }
    
    void setUpgradePercent(int percent) { upgradePercent = percent; }
    void setUpgradeCount(int count) { upgradePercent = count; }
    void setUpgradeType(int type) { upgradeType = type; }
};

#endif /* Upgrade_hpp */
