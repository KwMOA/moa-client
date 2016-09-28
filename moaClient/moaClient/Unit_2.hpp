//
//  Unit_2.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_2_hpp
#define Unit_2_hpp


#include <stdio.h>
#include "Unit.hpp"

class Unit_2 : public Unit {
public:
    Unit_2();
    void click();
    void update(long dt);
};


#endif /* Unit_2_hpp */
