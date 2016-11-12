//
//  GameData.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef GameData_h
#define GameData_h

#include "ObjectInfo.h"

class GameData {
public:
    virtual ObjectInfo* getObjectInfoByObjectType(int objectType) = 0;
};


#endif /* GameData_h */
