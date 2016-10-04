//
//  Upgrade_20.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_20_hpp
#define Upgrade_20_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_20 : public Upgrade
{
public:
    Upgrade_20(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_20_hpp */
