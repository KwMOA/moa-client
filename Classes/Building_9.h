//
//  Building_9.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_9_h
#define Building_9_h

#include <stdio.h>
#include "Building.h"

class Building_9 : public Building {
private:

public:
    Building_9(GamePlayer* _gamePlayer);
    ~Building_9() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_9_h */
