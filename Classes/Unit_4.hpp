//
//  Unit_4.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_4_hpp
#define Unit_4_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_4 : public Unit {
public:
    Unit_4(GamePlayer* _gamePlayer);
    ~Unit_4() {};
    void click();
    void update(long dt);
};

#endif /* Unit_4_hpp */
