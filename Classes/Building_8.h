//
//  Building_8.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_8_h
#define Building_8_h

#include <stdio.h>
#include "Building.h"

class Building_8 : public Building {
private:
    
public:
    Building_8(GamePlayer* _gamePlayer);
    ~Building_8() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_8_h */
