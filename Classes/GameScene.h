#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "BaseLayer.h"

class GameManager;
class ObjectInfoList;

class GameScene : public BaseLayer
{
private:
    GameManager* gameManager;
//	ObjectInfoList* objectInfoList;
    
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

    void customUpdate(float dt);
    void networkUpdate(float dt);

	CREATE_FUNC(GameScene);

    int updateCount;
    
public:
    GameManager* getGameManager() { return gameManager; }
//	ObjectInfoList* getObjectInfoList() { return objectInfoList; }
    
};

#endif 

