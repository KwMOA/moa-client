#include "LobbyAIGameLayer.h"
#include "GameDefines.h"
#include "ClientFrontPacket.h"

#include "BasicDefines.h"
#include "GameClient.h"
#include "LobbyScene.h"
#include "NetworkManager.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

bool LobbyAIGameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Single Play", "fonts/Marker Felt.ttf", 48);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    //scheduleUpdate();
    auto bg = Sprite::create("bg.png");
    bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    this->addChild(bg, 0);
    
    auto exit = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24);
    
    
    auto exit_m = MenuItemLabel::create(exit, CC_CALLBACK_1(LobbyAIGameLayer::clickBackBtn, this));
    exit_m->setTag(0);
    
    auto menu_exit = Menu::create(exit_m, NULL);
    
    menu_exit->setAnchorPoint(Vec2(0, 0));
    menu_exit->setPosition(Vec2(60, 680));
    this->addChild(menu_exit);
    
    // add the lable scroll view
    auto layer = LayerColor::create(Color4B::WHITE);
    layer->setContentSize(Size(200, 600));
    
    auto scroll = ScrollView::create();
    scroll->setInnerContainerSize(Size(600, 1200));
    scroll->setSize(Size(600, 600));
    scroll->setBackGroundImage("bg_list.png");
    
    scroll->setDirection(ScrollView::Direction::VERTICAL);
    scroll->setAnchorPoint(Vec2(0, 0));
    scroll->setPosition(Vec2(0, 0));
    
    this->addChild(scroll, 1);
//    
//    tribe1 = MenuItemImage::create(
//                                   "tribe_btn_1.png",
//                                       "tribe_btn_1.png",
//                                       CC_CALLBACK_1(LobbyAIGameLayer::clickTribe1, this));
//    
//    tribe2 = MenuItemImage::create(
//                                        "tribe_btn_2.png",
//                                        "tribe_btn_2.png",
//                                        CC_CALLBACK_1(LobbyAIGameLayer::clickTribe2, this));
//    
//    tribe3 = MenuItemImage::create(
//                                     "tribe_btn_3.png",
//                                     "tribe_btn_3.png",
//                                     CC_CALLBACK_1(LobbyAIGameLayer::clickTribe3, this));
//
//    
//    tribe1->setAnchorPoint(Vec2(0.5, 0.5));
//    tribe2->setAnchorPoint(Vec2(0.5, 0.5));
//    tribe3->setAnchorPoint(Vec2(0.5, 0.5));
//    
//    
//    tribe1->setPosition(Vec2(DISPLAY_WIDTH / 4, (DISPLAY_HEIGHT - 100) / 2));
//    tribe2->setPosition(Vec2((DISPLAY_WIDTH / 4) * 2, (DISPLAY_HEIGHT - 100) / 2));
//    tribe3->setPosition(Vec2((DISPLAY_WIDTH / 4) * 3, (DISPLAY_HEIGHT - 100) / 2));
//    
//    auto backBtn = MenuItemImage::create(
//                                         "cancel_btn_01.png",
//                                         "cancel_btn_01.png",
//                                         CC_CALLBACK_1(LobbyAIGameLayer::clickBackBtn, this));
//    
//    backBtn->setAnchorPoint(Vec2(0,0));
//    backBtn->setPosition(Vec2(100, DISPLAY_HEIGHT - 100));
//    
//    menu = Menu::create(tribe1, tribe2, tribe3, backBtn, NULL);
//    menu->setAnchorPoint(Vec2::ZERO);
//    menu->setPosition(Vec2::ZERO);
//    
//    this->addChild(menu, 100, TAG_MENU);
//    
//    GameClient::GetInstance().tribe = TRIBE_TYPE_CHINA;
//    
//    auto choose = Sprite::create("choose_tribe_btn.png");
//    choose->setAnchorPoint(Vec2::ZERO);
//    tribeChina->addChild(choose, 0, 123);

    return true;
}

void LobbyAIGameLayer::menuCloseCallback(Ref* pSender)
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


void LobbyAIGameLayer::clickTribe1(cocos2d::Ref* pSender)
{
    
}

void LobbyAIGameLayer::clickTribe2(cocos2d::Ref *pSender)
{

}

void LobbyAIGameLayer::clickTribe3(cocos2d::Ref *pSender)
{

}

void LobbyAIGameLayer::clickBackBtn(cocos2d::Ref *pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->popLayer();
}

