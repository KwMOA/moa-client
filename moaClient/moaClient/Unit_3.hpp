//
//  Unit_3.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_3_hpp
#define Unit_3_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_3 : public Unit {
public:
    Unit_3(GamePlayer* _gamePlayer);
    ~Unit_3() {};
    void click();
    void update(long dt);
};

#endif /* Unit_3_hpp */
