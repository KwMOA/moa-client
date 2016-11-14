//
//  Building_11.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_11_h
#define Building_11_h

#include <stdio.h>
#include "Building.h"

class Building_11 : public Building {
private:
public:
    Building_11(GamePlayer* _gamePlayer);
    ~Building_11() {};
    
    void click();
    void update(long dt);
};

#endif /* Building_11_h */
