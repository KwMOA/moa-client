//
//  GameDefines.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 25..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameDefines_h
#define GameDefines_h

const int INTERUPT_NETWORK_FRAME = 2;

enum OBJECT_TYPE
{
    OBJECT_TYPE_BUILDING_1,
};

struct ObjectInfo
{
    int PRICE;
    int CANCEL_PRICE;
    int CREATE_TIME;
};

enum INFLUENCE_TYPE
{
    INFLUENCE_TYPE_ATTACK,
    INFLUENCE_TYPE_HEAL,
};

struct Influence
{
    int objectNo;
    int influenceType;
    int damage;
};

#endif /* GameDefines_h */
