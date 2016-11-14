//
//  ActRun.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef ActRun_h
#define ActRun_h

#include <stdio.h>

#include "Act.h"

class ActRun : public Act
{
public:
    ActRun(Unit* _unit);
    
    void update(long dt);
    
    ~ActRun() {}
    
private:
    int runCount;
};

#endif /* ActRun_h */
