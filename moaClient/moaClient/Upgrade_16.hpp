//
//  Upgrade_16.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_16_hpp
#define Upgrade_16_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_16 : public Upgrade
{
public:
    Upgrade_16(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_16_hpp */
