//
//  Unit_1.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_1_hpp
#define Unit_1_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_1 : public Unit {
public:
    Unit_1(GamePlayer* _gamePlayer);
    ~Unit_1() {};
    void click();
    void update(long dt);
    void updateImage(Layer* layer);
};

#endif /* Unit_1_hpp */
