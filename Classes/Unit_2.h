//
//  Unit_2.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_2_h
#define Unit_2_h

#include <stdio.h>
#include "Unit.h"

class Unit_2 : public Unit {
public:
    Unit_2(GamePlayer* _gamePlayer);
    ~Unit_2() {};
    void click();
    void update(long dt);
};

#endif /* Unit_2_h */
