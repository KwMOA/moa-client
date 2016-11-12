//
//  Upgrade_7.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_7_hpp
#define Upgrade_7_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_7 : public Upgrade
{
public:
    Upgrade_7(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_7_hpp */
