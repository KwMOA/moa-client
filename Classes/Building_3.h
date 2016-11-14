//
//  Building_3.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_3_h
#define Building_3_h

#include <stdio.h>
#include "Building.h"

class Building_3 : public Building {
    
public:
    Building_3(GamePlayer* _gamePlayer);
    ~Building_3() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_3_h */
