//
//  Unit.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "Unit.hpp"
#include "GamePlayer.hpp"
#include "Unit_1.hpp"
#include "Unit_2.hpp"
#include "Unit_3.hpp"
#include "Unit_4.hpp"
#include "Unit_5.hpp"
#include "Unit_6.hpp"
#include "Unit_7.hpp"
#include "Unit_8.hpp"
#include "Unit_9.hpp"

#include "Act.hpp"
#include "Influence.hpp"
#include "GameWorldImpl.hpp"

Unit::Unit(GamePlayer* _gamePlayer, int _objectType) : BaseObject(_gamePlayer, _objectType)
{
    state = OBJECT_STATE_RUN;
    staticUnit = gamePlayer->getStaticUnitByUnitType(_objectType);
    attackPercent = 0;
    
    if(getGamePlayer()->getPlayerIndex() == 0)
        x = UNIT_START_X[getGamePlayer()->getPlayerIndex()];
    else
        x = UNIT_START_X[getGamePlayer()->getPlayerIndex()];
    
    px = x;
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
    std::cout<<"x - "<<x<< ", y - "<<DISPLAY_HEIGHT - (lineNo * 100)<<std::endl;
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
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_1.png"));
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_2.png"));
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_3.png"));
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_4.png"));
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_5.png"));
        deadAni->addSpriteFrame(cache->getSpriteFrameByName("unit_1_death_6.png"));
        
        auto deathAni = Animate::create(deadAni);
        
        auto cbSound = CallFunc::create( CC_CALLBACK_0(Unit::finishUnitDead, this) );
        
        
        auto sequence = Sequence::create(deathAni, cbSound, NULL);
        
        images[3][0]->runAction(sequence);
        
        objectLayer->removeChildByTag(TAG_IMAGE_OBJECT);
        objectLayer->addChild(images[3][0], 0, TAG_IMAGE_OBJECT);
    }
    
    influenceList.clear();
}

void Unit::finishUnitDead()
{
    ((GameWorldImpl*)gamePlayer->getGameWorld())->removeChild(this);
}
