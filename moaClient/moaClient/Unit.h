//
//  Unit.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_h
#define Unit_h

#include <stdio.h>
#include <list>
#include "BaseObject.h"
#include "GameDefines.h"

class Unit : public BaseObject {
protected:
    int hp;
    int atk;
    int atkSpeed;
    int atkRange;
    int speend;
    int def;
    int isVisible;
    
    std::list<Influence*> lists;
public:
    
};


#endif /* Unit_h */
