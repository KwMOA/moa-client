//
//  Upgrade_1.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_1_hpp
#define Upgrade_1_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_1 : public Upgrade
{
public:
    Upgrade_1(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_1_hpp */
