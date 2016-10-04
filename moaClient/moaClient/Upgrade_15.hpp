//
//  Upgrade_15.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_15_hpp
#define Upgrade_15_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_15 : public Upgrade
{
public:
    Upgrade_15(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_15_hpp */
