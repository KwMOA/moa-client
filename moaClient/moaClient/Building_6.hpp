//
//  Building_6.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_6_hpp
#define Building_6_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_6 : public Building {
private:
    
public:
    Building_6(GamePlayer* _gamePlayer);
    ~Building_6() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_6_hpp */
