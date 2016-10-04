//
//  Upgrade_17.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_17_hpp
#define Upgrade_17_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_17 : public Upgrade
{
public:
    Upgrade_17(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_17_hpp */
