//
//  Building_6.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_6_h
#define Building_6_h

#include <stdio.h>
#include "Building.h"

class Building_6 : public Building {
private:
    
public:
    Building_6(GamePlayer* _gamePlayer);
    ~Building_6() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_6_h */
