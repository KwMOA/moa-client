//
//  Upgrade_2.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_2_h
#define Upgrade_2_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_2 : public Upgrade
{
public:
    Upgrade_2(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_2_h */
