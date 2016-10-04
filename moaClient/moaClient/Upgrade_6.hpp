//
//  Upgrade_6.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_6_hpp
#define Upgrade_6_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_6 : public Upgrade
{
public:
    Upgrade_6(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_6_hpp */
