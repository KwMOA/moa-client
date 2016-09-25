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

#include "TestTaskManager.hpp"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    //DOTO. set new Instance in NetworkHandler and TaskManager
    networkHandler = new NetworkHandlerImpl();
    taskManager = new TestTaskManager();
    
    
    gamePlayers[0] = new GamePlayer();
    gamePlayers[1] = new GamePlayer();
    
    tempObjectNoCreator = 1;
    
    
    
    //object info init (TODO. receive from json data)
    objectInfos[0].PRICE = 100;
    objectInfos[0].CANCEL_PRICE = 80;
    objectInfos[0].CREATE_TIME = 80;
    
    //////////////////////////
}

bool GameManager::init()
{
    
    // init - send request to create first building both player
    
    ClientGamePacket::CreateBuildingReqPacket* packet1 = new ClientGamePacket::CreateBuildingReqPacket();
    packet1->isEnemy = 0;
    packet1->objectType = OBJECT_TYPE_BUILDING_1;
    packet1->position = 1;
    
    ClientGamePacket::CreateBuildingReqPacket* packet2 = new ClientGamePacket::CreateBuildingReqPacket();
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
    
    
    while(true) {
        
        //true if over 250 / 1000 second
        if((currentTime - startTime) - (netWorkCount * 250) >= 250) {
            networkHandler->update((currentTime - startTime) - (netWorkCount * 250));
            
            netWorkCount++;
        }
        
        //true if over 500 / 1000 second
        if((currentTime - startTime) - (taskCount * 125) >= 125) {
            std::cout<<"task"<<std::endl;
            
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