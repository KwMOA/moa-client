//
//  Upgrade_12.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_12_hpp
#define Upgrade_12_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_12 : public Upgrade
{
public:
    Upgrade_12(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_12_hpp */
