#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__

#include "BaseLayer.h"

class LoginLayer;
class CreateAccountLayer;

class LoginScene : public BaseLayer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
    void openCreateAccountLayer();
//    void closeCreateAccountLayer();
    void createAccountFail(int failReason);
    

	CREATE_FUNC(LoginScene);
    
private:
    cocos2d::Menu* menu;
    
    LoginLayer* loginLayer;
    CreateAccountLayer* createAccountLayer;
    
};

#endif //__FRONT_SCENE_H__
