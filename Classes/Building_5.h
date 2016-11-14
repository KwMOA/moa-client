//
//  Building_1.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_5_h
#define Building_5_h

#include <stdio.h>
#include "Building.h"

class Building_5 : public Building {
private:
public:
    Building_5(GamePlayer* _gamePlayer);
    ~Building_5() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_5_h */
