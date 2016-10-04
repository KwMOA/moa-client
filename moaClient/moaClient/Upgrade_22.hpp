//
//  Upgrade_22.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_22_hpp
#define Upgrade_22_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_22 : public Upgrade
{
public:
    Upgrade_22(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_22_hpp */
