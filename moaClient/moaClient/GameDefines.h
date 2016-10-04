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
    OBJECT_TYPE_BUILDING_1 = 1,
    OBJECT_TYPE_BUILDING_2,
    OBJECT_TYPE_BUILDING_3,
    OBJECT_TYPE_BUILDING_4,
    OBJECT_TYPE_BUILDING_5,
    OBJECT_TYPE_BUILDING_6,
    OBJECT_TYPE_BUILDING_7,
    OBJECT_TYPE_BUILDING_8,
    OBJECT_TYPE_BUILDING_9,
    OBJECT_TYPE_BUILDING_10,
    OBJECT_TYPE_BUILDING_11,
    OBJECT_TYPE_BUILDING_12,
    
    OBJECT_TYPE_UNIT_1,
    OBJECT_TYPE_UNIT_2,
    OBJECT_TYPE_UNIT_3,
    OBJECT_TYPE_UNIT_4,
    OBJECT_TYPE_UNIT_5,
    OBJECT_TYPE_UNIT_6,
    OBJECT_TYPE_UNIT_7,
    OBJECT_TYPE_UNIT_8,
    OBJECT_TYPE_UNIT_9,
    
};

enum OBJECT_STATE
{
    OBJECT_STATE_CREATEING = 1,
    OBJECT_STATE_IDLE,
    OBJECT_STATE_UPDATEING,
    OBJECT_STATE_CREATEING_UNIT,
    OBJECT_STATE_DESTROYING,
    OBJECT_STATE_DESTROY,
    
    
    OBJECT_STATE_RUN,
    OBJECT_STATE_ATTACK,
    OBJECT_STATE_DEAD,
};

enum UPGRADE_TYPE
{
    UPGRADE_TYPE_1 = 1,
    
    UPGRADE_TYPE_2,
    
    UPGRADE_TYPE_3, //7_1,
    UPGRADE_TYPE_4, //7_2,
    UPGRADE_TYPE_5, //7_3,
    
    
    UPGRADE_TYPE_6, //8_1,
    UPGRADE_TYPE_7, //8_2,
    UPGRADE_TYPE_8, //8_3,
    
    
    UPGRADE_TYPE_9, //9_1,
    UPGRADE_TYPE_10, //9_2,
    UPGRADE_TYPE_11, //9_3,
    UPGRADE_TYPE_12, //9_4,
    UPGRADE_TYPE_13, //9_5,
    UPGRADE_TYPE_14, //9_6,
    
    
    UPGRADE_TYPE_15, //10_1,
    UPGRADE_TYPE_16, //10_2,
    UPGRADE_TYPE_17, //10_3,
    UPGRADE_TYPE_18, //10_4,
    
    UPGRADE_TYPE_19, //11_1,
    UPGRADE_TYPE_20, //11_2,
    UPGRADE_TYPE_21, //11_3,
    
    UPGRADE_TYPE_22, //12_1,
    UPGRADE_TYPE_23, //12_2,
    UPGRADE_TYPE_24, //12_3,
    
};

enum INFLUENCE_TYPE
{
    INFLUENCE_TYPE_ATTACK = 1,
    INFLUENCE_TYPE_HEAL,
};


struct Influence
{
    int objectNo;
    int influenceType;
    int damage;
};

#endif /* GameDefines_h */
