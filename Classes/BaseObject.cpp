//
//  BaseObject.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 28..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "BaseObject.h"
#include "GamePlayer.h"
#include "GameWorld.h"
#include "GameScene.h"

BaseObject::BaseObject(GamePlayer* _gamePlayer, int _objectType)
{
    gamePlayer = _gamePlayer;
    objectType = _objectType;
    
    objectLayer = Layer::create();
    objectLayer->retain();
    objectLayer->setPosition(Vec2(0,0));
//    objectLayer->setAnchorPoint(Vec2(0, 0));
//    gamePlayer->getGameWorld()->addChild(objectLayer);
}

void BaseObject::setX(int _x)
{
    px = x;
    x = _x;
    objectLayer->setPositionX(x);
    objectLayer->setLocalZOrder(gamePlayer->sameXPlayerIndex(x));
}
