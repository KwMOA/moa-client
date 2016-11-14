//
//  Act.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 7..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Act_h
#define Act_h

#include <stdio.h>
#include "GameDefines.h"

class Unit;

class Act
{
protected:
    int actType;
    
    Unit* unit;
    
    int flag; // set flag 1 if finish own work
    
public:
    Act(Unit* _unit, int _actType);
    
    int getActType() { return actType; }
    void setActType(int _actType) { actType = _actType; }
    int getFlag() { return flag; }
    virtual ~Act() {};

    
    virtual void update(long dt) = 0;
};

#endif /* Act_h */
