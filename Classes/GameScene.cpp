#include "GameScene.h"

#include "GameDefines.h"

#include "GameManager.hpp"
#include "NetworkManager.h"
#include "TaskManager.h"
#include "GameLogic.h"
#include "GameWorldImpl.hpp"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = GameScene::create();
	
	scene->addChild(layer, 1, TAG_GAME_SCENE);

    return scene;
}

bool GameScene::init()
{
    if ( !BaseLayer::init() )
    {
        return false;
    }
    
    gameManager = new GameManager(this, true);
    
    if(gameManager->init() == false) {
        return false;
    }
    
    auto background = Sprite::create("game_back_ground_01.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0, 0));
    
    addChild(background, 0);
    
    auto button1 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button1->setAnchorPoint(Vec2(0.5, 0));
    button1->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 1 + 80, 0));
    
    button1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button1);
    
    auto button2 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button2->setAnchorPoint(Vec2(0.5, 0));
    button2->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 2 + 80, 0));
    
    button2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button2);
    
    auto button3 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button3->setAnchorPoint(Vec2(0.5, 0));
    button3->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 3 + 80, 0));
    
    button3->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button3);
    
    auto button4 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button4->setAnchorPoint(Vec2(0.5, 0));
    button4->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 4 + 80, 0));
    
    button4->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button4);
    
    auto button5 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button5->setAnchorPoint(Vec2(0.5, 0));
    button5->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 5 + 80, 0));
    
    button5->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button5);
    
    auto button6 = Button::create("game_control_btn_01.png", "game_control_btn_02.png", "game_control_btn_02.png");
    
    button6->setAnchorPoint(Vec2(0.5, 0));
    button6->setPosition(Vec2(((DISPLAY_WIDTH - 160) / 7) * 6 + 80, 0));
    
    button6->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(button6);
    
    auto leftButton = Button::create("game_control_left_btn_01.png", "game_control_left_btn_02.png", "game_control_left_btn_02.png");
    
    leftButton->setAnchorPoint(Vec2(0, 0));
    leftButton->setPosition(Vec2(0, 0));
    
    leftButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(leftButton);
    
    auto rightButton = Button::create("game_control_right_btn_01.png", "game_control_right_btn_02.png", "game_control_right_btn_02.png");
    
    rightButton->setAnchorPoint(Vec2(0, 0));
    rightButton->setPosition(Vec2(DISPLAY_WIDTH - 80, 0));
    
    rightButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    this->addChild(rightButton);
    
    
    
//	auto loginBtn = MenuItemImage::create(
//		"login_btn_01.png",
//		"login_btn_01.png",
//		CC_CALLBACK_1(LoginScene::clickLoginBtn, this));
//
//	loginBtn->setPosition(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 4);
//    
//	menu = Menu::create(loginBtn, NULL);
//	menu->setPosition(Vec2::ZERO);
//	this->addChild(menu, 100, TAG_MENU);
//    
//    createAccountLayer = CreateAccountLayer::create();
//    createAccountLayer->retain();
//    
//    GameClient::GetInstance().currentScene = LOGIN_SCENE_NOW;
    
    schedule(schedule_selector(GameScene::customUpdate), 0.125f);
    schedule(schedule_selector(GameScene::networkUpdate), 0.25f);
    
    
    return true;
}

void GameScene::menuCloseCallback(Ref* pSender)
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

void GameScene::customUpdate(float dt)
{
    ((GameWorldImpl*)gameManager->getGameWorld())->update(dt);
}

void GameScene::networkUpdate(float dt)
{
    gameManager->getTaskManager()->dispatchToServer();
    gameManager->getTaskManager()->carryOutMessages();
}




