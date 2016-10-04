//
//  Upgrade_14.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_14_hpp
#define Upgrade_14_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_14 : public Upgrade
{
public:
    Upgrade_14(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_3_hpp */
