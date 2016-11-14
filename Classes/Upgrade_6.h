//
//  Upgrade_6.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_6_h
#define Upgrade_6_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_6 : public Upgrade
{
public:
    Upgrade_6(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_6_h */
