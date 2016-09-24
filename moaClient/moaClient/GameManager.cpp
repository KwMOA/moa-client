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

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    //DOTO. set new Instance in NetworkHandler and TaskManager
    networkHandler = new NetworkHandlerImpl();

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