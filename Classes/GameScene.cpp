#include "GameScene.h"

#include "GameDefines.h"

#include "GameManager.h"
#include "NetworkManager.h"
#include "TaskManager.h"
#include "GameWorld.h"
#include "ControlLayer.h"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = GameScene::create();
	
	scene->addChild(layer, 1, TAG_GAME_SCENE);

    return scene;
}

bool GameScene::init()
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    
    updateCount = 0;
    
    if(PLAY_ALONE) {
        gameManager = new GameManager(this, true);
    } else {
        gameManager = new GameManager(this, false);
    }
    
    
    if(gameManager->init() == false) {
        return false;
    }

    auto background = Sprite::create("game_back_ground_01.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0, 0));
    
    addChild(background, 0);
    
	ControlLayer* controlLayer = ControlLayer::create();
	controlLayer->setGameWorld(this);
	this->addChild(controlLayer);

    
    schedule(schedule_selector(GameScene::customUpdate), 0.125f);
    schedule(schedule_selector(GameScene::networkUpdate), 0.25f);
    
    
    return true;
}

void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameScene::customUpdate(float dt)
{
    updateCount++;
    gameManager->getGameWorld()->update(updateCount);
}

void GameScene::networkUpdate(float dt)
{
    gameManager->getTaskManager()->dispatchToServer();
    gameManager->getTaskManager()->carryOutMessages();
}




