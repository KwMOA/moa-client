#include "GameScene.h"
#include "ResultLayer.h"
#include "GameDefines.h"

#include <string>

using namespace cocos2d::ui;
USING_NS_CC;

bool ResultLayer::init()
{
	
	if (!Layer::init())
	{
		return false;
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg = Sprite::create("bg_result.png");
    bg->setAnchorPoint(Vec2(0.5, 0.5));
    bg->setPosition(Vec2::ZERO);
    
    addChild(bg);
    
	return true;
}

void ResultLayer::setResult(GameScene* _gameScene, int result)
{
    if(result == 0) {
        auto label = Label::createWithTTF("WIN", "fonts/Marker Felt.ttf", 100);
        
        label->setAnchorPoint(Vec2(0.5, 0.5));
        label->setPosition(Vec2(0, 100));
        
        addChild(label);
    } else {
        auto label = Label::createWithTTF("LOSE", "fonts/Marker Felt.ttf", 100);
        
        label->setAnchorPoint(Vec2(0.5, 0.5));
        label->setPosition(Vec2(0, 100));
        
        addChild(label);
    }
    
    
    auto button = Button::create("result_out_btn.png");
    
    button->setAnchorPoint(Vec2(0.5, 0.5));
    button->setPosition(Vec2(0, -100));
    button->addTouchEventListener(CC_CALLBACK_2(GameScene::exitCallback, _gameScene));

    addChild(button);
    
    
}

