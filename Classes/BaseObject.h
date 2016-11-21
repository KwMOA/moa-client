//
//  BaseObject.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 28..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef BaseObject_h
#define BaseObject_h

#include <cocos2d.h>
#include "BasicDefines.h"
#include "GameDefines.h"

USING_NS_CC;

enum TAG_IMAGE
{
    TAG_IMAGE_OBJECT = 1,
    TAG_IMAGE_HP,
    TAG_IMAGE_UPGRADE_COUNT,
    TAG_IMAGE_COUNT,
    
};

class GamePlayer;

class BaseObject {
protected:
    int objectNo;
    int objectType;
    int x, y, px, py, w, h;
    int state;
    
    GamePlayer* gamePlayer;
    
public:
    BaseObject(GamePlayer* _gamePlayer, int _objectType);
    
    virtual void click() = 0;
    virtual void update(int updateCount) = 0;
    virtual void updateImage(Layer* layer) = 0;
    
    virtual ~BaseObject() {};
    
    
    int getObjectNo() { return objectNo; }
    void setObjectNo(int _objectNo) { objectNo = _objectNo; }
    
    int getObjectType() { return objectType; }
    void setObjectType(int _objectType) { objectType = _objectType; }
    
    int getState() { return state; }
    void setState(int _state);
    
    GamePlayer* getGamePlayer() { return gamePlayer; }
    void setGamePlayer(GamePlayer* _gamePlayer) { gamePlayer = _gamePlayer; }
    
    int getX() { return x; }
    void setX(int _x);
    
    int getPX() { return px; }
    void setPX(int _px) { px = _px; }
    
    int getY() { return y; }
    void setY(int _y) { y = _y; }
    
    int getW() { return w; }
    void setW(int _w) { w = _w; }
    
    int getH() { return h; }
    void setH(int _h) { h = _h; }
    
    
public:
    Sprite*** images;
    Sprite* hpBarBg;
    Sprite* hpBar;
    
    
    Layer* objectLayer;
};

#endif /* BaseObject_h */
