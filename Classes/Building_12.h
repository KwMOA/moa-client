//
//  Building_12.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_12_h
#define Building_12_h

#include <stdio.h>
#include "Building.h"

class Building_12 : public Building {
private:
    
public:
    Building_12(GamePlayer* _gamePlayer);
    ~Building_12() {};
    
    void click();
    void update(int updateCount);
};

#endif /* Building_12_h */
