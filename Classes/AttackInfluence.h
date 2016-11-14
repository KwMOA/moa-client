//
//  AttackInfluence.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef AttackInfluence_h
#define AttackInfluence_h

#include <stdio.h>
#include "Influence.h"

class AttackInfluence : public Influence
{
protected:
    int damage;
    
public:
    
    void applyInfluence(Unit* unit) override;
    
    
    
    void setDamage(int _damage) { damage = _damage; }
    int getDamage() { return damage; }
};


#endif /* AttackInfluence_h */
