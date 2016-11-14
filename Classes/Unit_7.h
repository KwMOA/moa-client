//
//  Unit_7.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_7_h
#define Unit_7_h

#include <stdio.h>
#include "Unit.h"

class Unit_7 : public Unit {
public:
    Unit_7(GamePlayer* _gamePlayer);
    ~Unit_7() {};
    void click();
    void update(long dt);
};

#endif /* Unit_7_h */
