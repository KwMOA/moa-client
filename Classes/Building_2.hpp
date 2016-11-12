//
//  Building_2.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_2_hpp
#define Building_2_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_2 : public Building {
private:
    int goldAquiredTime;

public:
    Building_2(GamePlayer* _gamePlayer);
    ~Building_2() {};
    void click();
    void update(long dt);
};

#endif /* Building_2_hpp */