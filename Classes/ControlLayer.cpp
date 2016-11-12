#include "GameScene.h"
#include "ControlLayer.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "LinkedList.h"
#include "CustomButton.h"
#include "ObjectInfos.h"
#include <string>

USING_NS_CC;

using namespace cocos2d::ui;


//Unit Controll this callback

bool ControlLayer::init()
{
	
	if (!Layer::init())
	{
		return false;
	}

	list = LinkedList<CustomButton*>();
	itr = LinkedList<CustomButton*>::iterator();
	layerLength = 0;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	moveLayer = Layer::create();
	//Bottom menu gui

	auto BottomBackground = Sprite::create("bg_bottom.png");
	BottomBackground->setPosition(Vec2(0, 0));
	BottomBackground->setAnchorPoint(Vec2(0, 0));

	auto buttonLeft = CustomButton::create("cursor.png", "cursor_pressed.png", "cursor_pressed.png");
	auto buttonRight = CustomButton::create("cursor.png", "cursor_pressed.png", "cursor_pressed.png");

	buttonLeft->setAnchorPoint(Vec2(0, 0));
	buttonLeft->setPosition(Vec2(0, 0));
	buttonRight->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	buttonRight->setPosition(Vec2(WIDTH, 0));

	BottomBackground->addChild(buttonRight, 1);
	BottomBackground->addChild(buttonLeft, 1);

	//Create begin Basic Building count now just 10 after change it !!!!!!!!!!!!!
	for (buttonCount = 0; buttonCount < 10; buttonCount++) {
		makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount);
	}
	//Change this area to change main building button



	layerLength = list.list_length();

	for (itr = list.begin(); itr != NULL; itr++) {
		moveLayer->addChild(itr.getData());
	}

	moveLayer->setAnchorPoint(Vec2(0, 0));
	moveLayer->setPosition(Vec2(120, 0));
	BottomBackground->addChild(moveLayer, 0);
	this->addChild(BottomBackground);

	buttonLeft->addTouchEventListener(CC_CALLBACK_2(ControlLayer::enterCallback, this));
	buttonLeft->setTag(1);
	buttonRight->addTouchEventListener(CC_CALLBACK_2(ControlLayer::enterCallback, this));
	buttonRight->setTag(2);

	return true;
}

void ControlLayer::DetailUnitCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
{

	list.getClickedBuilding();
	list.getClickedUnit();

	CustomButton* item = (CustomButton*)pSender;
	switch (item->getTag()) {

		//create unit
	case 0:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) { 
			
		}
		break;
		//cancle create unit
	case 1:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			
		}
		break;



	//this is line 1, 2, 3 
	case 2:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			
		}
		break;
	case 3:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			
		}
		break;
	case 4:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			
		}
		break;
	}

}









//Upgrade controll this callback

void ControlLayer::DetailUpgradeCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
{
	list.getClickedBuilding();
	list.getClickedUpgrade();
	
	list.getFront()->loadTextures("unit.png", "unit.png", "unit.png");
	//when change it was idle or upgrading or complete	
}






void ControlLayer::update(float dt)
{

}











void ControlLayer::unitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
	
	count = 0;
	CustomButton* item = (CustomButton*)pSender;
	switch (item->getTag()) {
	case 0:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 5);
		}
		break;
	case 1:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 5);
		}
		break;
	case 2:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 5);
		}
		break;
	case 3:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 5);
		}
		break;
	}
}

void ControlLayer::upgradeCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
{
	count = 0;
	CustomButton* item = (CustomButton*)pSender;
	switch (item->getTag()) {
	case 0:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 1);
		}
		break;
	case 1:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 1);
		}
		break;
	case 2:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 1);
		}
		break;
	case 3:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByUnit(item, 1);
		}
		break;
	}
}



void ControlLayer::buildingCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType) {
	count = 0;
	list.setClickedUnit(-1);
	CustomButton* item = (CustomButton*)pSender;
	
	switch(item->getTag()){
	case 0:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			//  if You need chang child button count  then u change that second argu
			//  and third argu is how many upgrad button u need    ***** child button  includ upgrade button
			// first argu is ref Button bcz i want to know any button pressed
			actionByBuilding(item, 3, 0);
		}
		break;
	case 1:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 4, 2);
		}
		break;
	case 2:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 2, 2);
		}
		break;
	case 3:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 2, 0);
		}
		break;
	case 4:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 3, 0);
		}
		break;
	case 5:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 4, 0);
		}
		break;
	case 6:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 2, 0);
		}
		break;
	case 7:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 3, 0);
		}
		break;
	case 8:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 1, 0);
		}
		break;
	case 9:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			actionByBuilding(item, 1, 0);
		}
		break;
	}
}

void ControlLayer::enterCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType) {
	MoveBy* action;

	CustomButton* item = (CustomButton*)pSender;
	int count = 0;
	switch (item->getTag()) {
	case 1:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			if (moveLayer->getPosition().x < 120) {
				action = MoveBy::create(0.0, Point(120, 0));
				moveLayer->runAction(action);
			}
		}
		break;
	case 2:
		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
			action = MoveBy::create(0.0, Point(-120, 0));
			moveLayer->runAction(action);
		}
		break;

	}
}

void ControlLayer::makeBuildingButton(string nomal, string select, string disable, int buttonCount) {
	
		button = CustomButton::create(nomal, select, disable);
		
		button->retain();
		button->setState(BUTTON_STATE_NONE);
		button->setName(makeName("Building_", buttonCount));
		button->setAnchorPoint(Vec2(0, 0));
		button->setPosition(Vec2(120 * (buttonCount), 0));
		button->setTag(buttonCount);
		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::buildingCallback, this));
		
		list.insert_tail(button);
}

void ControlLayer::makeUnitButton(size_t location, size_t howMany, size_t upgradeCount) {
	list.setUpgradeCount(howMany - upgradeCount);
	for (int i = 0; i < howMany- upgradeCount; i++) {
		button = CustomButton::create("unit.png", "unit.png", "unit.png");
		button->retain();
		button->setAnchorPoint(Vec2(0, 0));
		button->setName(makeName("Unit_", i));
		button->setTag(i);
		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::unitCallback, this));
		list.insert_location(location++, button);
	}
	for (int i = 0; i < upgradeCount; i++) {
		button = CustomButton::create("upgrade.png", "upgrade.png", "upgrade.png");
		button->retain();
		button->setAnchorPoint(Vec2(0, 0));
		button->setName(makeName("Upgrade_", i));
		button->setTag(howMany - upgradeCount+i);
		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::upgradeCallback, this));
		list.insert_location(location++, button);
	}
}

void ControlLayer::makeDetailButton(size_t location, size_t count, bool isUpgrade) {
	if(!isUpgrade){
		for (int i = 0; i < count; i++) {
			button = CustomButton::create("star.png", "star.png", "star.png");
			button->retain();
			button->setAnchorPoint(Vec2(0, 0));
			button->setTag(i);
			button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::DetailUnitCallback, this));
			list.insert_location(list.getClickedBuilding()+location, button);
		}
	}else {
		button = CustomButton::create("updetail.png", "updetail_pressed.png", "updetail_pressed.png");
		button->retain();
		button->setAnchorPoint(Vec2(0, 0));
		button->setTag(0);
		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::DetailUpgradeCallback, this));
		list.insert_location(list.getClickedBuilding() + location, button);
	}
}

void ControlLayer::actionByBuilding(CustomButton * refButton, size_t howMany, size_t upgradecount)
{
	if (list.getClickedBuilding() == refButton->getTag()) {
		list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", refButton->getTag()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", refButton->getTag() + 1))));
		list.setClickedBuilding(-1);
	}
	else if (list.getClickedBuilding() != -1 && list.getClickedBuilding() != refButton->getTag()) {
		list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
		makeUnitButton(refButton->getTag(), howMany, upgradecount);
		list.setClickedBuilding(refButton->getTag());
	}
	else {
		makeUnitButton(refButton->getTag(), howMany, upgradecount);
		list.setClickedBuilding(refButton->getTag());
	}

	moveLayer->removeAllChildren();

	for (itr = list.begin(); itr != NULL; itr++) {
		button = itr.getData();
		button->setPosition(Vec2(120 * (count++), 0));
		moveLayer->addChild(itr.getData());
	}

	moveLayer->setPosition(Vec2(120 * (-1 * refButton->getTag() + 1), 0));
}

void ControlLayer::actionByUnit(CustomButton * refButton, size_t howMany)
{
	int uc = list.getUpgradeCount();
	string name = refButton->getName();
	if (name.find("Unit") != string::npos) {
		if (list.getClickedUnit() == refButton->getTag()) {
			if (list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", 0))) == NULL) {
				list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", refButton->getTag()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", refButton->getTag() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
			}
			else {
				list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", refButton->getTag()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", refButton->getTag() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", 0))));
			}
			list.setClickedUnit(-1);
		}
		else if (list.getClickedUnit() != -1 && list.getClickedUnit() != refButton->getTag()) {
			if(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", 0))) == NULL){
				list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
			}
			else {
				if (list.getUpgradeCount() <= list.getClickedUnit()) {
					list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
				}
				else {
					list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", 0))));
				}
			}
			makeDetailButton(refButton->getTag() + 1, howMany, false);
			list.setClickedUnit(refButton->getTag());
		}
		else {
			makeDetailButton(refButton->getTag() + 1, howMany, false);
			list.setClickedUnit(refButton->getTag());
		}
	}

	if (name.find("Upgrade") != string::npos) {
		if (list.getClickedUnit() == refButton->getTag()) {
			list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", refButton->getTag()-list.getUpgradeCount()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", refButton->getTag() - list.getUpgradeCount() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
			list.setClickedUnit(-1);
		}
		else if (list.getClickedUnit() != -1 && list.getClickedUnit() != refButton->getTag()) {
			if(list.getClickedUnit() < list.getUpgradeCount()){
			
				list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Unit_", list.getClickedUnit()+1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", 0))));
				makeDetailButton(refButton->getTag() + 1, howMany, true);
				list.setClickedUnit(refButton->getTag());

			}else{
				
				list.remove_section_node(list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount()))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount() + 1))), list.search_node((CustomButton*)moveLayer->getChildByName(makeName("Building_", list.getClickedBuilding() + 1))));
				makeDetailButton(refButton->getTag() + 1, howMany, true);
				list.setClickedUnit(refButton->getTag());
			}
		}
		else {
			makeDetailButton(refButton->getTag() + 1, howMany, true);
			list.setClickedUnit(refButton->getTag());
		}
	}

	moveLayer->removeAllChildren();
	
	for (itr = list.begin(); itr != NULL; itr++) {
		button = itr.getData();
		button->setPosition(Vec2(120 * (count++), 0));
		moveLayer->addChild(itr.getData());
	}

	moveLayer->setPosition(Vec2(120 * (-1 * (refButton->getTag() + list.getClickedBuilding())), 0));
}

string ControlLayer::makeName(string _name, int _no)
{
	name = _name;
	changCount = _no + 49;
	memcpy(&myChar, &changCount, 1);
	name += myChar;
	return name;
}

void ControlLayer::setGameWorld(GameScene * _gameWorld)
{
	gameWorld = _gameWorld;
}
