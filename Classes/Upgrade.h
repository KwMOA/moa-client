//
//  Upgrade.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_h
#define Upgrade_h

#include <stdio.h>
#include "BaseObject.h"

class Building;
class StaticUpgrade;

class Upgrade : public BaseObject
{
protected:
    int upgradePercent;
    int upgradeCount;
    int upgradeType;
    int upgradeCompleteNum;
    
    Building* owner;
    
    StaticUpgrade* staticUpgrade;
public:
    Upgrade(Building* building, int _upgradeType);
    virtual void upgradeComplete() = 0;
    virtual void update(int updateCount) = 0;
    void updateImage();
    
    void upgrading(int upgradeTime);

    int getUpgradePercent() { return upgradePercent; }
    int getUpgradeCount() { return upgradeCount; }
    int getUpgradeType() { return upgradeType; }
    
    void setUpgradePercent(int percent) { upgradePercent = percent; }
    void setUpgradeCount(int count) { upgradePercent = count; }
    void setUpgradeType(int type) { upgradeType = type; }
    
    void updateImage(Layer* layer) {}
    void click() {}
    ~Upgrade() {}
    
    void setState(int _state);
    
    void startUpgrade();
    void cancelUpgrade();
    void completeUpgrade();
};

#endif /* Upgrade_h */
