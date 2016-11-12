//
//  AttackInfluence.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef AttackInfluence_hpp
#define AttackInfluence_hpp

#include <stdio.h>
#include "Influence.hpp"

class AttackInfluence : public Influence
{
protected:
    int damage;
    
public:
    
    void applyInfluence(Unit* unit) override;
    
    
    
    void setDamage(int _damage) { damage = _damage; }
    int getDamage() { return damage; }
};


#endif /* AttackInfluence_hpp */
