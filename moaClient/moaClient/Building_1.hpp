//
//  Building_1.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_1_hpp
#define Building_1_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_1 : public Building {
private:
    int quantity;
    
public:
    Building_1();
    void click();
    void update(long dt);
};

#endif /* Building_1_hpp */
