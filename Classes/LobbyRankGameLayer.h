#ifndef __LOBBY_RANK_GAME_LAYER_H__
#define __LOBBY_RANK_GAME_LAYER_H__

#include "cocos2d.h"

class LobbyRankGameLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void clickTribe1(cocos2d::Ref* pSender);
    void clickTribe2(cocos2d::Ref* pSender);
    void clickTribe3(cocos2d::Ref* pSender);

    void clickBackBtn(cocos2d::Ref *pSender);

	CREATE_FUNC(LobbyRankGameLayer);
    
private:
    cocos2d::Menu* menu;
    
    cocos2d::MenuItemImage* tribe1;
    cocos2d::MenuItemImage* tribe2;
    cocos2d::MenuItemImage* tribe3;
};

#endif //__LOBBY_RANK_GAME_LAYER_H__
