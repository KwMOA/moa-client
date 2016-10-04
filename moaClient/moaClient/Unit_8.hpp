//
//  Unit_8.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_8_hpp
#define Unit_8_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_8 : public Unit {
public:
    Unit_8(GamePlayer* _gamePlayer);
    ~Unit_8() {};
    void click();
    void update(long dt);
};

#endif /* Unit_8_hpp */
