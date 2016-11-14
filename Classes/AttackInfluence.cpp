//
//  AttackInfluence.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "AttackInfluence.h"
#include "Unit.h"

void AttackInfluence::applyInfluence(Unit* unit)
{
    int finalDamage = damage - ((double)(damage * unit->getDef()) / 100);
    
    unit->setHp(unit->getHp() - finalDamage);
}
