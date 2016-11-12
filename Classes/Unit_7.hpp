//
//  Unit_7.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_7_hpp
#define Unit_7_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_7 : public Unit {
public:
    Unit_7(GamePlayer* _gamePlayer);
    ~Unit_7() {};
    void click();
    void update(long dt);
};

#endif /* Unit_7_hpp */
