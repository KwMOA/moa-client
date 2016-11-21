//#include "GameScene.h"
//#include "ControlLayer.h"
//#include "SimpleAudioEngine.h"
//#include "ui/CocosGUI.h"
//#include "LinkedList.h"
//#include "CustomButton.h"
//#include "ObjectInfos.h"
//#include "GameManager.h"
//#include "GameWorld.h"
//#include "GamePlayer.h"
//#include "GameDefines.h"
//#include "ClientInput.h"
//#include "BaseObject.h"
//#include "TaskManager.h"
//
//#include <string>
//
//USING_NS_CC;
//
//using namespace cocos2d::ui;
//
//
////Unit Controll this callback
//
//bool ControlLayer::init()
//{
//	
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//    objectInfoList = new ObjectInfoList();
//    
//	list = LinkedList<CustomButton*>();
//	itr = LinkedList<CustomButton*>::iterator();
//	layerLength = 0;
//
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//	moveLayer = Layer::create();
//	//Bottom menu gui
//
//	auto BottomBackground = Sprite::create("bg_bottom.png");
//	BottomBackground->setPosition(Vec2(0, 0));
//	BottomBackground->setAnchorPoint(Vec2(0, 0));
//
//	auto buttonLeft = Button::create("cursor.png", "cursor_pressed.png", "cursor_pressed.png");
//	auto buttonRight = Button::create("cursor.png", "cursor_pressed.png", "cursor_pressed.png");
//
//	buttonLeft->setAnchorPoint(Vec2(0, 0));
//	buttonLeft->setPosition(Vec2(0, 0));
//	buttonRight->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
//	buttonRight->setPosition(Vec2(WIDTH, 0));
//
//	BottomBackground->addChild(buttonRight, 1);
//	BottomBackground->addChild(buttonLeft, 1);
//
//    buttonCount = 0;
//    
//	//Create begin Basic Building count now just 10 after change it !!!!!!!!!!!!!
//    makeBuildingButton("star.png", "star.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_1);
//	makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_2);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_3);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_4);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_5);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_6);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_7);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_8);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_9);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_10);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_11);
//    makeBuildingButton("pause.png", "pause_pressed.png", "star.png", buttonCount++, OBJECT_TYPE_BUILDING_12);
//    
//    
//    //Change this area to change main building button
//
//
//
//	layerLength = list.list_length();
////
//    refreshMoveLayer(120);
//
//	moveLayer->setAnchorPoint(Vec2(0, 0));
//	moveLayer->setPosition(Vec2(120, 0));
//	BottomBackground->addChild(moveLayer, 0);
//	this->addChild(BottomBackground);
//
//	buttonLeft->addTouchEventListener(CC_CALLBACK_2(ControlLayer::enterCallback, this));
//	buttonLeft->setTag(1);
//	buttonRight->addTouchEventListener(CC_CALLBACK_2(ControlLayer::enterCallback, this));
//	buttonRight->setTag(2);
//
//	return true;
//}
//
//void ControlLayer::DetailUnitCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
//{
//
//
//	Button* item = (Button*)pSender;
//	ButtonInfo* diva = objectInfoList->getInfoByName(clickedName);
//	
//	switch (item->getTag()) {
//
//		//create unit
//	case 0:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) { 
//			if(diva->unitCount > 0){
//				CreateUnitCI* p3 = new CreateUnitCI();
//				p3->objectType = diva->objectType;
//				p3->objectNo = gameScene->getGameManager()->getGameWorld()->getGamePlayer(0)->getBuildingByObjectType(list.getClickedBuilding()+1)->getObjectNo();
//				p3->objectCount = diva->unitCount;
//				p3->lineNo = 3;
//				gameScene->getGameManager()->getTaskManager()->pushBackMessage(p3);
//				diva->unitCount = 0;
//			}
//		}
//		break;
//		//cancle create unit
//	case 1:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			if (diva->unitCount > 0) {
//				CreateUnitCI* p3 = new CreateUnitCI();
//				p3->objectType = diva->objectType;
//				p3->objectNo = gameScene->getGameManager()->getGameWorld()->getGamePlayer(0)->getBuildingByObjectType(list.getClickedBuilding() + 1)->getObjectNo();
//				p3->objectCount = diva->unitCount;
//				p3->lineNo = 2;
//				gameScene->getGameManager()->getTaskManager()->pushBackMessage(p3);
//				diva->unitCount = 0;
//			}
//		}
//		break;
//
//
//
//	//this is line 1, 2, 3 
//	case 2:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			if (diva->unitCount > 0) {
//				CreateUnitCI* p3 = new CreateUnitCI();
//				p3->objectType = diva->objectType;
//				p3->objectNo = gameScene->getGameManager()->getGameWorld()->getGamePlayer(0)->getBuildingByObjectType(list.getClickedBuilding() + 1)->getObjectNo();
//				p3->objectCount = 1;
//				p3->lineNo = 1;
//				gameScene->getGameManager()->getTaskManager()->pushBackMessage(p3);
//				diva->unitCount = 0;
//			}
//		}
//		break;
//	case 3:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			if(diva->unitCount >0)
//				diva->unitCount--;
//			}
//		break;
//	case 4:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			diva->unitCount++;
//		}
//		break;
//	}
//
//}
//
//
//
//
//
//
//
//
//
////Upgrade controll this callback
//
//void ControlLayer::DetailUpgradeCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
//{
//	Button* item = (Button*)pSender;
//	ButtonInfo* diva = objectInfoList->getInfoByName(clickedName);
//
//	//when change it was idle or upgrading or complete	
//}
//
//
//
//
//
//
//void ControlLayer::update(float dt)
//{
//
//}
//
//
//
//
//
//
//
//
//
//
//
//void ControlLayer::unitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
//	
//	count = 0;
//	Button* item = (Button*)pSender;
//	if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//		actionByUnit(item, 5);
//	}
//}
//
//void ControlLayer::upgradeCallback(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType eventType)
//{
//	count = 0;
//	Button* item = (Button*)pSender;
//
//	if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//		actionByUnit(item, 1);
//	}
//
//}
//
//
//
//void ControlLayer::buildingCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType) {
//	count = 0;
//	list.setClickedUnit(-1);
//	Button* item = (Button*)pSender;
//	
//	switch(item->getTag()){
//	case 0:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			//  if You need chang child button count  then u change that second argu
//			//  and third argu is how many upgrad button u need    ***** child button  includ upgrade button
//			// first argu is ref Button bcz i want to know any button pressed
//			actionByBuilding(item, 2 , 1, OBJECT_TYPE_UNIT_1, OBJECT_TYPE_UPGRADE_1);
//		}
//		break;
//	case 1:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 4, 2, OBJECT_TYPE_UNIT_2, OBJECT_TYPE_UPGRADE_2);
//		}
//		break;
//	case 2:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 2, 2, NULL, 1);
//		}
//		break;
//	case 3:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 2, 0, OBJECT_TYPE_UNIT_4, 1);
//		}
//		break;
//	case 4:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 3, 0, NULL, NULL);
//		}
//		break;
//	case 5:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 4, 0, NULL, NULL);
//		}
//		break;
//	case 6:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 2, 0, NULL, NULL);
//		}
//		break;
//	case 7:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 3, 0, NULL, NULL);
//		}
//		break;
//	case 8:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 1, 0, NULL, NULL);
//		}
//		break;
//	case 9:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 1, 0, NULL, NULL);
//		}
//		break;
//	case 10:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			actionByBuilding(item, 1, 0, NULL, NULL);
//		}
//		break;
//	}
//}
//
//void ControlLayer::enterCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType) {
//	MoveBy* action;
//
//	Button* item = (Button*)pSender;
//	int count = 0;
//	switch (item->getTag()) {
//	case 1:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//			if (moveLayer->getPosition().x < 120) {
//                moveLayer->setPositionX(moveLayer->getPositionX() + ((double)(DISPLAY_WIDTH - 240) / 9));
////				action = MoveBy::create(0.0, Point((DISPLAY_WIDTH - 240) / 9, 0));
////				moveLayer->runAction(action);
//			}
//		}
//		break;
//	case 2:
//		if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
//            moveLayer->setPositionX(moveLayer->getPositionX() - ((double)(DISPLAY_WIDTH - 240) / 9));
//
////			action = MoveBy::create(0.0, Point(-120, 0));
////			moveLayer->runAction(action);
//		}
//		break;
//
//	}
//}
//
//void ControlLayer::makeBuildingButton(string nomal, string select, string disable, int buttonCount, int objectType) {
//	
//    button = Button::create();
//    button->retain();
//    button->setName(makeName("Building_%d", buttonCount));
//    button->setAnchorPoint(Vec2(0, 0));
//    button->setPosition(Vec2(120 * (buttonCount), 0));
//    button->setTag(buttonCount);
//    button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::buildingCallback, this));
//    csBtn = new CustomButton();
//    csBtn->setButton(button);
//    csBtn->setButtonType(BUTTON_TYPE_BUILDING);
//    csBtn->setobjectType(objectType);
//    csBtn->setState(objectInfoList->getInfo(BUTTON_TYPE_BUILDING, objectType)->state);
//    list.insert_tail(csBtn, makeName("Building_%d", buttonCount));
//}
//
//
//void ControlLayer::makeDetailButton(size_t count, string name) {
//	if(name.find("Unit_") != string::npos){
//		for (int i = 0; i < count; i++) {
//			button = Button::create("star.png", "star.png", "star.png");
//			button->retain();
//			button->setAnchorPoint(Vec2(0, 0));
//			button->setTag(i);
//			button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::DetailUnitCallback, this));
//			csBtn = new CustomButton();
//			csBtn->setButton(button);
//			list.insert_location(list.search_node_name(name), csBtn, "detail");
//		}
//	}else {
//		button = Button::create("updetail.png", "updetail_pressed.png", "updetail_pressed.png");
//		button->retain();
//		button->setAnchorPoint(Vec2(0, 0));
//		button->setTag(0);
//		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::DetailUpgradeCallback, this));
//		csBtn = new CustomButton();
//		csBtn->setButton(button);
//		list.insert_location(list.search_node_name(name), csBtn, "detail");
//	}
//}
//
//void ControlLayer::actionByBuilding(Button * refButton, size_t howMany, size_t upgradecount, int firstUnit, int firstUpgrade)
//{
//	clickedName = "";
// 	if (list.getClickedBuilding() == refButton->getTag()) {
//
//		list.remove_section_node(list.search_node_name(makeName("Building_%d", refButton->getTag())), list.search_node_name(makeName("Building_%d", refButton->getTag() + 1)));
//		list.setClickedBuilding(-1);
//	}
//	else if (list.getClickedBuilding() != -1 && list.getClickedBuilding() != refButton->getTag()) {
//		list.remove_section_node(list.search_node_name(makeName("Building_%d", list.getClickedBuilding())), list.search_node_name(makeName("Building_%d", list.getClickedBuilding() + 1)));
//		makeUnitButton(refButton->getTag(), howMany, upgradecount, firstUnit, firstUpgrade);
//		list.setClickedBuilding(refButton->getTag());
//	}
//	else {
//		makeUnitButton(refButton->getTag(), howMany, upgradecount, firstUnit, firstUpgrade);
//		list.setClickedBuilding(refButton->getTag());
//	}
//
//    refreshMoveLayer(-1 * refButton->getTag() + 1);
////	moveLayer->removeAllChildren();
////
////	for (itr = list.begin(); itr != list.end(); itr++) {
////		button = itr.getData()->getButton();
////		button->setPosition(Vec2(120 * (count++), 0));
////		moveLayer->addChild(itr.getData()->getButton());
////	}
////
////	moveLayer->setPosition(Vec2(120 * (-1 * refButton->getTag() + 1), 0));
//}
//
//
//void ControlLayer::makeUnitButton(size_t location, size_t howMany, size_t upgradeCount, int firstUnit, int firstUpgrade) {
//	list.setUpgradeCount(howMany - upgradeCount);
//	list.setFirstUpgradeNo(firstUpgrade - 1);
//	for (int i = 0; i < howMany - upgradeCount; i++) {
//		button = Button::create("unit.png", "unit.png", "unit.png");
//		button->retain();
//		button->setAnchorPoint(Vec2(0, 0));
//		button->setName(makeName("Unit_%d", firstUnit - list.getTotalBuildingCount() + i - 1));
//		int as = firstUnit - list.getTotalBuildingCount() + i - 1;
//		string asdf = makeName("Unit_%d", firstUnit - list.getTotalBuildingCount() + i - 1);
//		button->setTag(firstUnit - list.getTotalBuildingCount() + i - 1);
//		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::unitCallback, this));
//		csBtn = new CustomButton();
//		csBtn->setButton(button);
//		list.insert_location(location++, csBtn, makeName("Unit_%d", firstUnit - list.getTotalBuildingCount() + i - 1));
//	}
//	for (int i = 0; i < upgradeCount; i++) {
//		button = Button::create("upgrade.png", "upgrade.png", "upgrade.png");
//		button->retain();
//		button->setAnchorPoint(Vec2(0, 0));
//		button->setName(makeName("Upgrade_%d", firstUpgrade + i - 1));
//		button->setTag(firstUpgrade + i - 1);
//		button->addTouchEventListener(CC_CALLBACK_2(ControlLayer::upgradeCallback, this));
//		csBtn = new CustomButton();
//		csBtn->setButton(button);
//		list.insert_location(location++, csBtn, makeName("Upgrade_%d", firstUpgrade + i - 1));
//	}
//}
//
//void ControlLayer::actionByUnit(Button * refButton, size_t howMany)
//{
//	string name = refButton->getName();
//	
//	if (clickedName.compare(name) == 0) {
//		if (list.search_node_name(makeName("Upgrade_%d", list.getFirstUpgradeNo())) == NULL) {
//			list.remove_section_node(list.search_node_name(makeName("Unit_%d", refButton->getTag())),
//								     list.search_node_name(makeName("Unit_%d", refButton->getTag() + 1)),
//									 list.search_node_name(makeName("Building_%d", list.getClickedBuilding() + 1)));
//		}else {
//			if(name.compare("Upgrade_") == string::npos){
//				list.remove_section_node(list.search_node_name(makeName("Unit_%d", refButton->getTag())),
//										 list.search_node_name(makeName("Unit_%d", refButton->getTag() + 1)),
//										 list.search_node_name(makeName("Upgrade_%d", list.getFirstUpgradeNo())));
//			}
//			else {
//				list.remove_section_node(list.search_node_name(makeName("Upgrade_%d", refButton->getTag())),
//									   	 list.search_node_name(makeName("Upgrade_%d", refButton->getTag()+1)),
//										 list.search_node_name(makeName("Building_%d", list.getClickedBuilding() + 1)));
//			}
//		}
//		clickedName = "";
//	}else if (clickedName.compare("") != 0 && clickedName.compare(name) != 0) {
//		if (list.search_node_name(makeName("Upgrade_%d", list.getFirstUpgradeNo())) == NULL) {
//			list.remove_section_node(list.search_node_name(makeName("Unit_%d", list.getClickedUnit())),
//									 list.search_node_name(makeName("Unit_%d", list.getClickedUnit() + 1)),
//									 list.search_node_name(makeName("Building_%d", list.getClickedBuilding() + 1)));
//		}else {
//			if (clickedName.find("Upgrade_") != string::npos) {
//				list.remove_section_node(list.search_node_name(makeName("Upgrade_%d", list.getClickedUnit())),
//										 list.search_node_name(makeName("Upgrade_%d", list.getClickedUnit()+ 1)),
//										 list.search_node_name(makeName("Building_%d", list.getClickedBuilding() + 1)));
//			}
//			else {
//				list.remove_section_node(list.search_node_name(makeName("Unit_%d", list.getClickedUnit())),
//										 list.search_node_name(makeName("Unit_%d", list.getClickedUnit() + 1)),
//									     list.search_node_name(makeName("Upgrade_%d", list.getFirstUpgradeNo())));
//			}
//		}
//		makeDetailButton(howMany, name);
//		list.setClickedUnit(refButton->getTag());
//		clickedName = name;
//	}
//	else {
//		makeDetailButton(howMany, name);
//		list.setClickedUnit(refButton->getTag());
//		clickedName = name;
//	}
//	if (name.find("Unit") != string::npos) {
//		/*if (list.getClickedUnit() == refButton->getTag()) {
//			if (list.search_node_name(makeName("Upgrade_", list.getFirstUpgradeNo())) == NULL) {
//				list.remove_section_node(list.search_node_name(makeName("Unit_", refButton->getTag())),
//										 list.search_node_name(makeName("Unit_", refButton->getTag() + 1)),
//						                 list.search_node_name(makeName("Building_", list.getClickedBuilding() + 1)));
//			}
//			else {
//				list.remove_section_node(list.search_node_name(makeName("Unit_", refButton->getTag())),
//										 list.search_node_name(makeName("Unit_", refButton->getTag() + 1)),
//									     list.search_node_name(makeName("Upgrade_", list.getFirstUpgradeNo())));
//			}
//			list.setClickedUnit(-1);
//		}
//		else if (list.getClickedUnit() != -1 && list.getClickedUnit() != refButton->getTag()) {
//			if(list.search_node_name(makeName("Upgrade_", list.getFirstUpgradeNo())) == NULL){
//				list.remove_section_node(list.search_node_name(makeName("Unit_", list.getClickedUnit())),
//										 list.search_node_name(makeName("Unit_", list.getClickedUnit() + 1)), 
//										 list.search_node_name(makeName("Building_", list.getClickedBuilding() + 1)));
//			}
//			else {
//				if (list.getUpgradeCount() <= list.getClickedUnit()) {
//					list.remove_section_node(list.search_node_name(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount())),
//											 list.search_node_name(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount() + 1)),
//											 list.search_node_name(makeName("Building_", list.getClickedBuilding() + 1)));
//				}
//				else {
//					list.remove_section_node(list.search_node_name(makeName("Unit_", list.getClickedUnit())), 
//											 list.search_node_name(makeName("Unit_", list.getClickedUnit() + 1)), 
//										     list.search_node_name(makeName("Upgrade_", list.getFirstUpgradeNo())));
//				}
//			}
//			makeDetailButton(refButton->getTag() + 1, howMany, false);
//			list.setClickedUnit(refButton->getTag());
//		}
//		else {
//			makeDetailButton(refButton->getTag() + 1, howMany, false);
//			list.setClickedUnit(refButton->getTag());
//		}*/
//	}
//
//	if (name.find("Upgrade") != string::npos) {
//		/*if (list.getClickedUnit() == refButton->getTag()) {
//			list.remove_section_node(list.search_node_name(makeName("Upgrade_", refButton->getTag()-list.getUpgradeCount())),
//									 list.search_node_name(makeName("Upgrade_", refButton->getTag() - list.getUpgradeCount() + 1)), 
//									 list.search_node_name(makeName("Building_", list.getClickedBuilding() + 1)));
//			list.setClickedUpgradeNo(-1);
//		}
//		else if (list.getClickedUnit() != -1 && list.getClickedUnit() != refButton->getTag()) {
//			if(list.getClickedUnit() < list.getUpgradeCount()){
//			
//				list.remove_section_node(list.search_node_name(makeName("Unit_", list.getClickedUnit())),
//										 list.search_node_name(makeName("Unit_", list.getClickedUnit()+1)), 
//										 list.search_node_name(makeName("Upgrade_", 0)));
//				makeDetailButton(refButton->getTag() + 1, howMany, true);
//				list.setClickedUnit(refButton->getTag());
//
//			}else{
//				
//				list.remove_section_node(list.search_node_name(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount())),
//										 list.search_node_name(makeName("Upgrade_", list.getClickedUnit() - list.getUpgradeCount() + 1)), 
//										 list.search_node_name(makeName("Building_", list.getClickedBuilding() + 1)));
//				makeDetailButton(refButton->getTag() + 1, howMany, true);
//				list.setClickedUnit(refButton->getTag());
//			}
//		}
//		else {
//			makeDetailButton(refButton->getTag() + 1, howMany, true);
//			list.setClickedUnit(refButton->getTag());
//		}*/
//	}
//
//	
//	moveLayer->removeAllChildren();
//	
//	for (itr = list.begin(); itr != NULL; itr++) {
//		button = itr.getData()->getButton();
//		button->setPosition(Vec2(120 * (count++), 0));
//		moveLayer->addChild(itr.getData()->getButton());
//	}
//
//	moveLayer->setPosition(Vec2(-120 * (list.getLocation(name)-2), 0));
//}
//
//char* ControlLayer::makeName(string _name, int _no)
//{
//	memset(buf, 0, 128);
//	sprintf(buf, _name.c_str(), _no+1);
//	/*
//	name = _name;
//	changCount = _no + 49;
//	memcpy(&myChar, &changCount, 1);
//	name += myChar;*/
//	return buf;
//}
//
//void ControlLayer::setGameWorld(GameScene * _gameWorld)
//{
//	gameScene = _gameWorld;
//}
//
//
//// re-draw move layer
//void ControlLayer::refreshMoveLayer(int firstViewButton)
//{
//    moveLayer->removeAllChildren();
//
//    int i = 0;
//    for (itr = list.begin(); itr != NULL; itr++) {
//        itr.getData()->getButton()->setPositionX(((double)(DISPLAY_WIDTH - 240) / 9) * i);
//        moveLayer->addChild(itr.getData()->getButton());
//        i++;
//    }
//    
//    moveLayer->setPositionX((((double)DISPLAY_WIDTH - 240) / 9) * firstViewButton);
//}
//
//
//
