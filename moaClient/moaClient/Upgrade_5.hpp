//
//  Upgrade_5.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_5_hpp
#define Upgrade_5_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_5 : public Upgrade
{
public:
    Upgrade_5(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_5_hpp */
