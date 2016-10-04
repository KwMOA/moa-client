//
//  Building_11.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_11_hpp
#define Building_11_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_11 : public Building {
private:
public:
    Building_11(GamePlayer* _gamePlayer);
    ~Building_11() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_11_hpp */
