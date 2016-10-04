//
//  Upgrade_18.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_18_hpp
#define Upgrade_18_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_18 : public Upgrade
{
public:
    Upgrade_18(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_18_hpp */
