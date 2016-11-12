#include "MenuButtonLayer.h"
#include "GameDefines.h"

#include "BasicDefines.h"
#include "LobbyScene.h"

USING_NS_CC;


bool MenuButtonLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto backBtn = MenuItemImage::create(
                                         "CloseNormal.png",
                                         "CloseSelected.png",
                                         CC_CALLBACK_1(MenuButtonLayer::clickBackBtn, this));
    
    backBtn->setAnchorPoint(Vec2(0,0));
    backBtn->setPosition(0, DISPLAY_HEIGHT - 100);
    
	menu = Menu::create(backBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100, TAG_MENU);

    return true;
}

void MenuButtonLayer::menuCloseCallback(Ref* pSender)
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


void MenuButtonLayer::clickBackBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_MAIN);
}
