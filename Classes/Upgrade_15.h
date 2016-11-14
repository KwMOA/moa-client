//
//  Upgrade_15.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_15_h
#define Upgrade_15_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_15 : public Upgrade
{
public:
    Upgrade_15(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_15_h */
