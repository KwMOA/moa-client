//
//  Upgrade_23.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_23_hpp
#define Upgrade_23_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_23 : public Upgrade
{
public:
    Upgrade_23(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_23_hpp */
