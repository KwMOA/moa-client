//
//  BaseObject.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 28..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "BaseObject.hpp"
#include "GamePlayer.hpp"

BaseObject::BaseObject(GamePlayer* _gamePlayer, int _objectType)
{
    gamePlayer = _gamePlayer;
    objectType = _objectType;
}