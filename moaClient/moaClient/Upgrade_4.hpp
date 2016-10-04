//
//  Upgrade_3.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_4_hpp
#define Upgrade_4_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_4 : public Upgrade
{
public:
    Upgrade_4(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_4_hpp */
