//
//  Upgrade_3.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_3_hpp
#define Upgrade_3_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_3 : public Upgrade
{
public:
    Upgrade_3(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_3_hpp */
