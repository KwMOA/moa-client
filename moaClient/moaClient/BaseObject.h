//
//  BaseObject.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef BaseObject_h
#define BaseObject_h

#include "ObjectState.h"

class BaseObject {
protected:
    int objectNo;
    int objectType;
    int x, y, w, h;
    int state;
    
public:
    virtual void click() = 0;
    virtual void update(long dt) = 0;
    
    
    int getObjectNo() { return objectNo; }
    void setObjectNo(int objectNo) { this->objectNo = objectNo; }
    
    int getObjectType() { return objectType; }
    void setObjectType(int objectType) { this->objectType = objectType; }
    
    int getState() { return state; }
    void setState(int state) { this->state = state; }
    
};

#endif /* BaseObject_h */
