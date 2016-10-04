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
    BaseObject(GamePlayer* _gamePlayer, int _objectType);
    
    virtual void click() = 0;
    virtual void update(long dt) = 0;
    virtual ~BaseObject() {};
    
    
    int getObjectNo() { return objectNo; }
    void setObjectNo(int _objectNo) { objectNo = _objectNo; }
    
    int getObjectType() { return objectType; }
    void setObjectType(int _objectType) { objectType = _objectType; }
    
    int getState() { return state; }
    void setState(int _state) { state = _state; }
    
    GamePlayer* getGamePlayer() { return gamePlayer; }
    void setGamePlayer(GamePlayer* _gamePlayer) { gamePlayer = _gamePlayer; }
    
};

#endif /* BaseObject_hpp */
