#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "BaseLayer.h"

class GameManager;

class GameScene : public BaseLayer
{
private:
    GameManager* gameManager;
    
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

    void customUpdate(float dt);
    void networkUpdate(float dt);

	CREATE_FUNC(GameScene);

    
public:
    GameManager* getGameManager() { return gameManager; }
    
    
};

#endif 

