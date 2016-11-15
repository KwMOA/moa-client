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
#include "BasicDefines.h"

#define MENU_BUTTON_LAYER_Y 0
#define MENU_BUTTON_LAYER_HEIGHT 120
#define MY_INFO_LAYER_Y (DISPLAY_HEIGHT - 150)
#define MY_INFO_LAYER_HEIGHT 150
#define LOBBY_LAYER_Y MENU_BUTTON_LAYER_HEIGHT
#define LOBBY_LAYER_HEIGHT (DISPLAY_HEIGHT - MY_INFO_LAYER_HEIGHT - MENU_BUTTON_LAYER_HEIGHT)

#define MAP_WIDTH 1408

enum LAYER_TAG
{
    TAG_NETWORK_LAYER = 1,
    TAG_HELLO_WORLD_SCENE,
    TAG_LOGIN_SCENE,
    TAG_CREATE_ACCOUNT_LAYER,
    TAG_SIGN_UP_LAYER,
    TAG_FRONT_SCENE, //
    TAG_LOBBY_SCENE,
    TAG_MENU_BUTTON_LAYER,
    TAG_MY_INFO_LAYER,
    TAG_LOBBY_MAIN_LAYER,
    TAG_LOBBY_GAME_LAYER,
    TAG_LOBBY_CHANNEL_LAYER,
    TAG_LOBBY_FRIEND_LAYER,
    TAG_LOBBY_CLAN_LAYER,
    TAG_LOBBY_RANKING_LAYER,
    TAG_LOBBY_BOARD_LAYER,
    
    
    
    
    TAG_RESULT_SCENE,
    TAG_ROOM_SCENE,
    TAG_GAME_SCENE,
    TAG_POP_UP,
    TAG_MENU,
    TAG_CHANNEL_LIST_LAYER,
    TAG_USER_LIST_LAYER,
    TAG_USER_INFO_LAYER,
    TAG_ROOM_LIST_LAYER,
    TAG_MAKE_ROOM_LAYER,
    TAG_REQUEST_LIST_LAYER,
    TAG_SELETION_LAYER,
    TAG_FIND_ROOM_LAYER,
    TAG_QUICK_PLAY_LAYER,
    
};

enum CurrentScene
{
    HELLO_WORLD_SCENE_NOW = 1,
    LOGIN_SCENE_NOW,
    LOBBY_SCENE_NOW,
    ROOM_SCENE_NOW,
    GAME_SCENE_NOW,
    RESULT_SCENE_NOW,
    NO_SCENE_NOW,
};

const int INTERUPT_NETWORK_FRAME = 2;
const int UNIT_START_X[2] = {150, 1250};

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
    OBJECT_STATE_CREATING = 1,
    OBJECT_STATE_IDLE,
    OBJECT_STATE_UPGRADING,
    OBJECT_STATE_CREATING_UNIT,
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

enum ACT_TYPE
{
    ACT_TYPE_RUN = 1,
    ACT_TYPE_ATTACK,
    ACT_TYPE_LOAD,
    ACT_TYPE_HEAL,
};

enum BUTTON_TYPE {
	BUTTON_TYPE_BUILDING = 1,
	BUTTON_TYPE_UNIT,
	BUTTON_TYPE_UPGRADE,
};

enum BUTTON_STATE
{
	BUTTON_STATE_NONE = 1,
	BUTTON_STATE_ACTIVE,
	BUTTON_STATE_BUILDING,
	BUTTON_STATE_IDLE,
	BUTTON_STATE_CREATING,
	BUTTON_STATE_RESEARCHING,
};
const int WIDTH = 1280;
const int HEIGHT = 720;



#endif /* GameDefines_h */
