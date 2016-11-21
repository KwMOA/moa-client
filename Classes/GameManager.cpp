//
//  GameManager.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.h"

#include <iostream>


#include "GameDefines.h"
#include "ClientGamePacket.h"
#include "Building_1.h"
#include "Building_2.h"
#include "TaskManager.h"


#include "GameWorld.h"
#include "ClientInput.h"
#include "NetworkManager.h"

#include "BasicDefines.h"
#include "GameDefines.h"

#include "TaskManager.h"
#include "GameWorld.h"
#include "GameData.h"
#include "GameScene.h"

GameManager::GameManager(GameScene* _gameScene, bool _isAiMode)
{
    //이미지 캐슁해놓기
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("unit/unit_1.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("building/building.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("control_btn/control_btn.plist");
    
    
    //DOTO. set new Instance in NetworkHandler and TaskManager
    gameScene = _gameScene;
    aiMode = _isAiMode;

    taskManager = new TaskManager(this);
    gameWorld = new GameWorld(this);
    
    tempObjectNoCreator = 1;
    
    //TODO. if multi play, receive and set myIdex from Server
    
    myIndex = 0;
    
    //////////////////////////
}

bool GameManager::init()
{
    //test code - create
    
//    CreateBuildingCI* p3 = new CreateBuildingCI();
//    p3->objectType = OBJECT_TYPE_BUILDING_3;
//    taskManager->pushBackMessage(p3);
//    
//    
//    CreateBuildingCI* p6 = new CreateBuildingCI();
//    p6->objectType = OBJECT_TYPE_BUILDING_3;
//    taskManager->pushBackAITask(p6);
//    
    //////////////////////////////
    
    return true;
}

void GameManager::finishGame()
{
    std::cout<<"finish"<<std::endl;
//    LogMgr->Log("통신 두절");
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



