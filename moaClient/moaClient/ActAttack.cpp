//
//  ActAttack.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "ActAttack.hpp"
#include "Unit.hpp"
#include "GamePlayer.hpp"
#include "ActRun.hpp"
#include "AttackInfluence.hpp"

ActAttack::ActAttack(Unit* _unit) : Act(_unit, ACT_TYPE_ATTACK)
{
    atk = _unit->getAtk();
    atkSpeed = _unit->getAtkSpeed();
    atkLoadSpeed = _unit->getAtkLoadSpeed();
    atkRange = _unit->getAtkRange();
    
    actPercent = 0;
}



void ActAttack::update(long dt)
{
    actPercent++;
    
    if(actPercent <= atkSpeed) {
        
        Unit* otherUnit = unit->getTargaet();
        
        if(otherUnit == nullptr) {
            
            otherUnit = unit->getGamePlayer()->checkEnemyInRange(unit->getLineNo(), unit->getX(), unit->getWidth(), unit->getAtkRange());
        
            if(otherUnit == nullptr) {
                
                flag = 1;
                
                return ;
                
            } else {
                unit->setTarget(otherUnit);
                otherUnit->setTargetList(unit);
            }
            
        } else {
            if((otherUnit->getX() - otherUnit->getWidth()) - (unit->getX() + unit->getWidth()) > unit->getAtkRange()) { // other unit is so far
                
                unit->setTarget(nullptr);
                otherUnit->removeTargetList(unit);
                
                otherUnit = unit->getGamePlayer()->checkEnemyInRange(unit->getLineNo(), unit->getX(), unit->getWidth(), unit->getAtkRange());
                
                if(otherUnit == nullptr) {
                    
                    flag = 1;
                    
                    return ;
                    
                } else {
                    unit->setTarget(otherUnit);
                    otherUnit->setTargetList(unit);
                }
                
            }
        }
        
        if(actPercent == atkSpeed) { // attack
            
            AttackInfluence* influence = new AttackInfluence();
            influence->setObjectNo(unit->getObjectNo());
            influence->setActType(ACT_TYPE_ATTACK);
            influence->setDamage(atk);
            
            otherUnit->setInfluenceList(influence);
            
            unit->setTarget(nullptr);
            otherUnit->removeTargetList(unit);
        }
        
    } else if(actPercent == atkSpeed + atkLoadSpeed) { // attack finish
        
        flag = 1;
        
        return ;
    
    } else {
        
    }
}
