//
//  Building_9.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_9_hpp
#define Building_9_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_9 : public Building {
private:

public:
    Building_9(GamePlayer* _gamePlayer);
    ~Building_9() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_9_hpp */
