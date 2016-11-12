#ifndef __LOBBY_MAIN_LAYER_H__
#define __LOBBY_MAIN_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define MENU_BUTTON_WIDTH 120
#define MENU_BUTTON_HEIGHT 120

using namespace cocos2d::ui;

class LobbyMainLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    void clickGameBtn(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void clickChannelBtn(cocos2d::Ref* pSender);
    void clickFriendBtn(cocos2d::Ref* pSender);
    void clickClanBtn(cocos2d::Ref* pSender);
    void clickRankingBtn(cocos2d::Ref* pSender);
    void clickBoardBtn(cocos2d::Ref* pSender);
    
    CREATE_FUNC(LobbyMainLayer);
    
private:
    cocos2d::Menu* menu;
};

#endif //__LOBBY_MAIN_LAYER_H__
