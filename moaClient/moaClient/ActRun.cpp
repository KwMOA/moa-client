//
//  ActRun.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "ActRun.hpp"
#include "Unit.hpp"
#include "GamePlayer.hpp"
#include "ActAttack.hpp"

ActRun::ActRun(Unit* _unit) : Act(_unit, ACT_TYPE_RUN)
{
    
}



void ActRun::update(long dt)
{
    Unit* otherUnit = unit->getGamePlayer()->checkEnemyInRange(unit->getLineNo(), unit->getX(), unit->getWidth(), unit->getAtkRange());
    
    if(otherUnit == nullptr) {

        //move unit
        
        unit->setX(unit->getX() + unit->getSpeed());
        
    } else {
        
        unit->setTarget(otherUnit);
        otherUnit->setTargetList(unit);
        
        ActAttack* actAttack = new ActAttack(unit);
        unit->setActList(actAttack);
//        actAttack->update(dt);
        
        unit->setState(OBJECT_STATE_ATTACK);
    }
}