//
//  Upgrade_3.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_9_h
#define Upgrade_9_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_9 : public Upgrade
{
public:
    Upgrade_9(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_9_h */
