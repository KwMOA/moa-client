//
//  Upgrade_3.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_4_h
#define Upgrade_4_h

#include <stdio.h>
#include "Upgrade.h"

class Upgrade_4 : public Upgrade
{
public:
    Upgrade_4(Building* building);
    void upgradeComplete();
    void update(int updateCount);
};

#endif /* Upgrade_4_h */
