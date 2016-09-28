//
//  Unit.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_hpp
#define Unit_hpp

#include <stdio.h>
#include <list>
#include "BaseObject.hpp"
#include "GameDefines.h"

class Unit : public BaseObject {
protected:
    int hp;
    int atk;
    int atkSpeed;
    int atkRange;
    int speed;
    int def;
    int isVisible;
    
    std::list<Influence*> lists;
public:
    Unit();
    ~Unit() {}
};
#endif /* Unit_hpp */
