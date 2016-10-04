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
    
    Building_1* building1 = new Building_1(gameWorld->getGamePlayer(0));
    building1->setState(OBJECT_STATE_IDLE);
    Building_2* building2 = new Building_2(gameWorld->getGamePlayer(0));
    building2->setState(OBJECT_STATE_IDLE);
    
    gameWorld->getGamePlayer(0)->setBuilding(building1);
    gameWorld->getGamePlayer(0)->setBuilding(building2);
    
    
    Building_1* building3 = new Building_1(gameWorld->getGamePlayer(1));
    building3->setState(OBJECT_STATE_IDLE);
    
    Building_2* building4 = new Building_2(gameWorld->getGamePlayer(1));
    building4->setState(OBJECT_STATE_IDLE);
    
    
    gameWorld->getGamePlayer(1)->setBuilding(building3);
    gameWorld->getGamePlayer(1)->setBuilding(building4);
    
    
    
    
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







