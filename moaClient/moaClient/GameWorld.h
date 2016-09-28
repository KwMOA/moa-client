//
//  GameWorld.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 26..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameWorld_h
#define GameWorld_h

class GamePlayer;

class GameWorld {
public:
    virtual void checkState() = 0;
    virtual void actState() = 0;
    virtual void applyInfluence() = 0;
    
    virtual GamePlayer* getGamePlayer(int index) = 0;
};


#endif /* GameWorld_h */
