#include "LoginScene.h"
//#include "BackGroundLayer.h"
#include "GameDefines.h"
#include "ClientFrontPacket.h"
#include "GameClient.h"
#include "CreateAccountLayer.h"
#include "MiniMapLayer.h"
#include "NetworkManager.h"
#include "LoginLayer.h"


const char* userId = "1232322";

USING_NS_CC;

Scene* LoginScene::createScene()
{
    auto scene = Scene::create();

	auto layer = LoginScene::create();
	
	scene->addChild(layer, 1, TAG_LOGIN_SCENE);

    return scene;
}

bool LoginScene::init()
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    
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
    
    loginLayer = LoginLayer::create();
    loginLayer->retain();
    
    createAccountLayer = CreateAccountLayer::create();
    createAccountLayer->retain();
    
    
    pushLayer(loginLayer);
    
    GameClient::GetInstance().currentScene = LOGIN_SCENE_NOW;
    
    return true;
}

void LoginScene::menuCloseCallback(Ref* pSender)
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

void LoginScene::openCreateAccountLayer()
{
    ((Menu*)loginLayer->getChildByTag(TAG_MENU))->setEnabled(true);
    
    createAccountLayer->setAnchorPoint(Vec2(0,0));
    createAccountLayer->setPosition(Vec2(0,0));
    
    pushLayer(createAccountLayer);
}

//void LoginScene::closeCreateAccountLayer()
//{
//    removeChildByTag(TAG_CREATE_ACCOUNT_LAYER, false);
//}


void LoginScene::createAccountFail(int failReason)
{
    CCLOG("caf");
}

