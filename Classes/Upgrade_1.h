//
//  Upgrade_1.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_1_h
#define Upgrade_1_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_1 : public Upgrade
{
public:
    Upgrade_1(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_1_h */
