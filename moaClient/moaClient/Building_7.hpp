//
//  Building_7.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_7_hpp
#define Building_7_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_7 : public Building {
private:
    
    
public:
    Building_7(GamePlayer* _gamePlayer);
    ~Building_7() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_7_hpp */
