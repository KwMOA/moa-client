//
//  GameDefines.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameDefines_h
#define GameDefines_h

#include <iostream>

const int INTERUPT_NETWORK_FRAME = 2;

enum OBJECT_TYPE
{
    OBJECT_TYPE_BUILDING_1,
};

enum OBJECT_STATE
{
    OBJECT_STATE_CREATEING,
    OBJECT_STATE_WORK,
    OBJECT_STATE_DESTROY,
    OBJECT_STATE_RUN,
    OBJECT_STATE_ATTACK,
    OBJECT_STATE_DEAD,
};

enum INFLUENCE_TYPE
{
    INFLUENCE_TYPE_ATTACK,
    INFLUENCE_TYPE_HEAL,
};

struct ObjectInfo
{
    int price;
    int cancel_price;
    int create_time;
};

struct Influence
{
    int objectNo;
    int influenceType;
    int damage;
};

#endif /* GameDefines_h */
