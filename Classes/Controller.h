
#ifndef __CONTROL_LAYER_H__
#define __CONTROL_LAYER_H__

#include "cocos2d.h"
#include "BasicPacket.h"

USING_NS_CC;


class GameWorld;

class Controller
{
public:
    Controller(GameWorld* _gameWorld);
    virtual ~Controller() {};
    
public:
    virtual void completeCreateBuildingNotify(int objectType) = 0;
    virtual void completeUgradeNotify(int upgradeType, int upgradeCompleteNum) = 0;
    virtual void activeBuildingNotify(int objectType) = 0;
    virtual void activeUgradeNotify(int upgradeType, int upgradeCompleteNum) = 0;
    virtual void activeUnitNotify(int objectType) = 0;
    
    
    
protected:
    GameWorld* gameWorld;
    
};

#endif //__CONTROL_LAYER_H__
