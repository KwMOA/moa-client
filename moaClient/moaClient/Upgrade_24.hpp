//
//  Upgrade_24.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_24_hpp
#define Upgrade_24_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_24 : public Upgrade
{
public:
    Upgrade_24(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_24_hpp */
