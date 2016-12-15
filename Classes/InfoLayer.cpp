#include "GameScene.h"
#include "InfoLayer.h"
#include "Unit.h"
#include "Building.h"
#include "Upgrade.h"
#include "StaticObject.h"
#include <string>

USING_NS_CC;

bool InfoLayer::init()
{
	
	if (!Layer::init())
	{
		return false;
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    


	return true;
}


void InfoLayer::update(float dt)
{
    
}

void InfoLayer::setObjectInfo(int buttonType, StaticObject* staticObject)
{
    removeAllChildren();
    
    switch (buttonType) {
        case BUTTON_TYPE_BUILDING:
            setBuildingInfo((StaticBuilding*)staticObject);
            break;
        case BUTTON_TYPE_UNIT:
            setUnitInfo((StaticUnit*)staticObject);
            break;
        case BUTTON_TYPE_UPGRADE:
            setUpgradeInfo((StaticUpgrade*)staticObject);
            break;
        default:
            break;
    }
}

void InfoLayer::setBuildingInfo(StaticBuilding* staticBuilding)
{
    Sprite* image = staticBuilding->getImage();
    
    addChild(image);
    
    std::string nameStr = "name : ";
    nameStr.append(staticBuilding->getName());
//    std::to_string(staticBuilding->getPrice());
    auto name = Label::createWithTTF(nameStr, "fonts/Marker Felt.ttf", 16);
    
    name->setAnchorPoint(Vec2(0, 0.5));
    name->setPosition(Vec2(120, 100));
    
    addChild(name);
    
    std::string priceStr = "price : ";
    priceStr += staticBuilding->getPrice();
    auto price = Label::createWithTTF(priceStr, "fonts/Marker Felt.ttf", 16);
    
    price->setAnchorPoint(Vec2(0, 0.5));
    price->setPosition(Vec2(120, 80));
    
    addChild(price);
    
    
}


void InfoLayer::setUnitInfo(StaticUnit* staticUnit)
{
    Sprite* image = staticUnit->getImage();
    
    addChild(image);
    
    std::string nameStr = "name : ";
    nameStr.append(staticUnit->getName());
    //    std::to_string(staticBuilding->getPrice());
    auto name = Label::createWithTTF(nameStr, "fonts/Marker Felt.ttf", 16);
    
    name->setAnchorPoint(Vec2(0, 0.5));
    name->setPosition(Vec2(120, 100));
    
    addChild(name);
    
    std::string priceStr = "price : ";
    priceStr += staticUnit->getPrice();
    auto price = Label::createWithTTF(priceStr, "fonts/Marker Felt.ttf", 16);
    
    price->setAnchorPoint(Vec2(0, 0.5));
    price->setPosition(Vec2(120, 80));
    
    addChild(price);
    
}


void InfoLayer::setUpgradeInfo(StaticUpgrade* staticUpgrade)
{
    Sprite* image = staticUpgrade->getImage();
    
    addChild(image);
    
    std::string nameStr = "name : ";
    nameStr.append(staticUpgrade->getName());
    //    std::to_string(staticBuilding->getPrice());
    auto name = Label::createWithTTF(nameStr, "fonts/Marker Felt.ttf", 16);
    
    name->setAnchorPoint(Vec2(0, 0.5));
    name->setPosition(Vec2(120, 100));
    
    addChild(name);
    
    std::string priceStr = "price : ";
    priceStr += staticUpgrade->getCompleteTimeArray()[staticUpgrade->upgrade->getUpgradeCount()].first;
    
    auto price = Label::createWithTTF(priceStr, "fonts/Marker Felt.ttf", 16);
    
    price->setAnchorPoint(Vec2(0, 0.5));
    price->setPosition(Vec2(120, 80));
    
    addChild(price);
    
}






