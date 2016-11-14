//
//  Upgrade_19.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_19_h
#define Upgrade_19_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_19 : public Upgrade
{
public:
    Upgrade_19(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_19_h */
