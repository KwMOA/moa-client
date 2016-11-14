//
//  Upgrade_7.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_7_h
#define Upgrade_7_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_7 : public Upgrade
{
public:
    Upgrade_7(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_7_h */
