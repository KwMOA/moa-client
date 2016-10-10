//
//  ActAttack.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef ActAttack_hpp
#define ActAttack_hpp

#include <stdio.h>

#include "Act.hpp"

class ActAttack : public Act
{
private:
    int atk;
    int atkSpeed;
    int atkLoadSpeed;
    int atkRange;
    
    
    int actPercent;
    
    
public:
    ActAttack(Unit* _unit);
    
    void update(long dt);
    
    ~ActAttack() {}

};

#endif /* ActAttack_hpp */
