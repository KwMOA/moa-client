//
//  Upgrade_2.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_2_hpp
#define Upgrade_2_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_2 : public Upgrade
{
public:
    Upgrade_2(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_2_hpp */
