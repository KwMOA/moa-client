//
//  Building_3.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_3_hpp
#define Building_3_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_3 : public Building {
private:
    int testNum;
public:
    Building_3(GamePlayer* _gamePlayer);
    ~Building_3() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_3_hpp */
