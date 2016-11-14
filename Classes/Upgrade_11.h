//
//  Upgrade_11.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_11_h
#define Upgrade_11_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_11 : public Upgrade
{
public:
    Upgrade_11(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_11_h */
