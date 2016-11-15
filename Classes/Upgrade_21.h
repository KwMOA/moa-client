//
//  Upgrade_21.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_21_h
#define Upgrade_21_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_21 : public Upgrade
{
public:
    Upgrade_21(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_21_h */
