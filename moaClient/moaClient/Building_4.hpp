//
//  Building_4.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_4_hpp
#define Building_4_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_4 : public Building {
private:

public:
    Building_4(GamePlayer* _gamePlayer);
    ~Building_4() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_4_hpp */
