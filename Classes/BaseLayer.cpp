#include "BaseLayer.h"
#include "NetworkManager.h"
#include "DefineHeader.h"
USING_NS_CC;

Scene* BaseLayer::createScene()
{
    auto scene = Scene::create();

	auto layer = BaseLayer::create();
	
	scene->addChild(layer, 0);

    return scene;
}

bool BaseLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
#ifndef NOT_CONNECT_WITH_SERVER
        scheduleUpdate();
#else

#endif
    
    return true;
}

void BaseLayer::update(float dt)
{
#ifndef NOT_CONNECT_WITH_SERVER
    int recvBytes = 0;
    while (1)
    {
        recvBytes = NetMgr->receiveData(SERVER_MODULE_FRONT_SERVER);
        if(recvBytes <= 0)
            break;
    }
    
    while (1)
    {
        recvBytes = NetMgr->receiveData(SERVER_MODULE_LOBBY_SERVER);
        if(recvBytes <= 0)
            break;
    }
    
    while (1)
    {
        recvBytes = NetMgr->receiveData(SERVER_MODULE_GAME_SERVER);
        if(recvBytes <= 0)
            break;
    }
    
    while (1)
    {
        recvBytes = NetMgr->receiveData(SERVER_MODULE_CHATTING_SERVER);
        if(recvBytes <= 0)
            break;
    }

#else

#endif
}

void BaseLayer::popLayer()
{
    if(layerStack.size() == 1) {
        return ;
    }
    
    Layer* layer = layerStack.front();
    layerStack.pop_front();
    
    removeChild(layer);
    
    layer = layerStack.front();
    
    Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(layer);
    
    addChild(layerStack.front(), (int)layerStack.size());
}


void BaseLayer::pushLayer(Layer* layer)
{
	if (layerStack.size() != 0) {
		Layer* oldLayer = layerStack.front();

		Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(oldLayer);
	
		layerStack.push_front(layer);


		if (layerStack.size() != 1) {
			removeChild(oldLayer);
		}
	}

	layerStack.push_front(layer);

    layer = layerStack.front();
    Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(layer);
    
    addChild(layerStack.front(), (int)layerStack.size());
}
