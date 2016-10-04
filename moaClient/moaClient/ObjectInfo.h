//
//  ObjectInfo.h
//  moaClient
//
//  Created by kimyongchan on 2016. 9. 29..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef ObjectInfo_h
#define ObjectInfo_h

class ObjectInfo {
protected:
    int objectType;
    
public:
    ObjectInfo(int _objectType) { objectType = _objectType; }
};

#endif /* ObjectInfo_h */
