//
//  Building_1.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_5_hpp
#define Building_5_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_5 : public Building {
private:
public:
    Building_5(GamePlayer* _gamePlayer);
    ~Building_5() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_5_hpp */