//
//  Upgrade_16.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_16_h
#define Upgrade_16_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_16 : public Upgrade
{
public:
    Upgrade_16(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_16_h */
