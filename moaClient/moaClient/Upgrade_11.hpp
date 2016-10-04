//
//  Upgrade_11.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_11_hpp
#define Upgrade_11_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_11 : public Upgrade
{
public:
    Upgrade_11(Building* building);
    void upgradeComplete();
    void update(long dt);
};

#endif /* Upgrade_11_hpp */
