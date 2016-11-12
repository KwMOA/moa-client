#include "LobbyGameLayer.h"
#include "GameDefines.h"
#include "ClientFrontPacket.h"

#include "BasicDefines.h"
#include "GameClient.h"
#include "LobbyScene.h"
#include "NetworkManager.h"
USING_NS_CC;


bool LobbyGameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("In Play Button", "fonts/Marker Felt.ttf", 48);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    //scheduleUpdate();
    auto bg = Sprite::create("bg.png");
    bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    this->addChild(bg, 0);
    
    auto single = Label::createWithTTF("Single", "fonts/Marker Felt.ttf", 100);
    single->enableOutline(Color4B::RED, 2);
    auto multi = Label::createWithTTF("Multi", "fonts/Marker Felt.ttf", 100);
    multi->enableOutline(Color4B::BLUE, 2);
    
    auto single_m = MenuItemLabel::create(single, CC_CALLBACK_1(LobbyGameLayer::clickAIGame, this));
    single_m->setTag(1);
    auto multi_m = MenuItemLabel::create(multi, CC_CALLBACK_1(LobbyGameLayer::clickRankGame, this));
    multi_m->setTag(2);
    
    auto menu = Menu::create(single_m, multi_m, NULL);
    menu->alignItemsHorizontallyWithPadding(200);
    this->addChild(menu);
    
    auto exit = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 24);
    multi->enableOutline(Color4B::GRAY, 2);
    
    auto exit_m = MenuItemLabel::create(exit, CC_CALLBACK_1(LobbyGameLayer::clickBackBtn, this));
    exit_m->setTag(0);
    
    auto menu_exit = Menu::create(exit_m, NULL);
    
    menu_exit->setAnchorPoint(Vec2(0, 0));
    menu_exit->setPosition(Vec2(60, 680));
    this->addChild(menu_exit);
    
//    
//    
//    AIGame = MenuItemImage::create(
//                                   "ai_game_btn_01.png",
//                                   "ai_game_btn_01.png",
//                                   CC_CALLBACK_1(LobbyGameLayer::clickAIGame, this));
//    
//    rankGame = MenuItemImage::create(
//                                   "rank_game_btn_01.png",
//                                   "rank_game_btn_01.png",
//                                   CC_CALLBACK_1(LobbyGameLayer::clickRankGame, this));
//    
//    AIGame->setAnchorPoint(Vec2(0.5, 0.5));
//    rankGame->setAnchorPoint(Vec2(0.5, 0.5));
//    
//    
//    AIGame->setPosition(Vec2(DISPLAY_WIDTH / 4, (DISPLAY_HEIGHT - 100) / 2));
//    rankGame->setPosition(Vec2((DISPLAY_WIDTH / 4) * 3, (DISPLAY_HEIGHT - 100) / 2));
//
//    auto backBtn = MenuItemImage::create(
//                                         "cancel_btn_01.png",
//                                         "cancel_btn_01.png",
//                                         CC_CALLBACK_1(LobbyGameLayer::clickBackBtn, this));
//    
//    backBtn->setAnchorPoint(Vec2(0,0));
//    backBtn->setPosition(Vec2(100, DISPLAY_HEIGHT - 100));
//    
//    menu = Menu::create(AIGame, rankGame, backBtn, NULL);
//    menu->setAnchorPoint(Vec2::ZERO);
//    menu->setPosition(Vec2::ZERO);
//    
//    this->addChild(menu, 100, TAG_MENU);
//    
//    auto choose = Sprite::create("choose_tribe_btn.png");
//    choose->setAnchorPoint(Vec2::ZERO);
//    
    
    

//    tribeChina->addChild(choose, 0, 123);

    return true;
}

void LobbyGameLayer::menuCloseCallback(Ref* pSender)
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


void LobbyGameLayer::clickGameBtn(cocos2d::Ref* pSender)
{
//    NetMgr->frontSendFirstConnectReq();
    
}

void LobbyGameLayer::clickAIGame(cocos2d::Ref *pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_AI_GAME);
//    NetMgr->lobbySendQuickPlayReq(GameClient::GetInstance().tribe);
}

void LobbyGameLayer::clickRankGame(cocos2d::Ref *pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_RANK_GAME);
//    NetMgr->lobbySendQuickPlayReq(GameClient::GetInstance().tribe);
}

void LobbyGameLayer::clickBackBtn(cocos2d::Ref *pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->popLayer();
}


