//
//  ActAttack.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef ActAttack_h
#define ActAttack_h

#include <stdio.h>

#include "Act.h"

class ActAttack : public Act
{
private:
    int atk;
    int atkSpeed;
    int atkLoadSpeed;
    int atkRange;
    
    
    int actPercent;
    
    int prevImage;
    int currentImage;
    
public:
    ActAttack(Unit* _unit);
    
    void update(int updateCount);
    
    ~ActAttack() {}

};

#endif /* ActAttack_h */
