#ifndef __INFO_LAYER_H__
#define __INFO_LAYER_H__

#include "cocos2d.h"
#include <string>

class StaticObject;
class BaseObject;
class StaticUnit;
class StaticBuilding;
class StaticUpgrade;
class InfoLayer : public cocos2d::Layer
{
private:
    
public:

	virtual bool init();
	void update(float dt);
    
    
    
    void setObjectInfo(int type, StaticObject* staticObject);
    void setBuildingInfo(StaticBuilding* staticBuilding);
    void setUnitInfo(StaticUnit* staticUnit);
    void setUpgradeInfo(StaticUpgrade* staticUpgrade);
    
    
    
    // implement the "static create()" method manually
	CREATE_FUNC(InfoLayer);
};

#endif // __INFO_LAYER_H__
