//
//  Unit.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef Unit_hpp
#define Unit_hpp

#include <stdio.h>
#include <list>
#include "BaseObject.hpp"
#include "GameDefines.h"
#include "StaticObject.hpp"

class Act;
class Influence;

class Unit : public BaseObject {
protected:
    StaticUnit* staticUnit;
    int lineNo;
    int hp;
    
    std::list<Act*> actList;
    
    std::list<Influence*> influenceList;
    
    Unit* target;
    std::list<Unit*> targetList;
    
    int attackPercent;
    
public:
    Unit(GamePlayer* _gamePlayer, int _objectType);
    ~Unit() {}
    
    
    void setHp(int _hp) { hp = _hp; }
    int getHp() { return hp; }
    void setLineNo(int _lineNo) { lineNo = _lineNo; objectLayer->setPosition(Vec2(x, DISPLAY_HEIGHT - (_lineNo * 100))); }
    int getLineNo() { return lineNo; }
    
    
    static Unit* createUnit(GamePlayer* _gamePlayer, int _objectType);
    
    void update(long dt);
    void updateImage(Layer* layer) {}
    
    
    
    
    /////////////////////////////////////////////////// TODO. set with influence
    
    int getUnitType() { return staticUnit->getUnitType(); }
    
    std::string getName() { return staticUnit->getName(); }
    
    int getPrice() { return staticUnit->getPrice(); }
    
    int getWidth() { return staticUnit->getWidth(); }
    
    int getMaxHp() { return staticUnit->getMaxHp(); }
    
    int getAtk() { return staticUnit->getAtk(); }
    
    int getAtkSpeed() { return staticUnit->getAtkSpeed(); }
    
    int getAtkLoadSpeed() { return staticUnit->getAtkLoadSpeed(); }
    
    
    int getAtkRange() { return staticUnit->getAtkRange(); }
    
    int getSpeed() { return staticUnit->getSpeed(); }
    
    int getDef() { return staticUnit->getDef(); }
    
    int getIsVisible() { return staticUnit->getIsVisible(); }
    
    int getPopulation() { return staticUnit->getPopulation(); }
    
    ////////////////////////////////////////////////////
    
    void setTarget(Unit* _unit) { target = _unit; }
    Unit* getTargaet() { return target; }
    
    bool setTargetList(Unit* unit);
    void removeTargetList(Unit* _unit);
    
    void setInfluenceList(Influence* influence) { influenceList.push_back(influence); }
    void applyInfluence();
    
    void setActList(Act* act) { actList.push_front(act); }
  
    
    ////////////////////////
    
    void finishUnitDead();
};


#endif /* Unit_hpp */