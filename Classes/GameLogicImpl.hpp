//
//  GameLogic.hpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameLogic_hpp
#define GameLogic_hpp

#include "GameLogic.h"

class GameManager;

class GameLogicImpl : public GameLogic
{
private:
    GameManager* gameManager;
    
public:
    GameLogicImpl(GameManager* _gameManager);
    void update(long dt);
};

#endif /* GameLogic_hpp */
