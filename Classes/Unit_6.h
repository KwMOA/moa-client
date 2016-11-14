//
//  Unit_6.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_6_h
#define Unit_6_h

#include <stdio.h>
#include "Unit.h"

class Unit_6 : public Unit {
public:
    Unit_6(GamePlayer* _gamePlayer);
    ~Unit_6() {};
    void click();
    void update(long dt);
};

#endif /* Unit_6_h */
