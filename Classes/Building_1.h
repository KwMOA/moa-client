//
//  Building_1.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_1_h
#define Building_1_h

#include <stdio.h>
#include "Building.h"


class Building_1 : public Building {
private:
    
public:
    Building_1(GamePlayer* _gamePlayer);
    ~Building_1() {};
    
    void click();
    void update(long dt);
    void updateImage(Layer* layer);
    
};

#endif /* Building_1_h */
