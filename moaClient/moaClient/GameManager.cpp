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


#include "NetworkHandlerImpl.hpp"
#include "GameLogicImpl.hpp"
#include "GamePlayer.hpp"
#include "GameWorldImpl.hpp"
#include "TestTaskManager.hpp"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    //DOTO. set new Instance in NetworkHandler and TaskManager
    networkHandler = new NetworkHandlerImpl();
    taskManager = new TestTaskManager();
    gameLogic = new GameLogicImpl();
    gameWorld = new GameWorldImpl();
    
    tempObjectNoCreator = 1;
    
    
    
    //object info init (TODO. receive from json data)
    objectInfos[0].price = 100;
    objectInfos[0].cancel_price = 80;
    objectInfos[0].create_time = 80;
    
    //////////////////////////
}

bool GameManager::init()
{
    
    // init - send request to create first building both player
    
    ClientGamePacket::CreateBuildingResPacket* packet1 = new ClientGamePacket::CreateBuildingResPacket();
    packet1->isEnemy = 0;
    packet1->objectType = OBJECT_TYPE_BUILDING_1;
    packet1->position = 1;
    
    ClientGamePacket::CreateBuildingResPacket* packet2 = new ClientGamePacket::CreateBuildingResPacket();
    packet2->isEnemy = 1;
    packet2->objectType = OBJECT_TYPE_BUILDING_1;
    packet2->position = 1;
    
    networkHandler->sendInput(packet1);
    networkHandler->sendInput(packet2);
    
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