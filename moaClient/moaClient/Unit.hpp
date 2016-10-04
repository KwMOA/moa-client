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
#include "StaticObject.h"

class Unit : public BaseObject {
protected:
    StaticUnit* staticUnit;
    
    int hp;
    
    std::list<Influence*> lists;
public:
    Unit(GamePlayer* _gamePlayer, int _objectType);
    ~Unit() {}
    
    
    void setHp(int _hp) { hp = _hp; }
    int getHp() { return hp; }
    
    static Unit* createUnit(GamePlayer* _gamePlayer, int _objectType);
    
};
#endif /* Unit_hpp */
