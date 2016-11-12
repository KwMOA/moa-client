//
//  Unit_6.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_6_hpp
#define Unit_6_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_6 : public Unit {
public:
    Unit_6(GamePlayer* _gamePlayer);
    ~Unit_6() {};
    void click();
    void update(long dt);
};

#endif /* Unit_6_hpp */
