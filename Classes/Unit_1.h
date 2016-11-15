//
//  Unit_1.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_1_h
#define Unit_1_h

#include <stdio.h>
#include "Unit.h"

class Unit_1 : public Unit {
public:
    Unit_1(GamePlayer* _gamePlayer);
    ~Unit_1() {};
    void click();
    void update(int updateCount);
    void updateImage(Layer* layer);
};

#endif /* Unit_1_h */
