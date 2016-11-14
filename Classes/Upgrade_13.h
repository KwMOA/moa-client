//
//  Upgrade_13.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_13_h
#define Upgrade_13_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_13 : public Upgrade
{
public:
    Upgrade_13(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_13_h */
