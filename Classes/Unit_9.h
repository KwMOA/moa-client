//
//  Unit_9.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_9_h
#define Unit_9_h

#include <stdio.h>
#include "Unit.h"

class Unit_9 : public Unit {
public:
    Unit_9(GamePlayer* _gamePlayer);
    ~Unit_9() {};
    void click();
    void update(long dt);
};

#endif /* Unit_9_h */
