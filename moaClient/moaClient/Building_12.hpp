//
//  Building_12.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_12_hpp
#define Building_12_hpp

#include <stdio.h>
#include "Building.hpp"

class Building_12 : public Building {
private:
    
public:
    Building_12(GamePlayer* _gamePlayer);
    ~Building_12() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_12_hpp */
