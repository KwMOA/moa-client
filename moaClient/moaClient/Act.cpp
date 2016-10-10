//
//  Act.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 7..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Act.hpp"

#include "Unit.hpp"

Act::Act(Unit* _unit, int _actType)
{
    unit = _unit;
    actType = _actType;
    
    flag = 0;
}