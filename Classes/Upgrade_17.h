//
//  Upgrade_17.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_17_h
#define Upgrade_17_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_17 : public Upgrade
{
public:
    Upgrade_17(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_17_h */
