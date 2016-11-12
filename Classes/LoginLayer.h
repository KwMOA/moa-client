#ifndef __LOGIN_LAYER_H__
#define __LOGIN_LAYER_H__

#include "cocos2d.h"

class LoginLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
	void clickLoginBtn(cocos2d::Ref* pSender);
    
	CREATE_FUNC(LoginLayer);
    
private:
    cocos2d::Menu* menu;
};

#endif //__LOGIN_LAYER_H__
