//
//  GameManager.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.hpp"

#include <iostream>


#include "GameDefines.h"
#include "ClientGamePacket.h"
#include "Building_1.hpp"
#include "Building_2.hpp"
#include "TaskManager.h"


#include "GameLogicImpl.hpp"
#include "GameWorldImpl.hpp"
#include "ClientInput.h"
#include "NetworkManager.h"

#include "BasicDefines.h"
#include "GameDefines.h"

#include "TaskManager.h"
#include "GameLogic.h"
#include "GameWorld.h"
#include "GameData.h"
#include "GameScene.h"

GameManager::GameManager(GameScene* _gameScene, bool _isAiMode)
{
    //이미지 캐슁해놓기
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("unit/unit_1.plist");
    
    //DOTO. set new Instance in NetworkHandler and TaskManager
    gameScene = _gameScene;
    aiMode = _isAiMode;

    taskManager = new TaskManager(this);
    gameLogic = new GameLogicImpl(this);
    gameWorld = new GameWorldImpl(this);
    
    tempObjectNoCreator = 1;
    
    //TODO. if multi play, receive and set myIdex from Server
    
    myIndex = 0;
    
    //////////////////////////
}

bool GameManager::init()
{
    // init - set first building both player
    
//    Building_1* building1 = new Building_1(gameWorld->getGamePlayer(0));
//    building1->setState(OBJECT_STATE_IDLE);
//    Building_2* building2 = new Building_2(gameWorld->getGamePlayer(0));
//    building2->setState(OBJECT_STATE_IDLE);
//    
//    gameWorld->getGamePlayer(0)->setBuilding(building1);
//    gameWorld->getGamePlayer(0)->setBuilding(building2);
//    
//    
//    Building_1* building3 = new Building_1(gameWorld->getGamePlayer(1));
//    building3->setState(OBJECT_STATE_IDLE);
//    
//    Building_2* building4 = new Building_2(gameWorld->getGamePlayer(1));
//    building4->setState(OBJECT_STATE_IDLE);
//    
//    
//    gameWorld->getGamePlayer(1)->setBuilding(building3);
//    gameWorld->getGamePlayer(1)->setBuilding(building4);
    
    
    //test code - create
    
    
    CreateBuildingCI* p3 = new CreateBuildingCI();
    p3->objectType = OBJECT_TYPE_BUILDING_3;
    taskManager->pushBackMessage(p3);
    
    
    CreateBuildingCI* p6 = new CreateBuildingCI();
    p6->objectType = OBJECT_TYPE_BUILDING_3;
    taskManager->pushBackAITask(p6);
    
    
    
//    ClientGamePacket::CancelCreateBuildingResPacket* p = new ClientGamePacket::CancelCreateBuildingResPacket();
//    p->objectNo = 1;
//    p->isEnemy = 0;
//    
//    GameManager::GetInstance()->getNetworkHandler()->sendInput(p);
    
    //////////////////////////////
    
    return true;
}


//
void GameManager::run()
{
//
//    long startTime = 0;
//    
//#if OS_PLATFORM == PLATFORM_LINUX
//    
//    struct timeval tp;
//    gettimeofday(&tp, NULL);
//    
//    
//    startTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
//
//#else
//    
//    SYSTEMTIME time;
//    GetSystemTime(&time);
//    startTime = (time.wSecond * 1000) + time.wMilliseconds;
//
//#endif
//
//    
//
//    
//    long currentTime = startTime;
//    
//    int netWorkCount = 0;
//    int taskCount = 0;
//    
//    int networkFrame = 1;
//    
//    while(true) {
//        
//        //true if over 125 / 1000 second
//        if((currentTime - startTime) - (taskCount * 125) >= 125) {
//     
//            //true if over 250 / 1000 second
//            if(networkFrame == INTERUPT_NETWORK_FRAME) {
//                networkHandler->update((currentTime - startTime) - (netWorkCount * 250));
//                
//                networkFrame = 1;
//                netWorkCount++;
//            } else {
//                networkFrame++;
//            }
//            
//            taskManager->update((currentTime - startTime) - (taskCount * 125));
//            
//            taskCount++;
//        }
//        
//#if OS_PLATFORM == PLATFORM_LINUX
//        
//        gettimeofday(&tp, NULL);
//        currentTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
//
//#else
//        
//        GetSystemTime(&time);
//        currentTime = (time.wSecond * 1000) + time.wMilliseconds;
//        
//#endif
//        
//    }
}
//
//

void GameManager::finishGame()
{
    std::cout<<"finish"<<std::endl;
}



