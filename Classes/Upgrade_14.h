//
//  Upgrade_14.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_14_h
#define Upgrade_14_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_14 : public Upgrade
{
public:
    Upgrade_14(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_3_h */
