//
//  Building_7.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_7_h
#define Building_7_h

#include <stdio.h>
#include "Building.h"

class Building_7 : public Building {
private:
    
    
public:
    Building_7(GamePlayer* _gamePlayer);
    ~Building_7() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_7_h */
