//
//  ActAttack.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "ActAttack.h"
#include "Unit.h"
#include "GamePlayer.h"
#include "ActRun.h"
#include "AttackInfluence.h"

ActAttack::ActAttack(Unit* _unit) : Act(_unit, ACT_TYPE_ATTACK)
{
    atk = _unit->getAtk();
    atkSpeed = _unit->getAtkSpeed();
    atkLoadSpeed = _unit->getAtkLoadSpeed();
    atkRange = _unit->getAtkRange();
    
    actPercent = 0;
}



void ActAttack::update(int updateCount)
{
    actPercent++;
    
    //change Image
    if(actPercent == 1) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][0], 0, TAG_IMAGE_OBJECT);
    } else if(actPercent == atkSpeed / 3) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][1], 0, TAG_IMAGE_OBJECT);
    } else if(actPercent == (atkSpeed * 2) / 3) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][2], 0, TAG_IMAGE_OBJECT);
    } else if(actPercent  == atkSpeed) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][3], 0, TAG_IMAGE_OBJECT);
    } else if(actPercent== ((atkSpeed + atkLoadSpeed) / 2)) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][4], 0, TAG_IMAGE_OBJECT);
    } else if(actPercent == (atkSpeed + atkLoadSpeed)) {
        unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        unit->objectLayer->addChild(unit->images[2][5], 0, TAG_IMAGE_OBJECT);
    }
    
    
    
    if(actPercent <= atkSpeed) {
        
        Unit* otherUnit = unit->getTargaet();
        
        if(otherUnit == nullptr) {
            
            otherUnit = unit->checkEnemyInRange();
        
            if(otherUnit == nullptr) {
                
                flag = 1;
                
                return ;
                
            } else {
                unit->setTarget(otherUnit);
                otherUnit->setTargetList(unit);
            }
            
        } else {
            
            if(unit->isPossibleToAttack(otherUnit) == false) { // other unit is so far
                
                unit->setTarget(nullptr);
                otherUnit->removeTargetList(unit);
                
                otherUnit = unit->checkEnemyInRange();
                
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
            
        }
        
    } else if(actPercent == atkSpeed + atkLoadSpeed) { // attack finish
        
        if(unit->getTargaet() != nullptr) //if not dead targetUnit
        {
            actPercent = 0;
        } else {
            
            Unit* otherUnit = unit->checkEnemyInRange();
            
            if(otherUnit == nullptr) { // not exist to possible attacking emeny
                
                flag = 1;
                
            } else {
                
                unit->setTarget(otherUnit);
                otherUnit->setTargetList(unit);
                
                actPercent = 0;
            }
        }
    
    } else {
        
    }
}
