//
//  Unit_5.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_5_hpp
#define Unit_5_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_5 : public Unit {
public:
    Unit_5(GamePlayer* _gamePlayer);
    ~Unit_5() {};
    void click();
    void update(long dt);
};

#endif /* Unit_5_hpp */
