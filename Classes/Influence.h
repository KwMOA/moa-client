//
//  Influence.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Influence_h
#define Influence_h

#include <stdio.h>

class Unit;

class Influence
{
protected:
    int objectNo;
    int actType;

public:
    virtual void applyInfluence(Unit* unit) = 0;
    
    
    void setObjectNo(int _objectNo) { objectNo = _objectNo; }
    int getObjectNo() { return objectNo; }
    
    void setActType(int _actType) { actType = _actType; }
    int getActType() { return actType; }
};

#endif /* Influence_h */
