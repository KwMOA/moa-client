//
//  Upgrade_3.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_9_hpp
#define Upgrade_9_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_9 : public Upgrade
{
public:
    Upgrade_9(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_9_hpp */
