//
//  Upgrade_10.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_10_h
#define Upgrade_10_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_10 : public Upgrade
{
public:
    Upgrade_10(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_10_h */
