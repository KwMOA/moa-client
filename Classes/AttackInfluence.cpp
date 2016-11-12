//
//  AttackInfluence.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "AttackInfluence.hpp"
#include "Unit.hpp"

void AttackInfluence::applyInfluence(Unit* unit)
{
    int finalDamage = damage - ((double)(damage * unit->getDef()) / 100);
    
    unit->setHp(unit->getHp() - finalDamage);
}
