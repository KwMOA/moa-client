//
//  Upgrade_8.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_8_h
#define Upgrade_8_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_8 : public Upgrade
{
public:
    Upgrade_8(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_8_h */
