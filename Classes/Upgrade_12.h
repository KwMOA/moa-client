//
//  Upgrade_12.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_12_h
#define Upgrade_12_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_12 : public Upgrade
{
public:
    Upgrade_12(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_12_h */
