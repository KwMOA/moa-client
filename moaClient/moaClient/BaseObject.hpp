//
//  BaseObject.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 28..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef BaseObject_hpp
#define BaseObject_hpp

class GamePlayer;

class BaseObject {
protected:
    int objectNo;
    int objectType;
    int x, y, w, h;
    int state;
    
    GamePlayer* gamePlayer;
    
public:
    BaseObject(GamePlayer* _gamePlayer);
    
    virtual void click() = 0;
    virtual void update(long dt) = 0;
    
    
    int getObjectNo() { return objectNo; }
    void setObjectNo(int objectNo) { this->objectNo = objectNo; }
    
    int getObjectType() { return objectType; }
    void setObjectType(int objectType) { this->objectType = objectType; }
    
    int getState() { return state; }
    void setState(int state) { this->state = state; }
    
    GamePlayer* getGamePlayer() { return gamePlayer; }
    
};

#endif /* BaseObject_hpp */
