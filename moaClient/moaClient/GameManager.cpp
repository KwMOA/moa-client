//
//  GameManager.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.hpp"

#include <iostream>

#if OS_PLATFORM == PLATFORM_LINUX
#include <sys/time.h>
#else
#include <windows.h>
#endif

#include "GameDefines.h"
#include "ClientGamePacket.h"
#include "Building_1.hpp"
#include "Building_2.hpp"
#include "TaskManagerImpl.h"


#include "NetworkHandlerImpl.hpp"
#include "GameLogicImpl.hpp"
#include "GameWorldImpl.hpp"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    //DOTO. set new Instance in NetworkHandler and TaskManager
    networkHandler = new NetworkHandlerImpl();

    taskManager = new TaskManagerImpl();
    gameLogic = new GameLogicImpl();
    gameWorld = new GameWorldImpl();
    
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
    
    ClientGamePacket::CreateBuildingResPacket* p1 = new ClientGamePacket::CreateBuildingResPacket();
    p1->objectType = OBJECT_TYPE_BUILDING_1;
    p1->isEnemy = 0;
    networkHandler->sendInput(p1);
    
    
    ClientGamePacket::CreateBuildingResPacket* p2 = new ClientGamePacket::CreateBuildingResPacket();
    p2->objectType = OBJECT_TYPE_BUILDING_2;
    p2->isEnemy = 0;
    
    networkHandler->sendInput(p2);
    
    ClientGamePacket::CreateBuildingResPacket* p3 = new ClientGamePacket::CreateBuildingResPacket();
    p3->objectType = OBJECT_TYPE_BUILDING_3;
    p3->isEnemy = 0;
    
    networkHandler->sendInput(p3);
    
    ClientGamePacket::CreateBuildingResPacket* p4 = new ClientGamePacket::CreateBuildingResPacket();
    p4->objectType = OBJECT_TYPE_BUILDING_4;
    p4->isEnemy = 0;
    
    networkHandler->sendInput(p4);
    
    ClientGamePacket::CreateBuildingResPacket* p5 = new ClientGamePacket::CreateBuildingResPacket();
    p5->objectType = OBJECT_TYPE_BUILDING_5;
    p5->isEnemy = 0;
    
    networkHandler->sendInput(p5);
    
    ClientGamePacket::CreateBuildingResPacket* p6 = new ClientGamePacket::CreateBuildingResPacket();
    p6->objectType = OBJECT_TYPE_BUILDING_6;
    p6->isEnemy = 0;
    
    networkHandler->sendInput(p6);
    
    ClientGamePacket::CreateBuildingResPacket* p7 = new ClientGamePacket::CreateBuildingResPacket();
    p7->objectType = OBJECT_TYPE_BUILDING_7;
    p7->isEnemy = 0;
    
    networkHandler->sendInput(p7);
    
    ClientGamePacket::CreateBuildingResPacket* p8 = new ClientGamePacket::CreateBuildingResPacket();
    p8->objectType = OBJECT_TYPE_BUILDING_8;
    p8->isEnemy = 0;
    
    networkHandler->sendInput(p8);
    
    ClientGamePacket::CreateBuildingResPacket* p9 = new ClientGamePacket::CreateBuildingResPacket();
    p9->objectType = OBJECT_TYPE_BUILDING_9;
    p9->isEnemy = 0;
    
    networkHandler->sendInput(p9);
    
    ClientGamePacket::CreateBuildingResPacket* p10 = new ClientGamePacket::CreateBuildingResPacket();
    p10->objectType = OBJECT_TYPE_BUILDING_10;
    p10->isEnemy = 0;
    
    networkHandler->sendInput(p10);
    
    
    ClientGamePacket::CreateBuildingResPacket* p11 = new ClientGamePacket::CreateBuildingResPacket();
    p11->objectType = OBJECT_TYPE_BUILDING_11;
    p11->isEnemy = 0;
    
    networkHandler->sendInput(p11);
    
    ClientGamePacket::CreateBuildingResPacket* p12 = new ClientGamePacket::CreateBuildingResPacket();
    p12->objectType = OBJECT_TYPE_BUILDING_12;
    p12->isEnemy = 0;
    
    networkHandler->sendInput(p12);
    
//    ClientGamePacket::CancelCreateBuildingResPacket* p = new ClientGamePacket::CancelCreateBuildingResPacket();
//    p->objectNo = 1;
//    p->isEnemy = 0;
//    
//    GameManager::GetInstance()->getNetworkHandler()->sendInput(p);
    
    //////////////////////////////
    
    return true;
}

void GameManager::run()
{
    
    long startTime = 0;
    
#if OS_PLATFORM == PLATFORM_LINUX
    
    struct timeval tp;
    gettimeofday(&tp, NULL);
    
    
    startTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;

#else
    
    SYSTEMTIME time;
    GetSystemTime(&time);
    startTime = (time.wSecond * 1000) + time.wMilliseconds;

#endif

    

    
    long currentTime = startTime;
    
    int netWorkCount = 0;
    int taskCount = 0;
    
    int networkFrame = 1;
    
    while(true) {
        
        //true if over 125 / 1000 second
        if((currentTime - startTime) - (taskCount * 125) >= 125) {
     
            //true if over 250 / 1000 second
            if(networkFrame == INTERUPT_NETWORK_FRAME) {
                networkHandler->update((currentTime - startTime) - (netWorkCount * 250));
                
                networkFrame = 1;
                netWorkCount++;
            } else {
                networkFrame++;
            }
            
            taskManager->update((currentTime - startTime) - (taskCount * 125));
            
            taskCount++;
        }
        
#if OS_PLATFORM == PLATFORM_LINUX
        
        gettimeofday(&tp, NULL);
        currentTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;

#else
        
        GetSystemTime(&time);
        currentTime = (time.wSecond * 1000) + time.wMilliseconds;
        
#endif
        
    }
}







