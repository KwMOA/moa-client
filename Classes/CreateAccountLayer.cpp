#include "CreateAccountLayer.h"
#include "GameDefines.h"
#include "ClientFrontPacket.h"

#include "BasicDefines.h"
#include "GameClient.h"
#include "UserListLayer.h"
#include "LoginScene.h"
#include "NetworkManager.h"
USING_NS_CC;


bool CreateAccountLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    editbox = cocos2d::ui::EditBox::create(Size(300, 80), Scale9Sprite::create("typefield_01.png"));
    editbox->setAnchorPoint(Vec2(0.5,0.5));
    editbox->setPosition(Vec2(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2));
    editbox->setPlaceHolder("NICKNAME");                        //처음 보여주는 문자열
    editbox->setMaxLength(50);                                //최대로 입력받을수 잇는 문자의 길이
    editbox->setPlaceholderFontColor(Color3B::WHITE);        //문자열 색변경
    editbox->setFontColor(Color3B::BLACK);                    //입력한 문자열 색변경
    editbox->setReturnType(EditBox::KeyboardReturnType::SEARCH);
    editbox->setInputMode(EditBox::InputMode::ANY);

    this->addChild(editbox);
    
    
    okBtn = MenuItemImage::create(
                                       "create_account_btn_01.png",
                                       "create_account_btn_01.png",
                                       CC_CALLBACK_1(CreateAccountLayer::clickOkBtn, this));
    
    cancelBtn = MenuItemImage::create(
                                        "create_account_cancel_btn_01.png",
                                        "create_account_cancel_btn_01.png",
                                        CC_CALLBACK_1(CreateAccountLayer::clickCancelBtn, this));
    
    okBtn->setAnchorPoint(Vec2(1, 0.5));
    cancelBtn->setAnchorPoint(Vec2(0, 0.5));
    
    
    okBtn->setPosition(Vec2((DISPLAY_WIDTH / 2) - 50, DISPLAY_HEIGHT / 3));
    cancelBtn->setPosition(Vec2((DISPLAY_WIDTH / 2) + 50, DISPLAY_HEIGHT / 3));

    menu = Menu::create(okBtn, cancelBtn, NULL);
    menu->setAnchorPoint(Vec2::ZERO);
    menu->setPosition(Vec2::ZERO);
    
    this->addChild(menu, 100, TAG_MENU);

    return true;
}

void CreateAccountLayer::menuCloseCallback(Ref* pSender)
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


void CreateAccountLayer::clickOkBtn(cocos2d::Ref* pSender)
{
    CCLOG("clickOkBtn");
    
    menu->setEnabled(false);
    
    const char* text = editbox->getText();
    
    std::string loginToken = UserDefault::getInstance()->getStringForKey("loginToken");
    
    if(loginToken.length() == 0)
    {
        exit(0);
    }
        

    NetMgr->frontSendCreateAccountReq(loginToken.c_str(), loginToken.length(), text, strlen(text));
}



void CreateAccountLayer::clickCancelBtn(cocos2d::Ref *pSender)
{
    CCLOG("clickChattingSendBtn");
    
    editbox->setText("");
    
    ((LoginScene*)Director::getInstance()->getRunningScene()->getChildByTag(TAG_LOGIN_SCENE))->popLayer();
}

//
//void LobbyChannelLayer::notifyChatting(char* nickName, int nickNameLen, char* chatting, int chattingLen)
//{
//    std::string nickNameStr(nickName, nickNameLen);
//    std::string chattingStr(chatting, chattingLen);
//    
//    
//    char chattingBuffer[300];
//    memset(chattingBuffer, 0, 300);
//    
//    sprintf(chattingBuffer, "[%s] : %s", nickNameStr.c_str(), chattingStr.c_str());
//    
//    for(int i = 0; i < 19; i++)
//    {
//        auto chattingLabel = scrollView->getChildByTag(indexToTagNum(i));
//        chattingLabel->setPosition(Vec2(0, 40 * (i + 1)));
//
//    }
//    
//    Label* chattingLabel = (Label*)scrollView->getChildByTag(indexToTagNum(19));
//    chattingLabel->setPosition(Vec2(0, 0));
//    
//    chattingLabel->setString(std::string(chattingBuffer));
//    
//    
//    rotateCount--;
//    if(rotateCount == 0)
//        rotateCount = 20;
//}
//
//int LobbyChannelLayer::indexToTagNum(int i)
//{
//    return ((rotateCount + i) % 20);
//}

void CreateAccountLayer::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
    CCLOG("editBoxEditingDidBegin");
    
}


void CreateAccountLayer::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
    CCLOG("editBoxEditingDidBegin");
    clickOkBtn(this);

}


void CreateAccountLayer::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
    CCLOG("editBoxTextChanged");

    clickOkBtn(this);
}


void CreateAccountLayer::editBoxReturn(cocos2d::ui::EditBox* editBox)
{
    CCLOG("editBoxReturn");

}


