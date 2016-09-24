//
//  GameManager.cpp
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 24..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.hpp"

#include <iostream>
#include <sys/time.h>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
    //DOTO. set new Instance in NetworkHandler and TaskManager
    networkHandler = new NetworkHandlerImpl();

}

void GameManager::run()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    
    long startTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    
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
        
        
        
        gettimeofday(&tp, NULL);
        currentTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    }
}