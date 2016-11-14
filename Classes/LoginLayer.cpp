#include "LoginLayer.h"
#include "GameDefines.h"
#include "ClientFrontPacket.h"
#include "GameClient.h"
#include "CreateAccountLayer.h"
#include "MiniMapLayer.h"
#include "NetworkManager.h"

USING_NS_CC;

bool LoginLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto loginBtn = MenuItemImage::create(
		"login_btn_01.png",
		"login_btn_01.png",
		CC_CALLBACK_1(LoginLayer::clickLoginBtn, this));

	loginBtn->setPosition(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 4);
    
	menu = Menu::create(loginBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100, TAG_MENU);
    
    return true;
}

void LoginLayer::menuCloseCallback(Ref* pSender)
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

void LoginLayer::clickLoginBtn(Ref* pSender)
{
    menu->setEnabled(false); //TODO. erase and test
    std::string loginToken = UserDefault::getInstance()->getStringForKey("loginToken");

    if(loginToken.length() == 0)
    {
        char time[37] = {0, };
        memcpy(time, &GameClient::GetInstance().sessionId, 36);
        
        loginToken = std::string(time, 36);
        
        UserDefault::getInstance()->setStringForKey("loginToken", loginToken);
        
        loginToken = UserDefault::getInstance()->getStringForKey("loginToken");

    }

    CCLOG("not have id - %s %ld\n", loginToken.c_str(), loginToken.length());
#ifndef NOT_CONNECT_WITH_SERVER
	
    NetMgr->frontSendLoginReq(loginToken.c_str(), loginToken.length());
#else

#endif
}

