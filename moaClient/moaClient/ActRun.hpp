//
//  ActRun.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef ActRun_hpp
#define ActRun_hpp

#include <stdio.h>

#include "Act.hpp"

class ActRun : public Act
{
public:
    ActRun(Unit* _unit);
    
    void update(long dt);
    
    ~ActRun() {}
};

#endif /* ActRun_hpp */
