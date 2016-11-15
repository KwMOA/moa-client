//
//  ActRun.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 9..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "ActRun.h"
#include "Unit.h"
#include "GamePlayer.h"
#include "ActAttack.h"

ActRun::ActRun(Unit* _unit) : Act(_unit, ACT_TYPE_RUN)
{
    runCount = 0;
}



void ActRun::update(int updateCount)
{
    Unit* otherUnit = unit->checkEnemyInRange();
    
    if(otherUnit == nullptr) {

        //move unit
        unit->setPX(unit->getX());
        
        if(unit->getGamePlayer()->getPlayerIndex() == 0)
            unit->setX(unit->getX() + unit->getSpeed());
        else
            unit->setX(unit->getX() - unit->getSpeed());
        
        //change Image
        runCount++;
        if(runCount % 12 == 0) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][0], 0, TAG_IMAGE_OBJECT);
        } else if(runCount % 12 == 2) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][1], 0, TAG_IMAGE_OBJECT);
        } else if(runCount % 12 == 4) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][2], 0, TAG_IMAGE_OBJECT);
        } else if(runCount % 12 == 6) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][3], 0, TAG_IMAGE_OBJECT);
        } else if(runCount % 12 == 8) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][4], 0, TAG_IMAGE_OBJECT);
        } else if(runCount % 12 == 10) {
            unit->objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
            unit->objectLayer->addChild(unit->images[1][5], 0, TAG_IMAGE_OBJECT);
        }
        
        
    } else {
        
        unit->setTarget(otherUnit);
        otherUnit->setTargetList(unit);
        
        ActAttack* actAttack = new ActAttack(unit);
        unit->setActList(actAttack);
//        actAttack->update(updateCount);
        
        unit->setState(OBJECT_STATE_ATTACK);
    }
}
