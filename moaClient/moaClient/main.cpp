//
//  main.cpp
//  moa
//
//  Created by kimyongchan on 2016. 9. 23..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.hpp"
#include "TaskManagerImpl.h"


int main(int argc, const char * argv[]) {
    
    GameManager::GetInstance();
    
    GameManager::GetInstance()->init();
    
    GameManager::GetInstance()->run();

		return 0;
}
