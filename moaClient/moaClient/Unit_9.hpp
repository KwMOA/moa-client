//
//  Unit_9.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_9_hpp
#define Unit_9_hpp

#include <stdio.h>
#include "Unit.hpp"

class Unit_9 : public Unit {
public:
    Unit_9(GamePlayer* _gamePlayer);
    ~Unit_9() {};
    void click();
    void update(long dt);
};

#endif /* Unit_9_hpp */
