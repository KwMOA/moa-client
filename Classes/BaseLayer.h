#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include "cocos2d.h"


class BaseLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void update(float dt);
//	CREATE_FUNC(BaseLayer);
    
    std::list<cocos2d::Layer*> layerStack;
    
    void popLayer();
    void pushLayer(Layer* layer);

};

#endif //__BASE_LAYER_H__
