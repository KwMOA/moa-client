#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "BaseLayer.h"
#include "ui/CocosGUI.h"

class GameManager;
class ObjectInfoList;
class TopLayer;
class ControlLayer;
class InfoLayer;
class ResultLayer;
class GameScene : public BaseLayer
{
private:
    GameManager* gameManager;
    TopLayer* topLayer;
    ControlLayer* controlLayer;
    InfoLayer* infoLayer;
    ResultLayer* resultLayer;
//	ObjectInfoList* objectInfoList;
    
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

    void customUpdate(float dt);
    void networkUpdate(float dt);

	CREATE_FUNC(GameScene);

    int updateCount;
    
    void exitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void setResult(int result);
public:
    GameManager* getGameManager() { return gameManager; }
    TopLayer* getTopLayer() { return topLayer; }
    ControlLayer* getControlLayer() { return controlLayer; }
//	ObjectInfoList* getObjectInfoList() { return objectInfoList; }
    
};

#endif 

