//
//  Upgrade_10.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_10_hpp
#define Upgrade_10_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_10 : public Upgrade
{
public:
    Upgrade_10(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_10_hpp */
