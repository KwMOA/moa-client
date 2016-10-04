//
//  Upgrade_13.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_13_hpp
#define Upgrade_13_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_13 : public Upgrade
{
public:
    Upgrade_13(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_13_hpp */
