#include "GameScene.h"

#include "GameDefines.h"

#include "GameManager.hpp"
#include "NetworkManager.h"
#include "TaskManager.h"
#include "GameLogic.h"
#include "GameWorldImpl.hpp"
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
    
    gameManager = new GameManager(this, true);
    
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
    
//	auto loginBtn = MenuItemImage::create(
//		"login_btn_01.png",
//		"login_btn_01.png",
//		CC_CALLBACK_1(LoginScene::clickLoginBtn, this));
//
//	loginBtn->setPosition(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 4);
//    
//	menu = Menu::create(loginBtn, NULL);
//	menu->setPosition(Vec2::ZERO);
//	this->addChild(menu, 100, TAG_MENU);
//    
//    createAccountLayer = CreateAccountLayer::create();
//    createAccountLayer->retain();
//    
//    GameClient::GetInstance().currentScene = LOGIN_SCENE_NOW;
    
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
    ((GameWorldImpl*)gameManager->getGameWorld())->update(dt);
}

void GameScene::networkUpdate(float dt)
{
    gameManager->getTaskManager()->dispatchToServer();
    gameManager->getTaskManager()->carryOutMessages();
}




