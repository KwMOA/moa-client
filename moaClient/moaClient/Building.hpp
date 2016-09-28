//
//  Building.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "BaseObject.hpp"

class Building : public BaseObject {
protected:
public:
    Building(GamePlayer* gamePlayer);
};

#endif /* Building_hpp */
