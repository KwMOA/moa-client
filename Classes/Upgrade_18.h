//
//  Upgrade_18.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_18_h
#define Upgrade_18_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_18 : public Upgrade
{
public:
    Upgrade_18(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_18_h */
