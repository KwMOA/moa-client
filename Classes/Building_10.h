//
//  Building_10.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_10_h
#define Building_10_h

#include <stdio.h>
#include "Building.h"

class Building_10 : public Building {
private:

public:
    Building_10(GamePlayer* _gamePlayer);
    ~Building_10() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_10_h */
