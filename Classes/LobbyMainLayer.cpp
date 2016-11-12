#include "LobbyMainLayer.h"
#include "GameDefines.h"

#include "BasicDefines.h"
#include "LobbyScene.h"

USING_NS_CC;
using namespace cocos2d::ui;

bool LobbyMainLayer::init()
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
    
    auto label = Label::createWithTTF("Master of Ace", "fonts/Marker Felt.ttf", 48);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    //scheduleUpdate();
    auto bg = Sprite::create("bg.png");
    bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    this->addChild(bg, 0);
    
    
    auto playButton = Button::create("play.png", "play_pressed.png", "play_pressed.png");
    
    playButton->addTouchEventListener(CC_CALLBACK_2(LobbyMainLayer::clickGameBtn, this));
    playButton->setAnchorPoint(Vec2(0.5, 0.5));
    playButton->setPosition(Vec2(DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) - 50));
    this->addChild(playButton, 1);
//    
//    auto gameBtn = MenuItemImage::create(
//                                         "menu_game_btn_01.png",
//                                         "menu_game_btn_02.png",
//                                         CC_CALLBACK_1(LobbyMainLayer::clickGameBtn, this));
//    
//    gameBtn->setAnchorPoint(Vec2(0,0));
//    gameBtn->setPosition(0, 0);
//    
//    auto channelBtn = MenuItemImage::create(
//                                            "menu_channel_btn_01.png",
//                                            "menu_channel_btn_02.png",
//                                            CC_CALLBACK_1(LobbyMainLayer::clickChannelBtn, this));
//    
//    channelBtn->setAnchorPoint(Vec2(0,0));
//    channelBtn->setPosition(((DISPLAY_WIDTH - MENU_BUTTON_WIDTH) / 5), 0);
//    
//    auto friendBtn = MenuItemImage::create(
//                                           "menu_friend_btn_01.png",
//                                           "menu_friend_btn_02.png",
//                                           CC_CALLBACK_1(LobbyMainLayer::clickFriendBtn, this));
//    
//    friendBtn->setAnchorPoint(Vec2(0,0));
//    friendBtn->setPosition(((DISPLAY_WIDTH - MENU_BUTTON_WIDTH) / 5) * 2, 0);
//    
//    auto clanBtn = MenuItemImage::create(
//                                         "menu_clan_btn_01.png",
//                                         "menu_clan_btn_02.png",
//                                         CC_CALLBACK_1(LobbyMainLayer::clickClanBtn, this));
//    
//    clanBtn->setAnchorPoint(Vec2(0,0));
//    clanBtn->setPosition(((DISPLAY_WIDTH - MENU_BUTTON_WIDTH) / 5) * 3, 0);
//    
//    auto rankingBtn = MenuItemImage::create(
//                                            "menu_ranking_btn_01.png",
//                                            "menu_ranking_btn_02.png",
//                                            CC_CALLBACK_1(LobbyMainLayer::clickRankingBtn, this));
//    
//    rankingBtn->setAnchorPoint(Vec2(0,0));
//    rankingBtn->setPosition(((DISPLAY_WIDTH - MENU_BUTTON_WIDTH) / 5) * 4, 0);
//    
//    auto boardBtn = MenuItemImage::create(
//                                          "menu_board_btn_01.png",
//                                          "menu_board_btn_02.png",
//                                          CC_CALLBACK_1(LobbyMainLayer::clickBoardBtn, this));
//    
//    boardBtn->setAnchorPoint(Vec2(0,0));
//    boardBtn->setPosition((DISPLAY_WIDTH - MENU_BUTTON_WIDTH), 0);
//    
//    menu = Menu::create(gameBtn, channelBtn, friendBtn, clanBtn, rankingBtn, boardBtn, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 100, TAG_MENU);
//    
    return true;
}

void LobbyMainLayer::menuCloseCallback(Ref* pSender)
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


void LobbyMainLayer::clickGameBtn(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_GAME);
    }
}


void LobbyMainLayer::clickChannelBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_CHANNEL);
}


void LobbyMainLayer::clickFriendBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_FRIEND);
}


void LobbyMainLayer::clickClanBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_CLAN);
}


void LobbyMainLayer::clickRankingBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_RANKING);
}


void LobbyMainLayer::clickBoardBtn(cocos2d::Ref* pSender)
{
    ((LobbyScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOBBY_SCENE))->changeLobbyLayer(CURRENT_LAYER_BOARD);
}

