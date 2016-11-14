//
//  Upgrade_24.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_24_h
#define Upgrade_24_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_24 : public Upgrade
{
public:
    Upgrade_24(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_24_h */
