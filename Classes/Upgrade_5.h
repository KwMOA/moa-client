//
//  Upgrade_5.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_5_h
#define Upgrade_5_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_5 : public Upgrade
{
public:
    Upgrade_5(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_5_h */
