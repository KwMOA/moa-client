//
//  Upgrade_8.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 30..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Upgrade_8_hpp
#define Upgrade_8_hpp

#include <stdio.h>
#include "Upgrade.hpp"

class Upgrade_8 : public Upgrade
{
public:
    Upgrade_8(Building* building);
    int isPossibleUpgrade();
    void update(long dt);
};

#endif /* Upgrade_8_hpp */
