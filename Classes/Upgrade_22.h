//
//  Upgrade_22.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_22_h
#define Upgrade_22_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_22 : public Upgrade
{
public:
    Upgrade_22(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_22_h */
