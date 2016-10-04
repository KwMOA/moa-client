//
//  Upgrade_21.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_21_hpp
#define Upgrade_21_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_21 : public Upgrade
{
public:
    Upgrade_21(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_21_hpp */
