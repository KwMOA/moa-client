//
//  Unit.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit.h"
#include "GamePlayer.h"
#include "Unit_1.h"
#include "Unit_2.h"
#include "Unit_3.h"
#include "Unit_4.h"
#include "Unit_5.h"
#include "Unit_6.h"
#include "Unit_7.h"
#include "Unit_8.h"
#include "Unit_9.h"

#include "Act.h"
#include "ActRun.h"
#include "Influence.h"
#include "GameWorld.h"
#include <string>

Unit::Unit(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_RUN;
    staticUnit = gamePlayer->getStaticUnitByUnitType(_objectType);
    attackPercent = 0;
    
    x = gamePlayer->sameXPlayerIndex(150);
    
    px = x;
    
    
    hp = staticUnit->getMaxHp();
    
    
    
    
    //set image
    
    
    //direction
    char direction[6] = {0, };
    
    getDirectionByIndex(direction);
    
    
    //////////////////////////
    
    
    
    
    images = new Sprite**[3];
    
    
    char buf[128];
    
    images[0] = new Sprite*[1];
    for(int i = 0; i < 1; i++) {
        
        memset(buf, 0, 128);
        sprintf(buf, "%s_%s_idle_%d.png", staticUnit->getName(), direction, i + 1);
        
        images[0][i] = Sprite::createWithSpriteFrameName(buf);
        images[0][i]->retain();
        
        images[0][i]->setAnchorPoint(Vec2(0.5, 0));
    }
    
    images[1] = new Sprite*[staticUnit->getRunImageCount()];
    for(int i = 0; i < staticUnit->getRunImageCount(); i++) {
        memset(buf, 0, 128);
        sprintf(buf, "%s_%s_run_%d.png", staticUnit->getName(), direction, i + 1);
        
        images[1][i] = Sprite::createWithSpriteFrameName(buf);
        images[1][i]->retain();
        
        
        
        images[1][i]->setAnchorPoint(Vec2(0.5, 0));
    }
    
    
    images[2] = new Sprite*[staticUnit->getAttackImageCount()];
    for(int i = 0; i < staticUnit->getAttackImageCount(); i++) {
        memset(buf, 0, 128);
        sprintf(buf, "%s_%s_attack_%d.png", staticUnit->getName(), direction, i + 1);
        images[2][i] = Sprite::createWithSpriteFrameName(buf);
        images[2][i]->retain();
        
        images[2][i]->setAnchorPoint(Vec2(0.5, 0));
    }
    
    
    //hp bar
    hpBarBg = Sprite::create("hp_bar_bg.png");
    hpBarBg->setPosition(Vec2(0, -10));
    hpBarBg->setAnchorPoint(Vec2(0.5,0));
    
    hpBarBg->setScale(0.5, 0.5);
    objectLayer->addChild(hpBarBg);
    
    hpBar = Sprite::create("hp_bar.png");
    hpBar->setPosition(Vec2(-(hpBarBg->getContentSize().width / 4), -10));
    hpBar->setAnchorPoint(Vec2(0,0));
    hpBar->setScale(0.5, 0.5);
    objectLayer->addChild(hpBar);
    
    
    ActRun* act = new ActRun(this);
    actList.push_back(act);

}

Unit* Unit::createUnit(GamePlayer* _gamePlayer, int _objectType)
{
    switch (_objectType) {
        case OBJECT_TYPE_UNIT_1:
            return new Unit_1(_gamePlayer);
        case OBJECT_TYPE_UNIT_2:
            return new Unit_2(_gamePlayer);
        case OBJECT_TYPE_UNIT_3:
            return new Unit_3(_gamePlayer);
        case OBJECT_TYPE_UNIT_4:
            return new Unit_4(_gamePlayer);
        case OBJECT_TYPE_UNIT_5:
            return new Unit_5(_gamePlayer);
        case OBJECT_TYPE_UNIT_6:
            return new Unit_6(_gamePlayer);
        case OBJECT_TYPE_UNIT_7:
            return new Unit_7(_gamePlayer);
        case OBJECT_TYPE_UNIT_8:
            return new Unit_8(_gamePlayer);
        case OBJECT_TYPE_UNIT_9:
            return new Unit_9(_gamePlayer);
        default:
            return nullptr;
    }
}

void Unit::update(long dt)
{
    Act* act = actList.front();
    
    act->update(dt);
    
    int flag = act->getFlag();
    
    if(flag == 1) { // finish work
        actList.pop_front();
        
        delete act;
    }
}


bool Unit::setTargetList(Unit* unit)
{
    targetList.push_back(unit);
    
    return true;
}


void Unit::removeTargetList(Unit* _unit)
{
    std::list<Unit*>::iterator targetListItr;
    
    for(targetListItr = targetList.begin(); targetListItr != targetList.end(); targetListItr++) {
        
        if(*targetListItr == _unit) {
            targetList.erase(targetListItr);
            
            return ;
        }
    }
    
    std::cout<<"not exist unit"<<std::endl;
}

void Unit::applyInfluence()
{
    std::list<Influence*>::iterator influenceListItr;
    
    //TODO. change other class for sorting influence
    
    for(influenceListItr = influenceList.begin(); influenceListItr != influenceList.end(); influenceListItr++) {
        
        influenceList.front()->applyInfluence(this);
    }
    
    //죽었을시
    if(hp <= 0) {
        state = OBJECT_STATE_DEAD;
        
        std::list<Unit*>::iterator itr;
        
        for(itr = targetList.begin(); itr != targetList.end(); itr++) {
            Unit* unit = *itr;
            unit->removeTargetList(this);
        }
        //메모리 해제
        
        
        //
        auto deadAni = Animation::create();
        deadAni->setDelayPerUnit(0.2);
        auto cache = SpriteFrameCache::getInstance();
        
        char buf[128];
        
        char direction[6] = {0, };
        getDirectionByIndex(direction);
        
        for(int i = 0; i < staticUnit->getDeathImageCount(); i++) {
            memset(buf, 0, 128);
            sprintf(buf, "%s_%s_death_%d.png", staticUnit->getName(), direction, i + 1);
            
            deadAni->addSpriteFrame(cache->getSpriteFrameByName(buf));
        }
        
        
        auto deathAni = Animate::create(deadAni);
        
        auto cbSound = CallFunc::create( CC_CALLBACK_0(Unit::finishUnitDead, this) );
        
        
        auto sequence = Sequence::create(deathAni, cbSound, NULL);
        
        images[0][0]->runAction(sequence);
        
        objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        objectLayer->addChild(images[0][0], 0, TAG_IMAGE_OBJECT);
    }
    
    influenceList.clear();
}

void Unit::finishUnitDead()
{
    gamePlayer->getGameWorld()->removeChild(this);
}

void Unit::getDirectionByIndex(char *direction)
{
    if(getGamePlayer()->getPlayerIndex() == 0)
        memcpy(direction, "right", 5);
    else
        memcpy(direction, "left", 4);
}




bool Unit::isPossibleToAttack(Unit* otherUnit)
{
    if(otherUnit->getIsVisible() == false) {
        return false;
    } else if(getGamePlayer()->getPlayerIndex() == 0) {
        return ((otherUnit->getX() - otherUnit->getWidth()) - (getX() + getWidth()) < getAtkRange());
    } else {
        return ((getX() - getWidth()) - (otherUnit->getX() + otherUnit->getWidth()) < getAtkRange());
    }
}

Unit* Unit::checkEnemyInRange()
{
    GamePlayer* otherPlayer;
    
    if(gamePlayer->getPlayerIndex() == 0) {
    
        otherPlayer = gamePlayer->getGameWorld()->getGamePlayer(1);
        
    } else {
        
        otherPlayer = gamePlayer->getGameWorld()->getGamePlayer(0);
        
    }
    
    return otherPlayer->getBestCloseUnit(this);
}
