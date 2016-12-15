//
//  AiPlayer.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 7..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef __AI_PLAYER_H__
#define __AI_PLAYER_H__

#include <stdio.h>
#include "GamePlayer.h"

class AIPlayer :public GamePlayer
{
protected:
    int aiType;
    int currentTick;
    int testUnitCreateNum;
public:
    AIPlayer(GameWorld* _gameWorld, int _aiType, int _playerIndex);
    
    void update(int updateCount);
};

#endif /* __AI_PLAYER_H__ */
