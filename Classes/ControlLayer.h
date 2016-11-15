#ifndef __CONTROLLAYER_H__
#define __CONTROLLAYER_H__

#include "cocos2d.h"
#include "GameDefines.h"
#include "ui/CocosGUI.h"
#include "LinkedList.h"
#include "CustomButton.h"
#include "ObjectInfos.h"

#include <string>

using namespace cocos2d::ui;

class ControlLayer : public cocos2d::Layer
{
private:

	GameScene* gameScene;
	LinkedList<CustomButton*> list;
	LinkedList<CustomButton*>::iterator itr;
	
	char buf[128];
	string name;
	string clickedName;
	char myChar;
	Button* button;
	CustomButton* csBtn;
	Layer* moveLayer;
	int buttonCount;
	int changCount;
	int count;
	size_t layerLength;
	void makeBuildingButton(string nomal, string select, string disable, int count);
	void makeUnitButton(size_t location, size_t howMany, size_t upgradeCount, int firstUnit, int firstUpgrade);
	void makeDetailButton(size_t count, string name);
	void actionByBuilding(Button* refButton, size_t howMany, size_t upgradeCount, int firstUnit, int firstUpgrade);
	void actionByUnit(Button* refButton, size_t howMany);
	char* makeName(string _name, int _no);

public:

	virtual bool init();
	void update(float dt);	


	void completeCreateBuildingNotify(int objectType);
	void completeUgradeNotify(int upgradeType, int upgradeCompleteNum);
	void activeBuildingNotify(int objectType);
	void activeUgradeNotify(int upgradeType, int upgradeCompleteNum);
	void activeUnitNotify(int objectType);

	// a selector callback
	void setGameWorld(GameScene* _gameWorld);

	void enterCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

	void buildingCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
	void unitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
	void upgradeCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

	void DetailUnitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
	void DetailUpgradeCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

	// implement the "static create()" method manually
	CREATE_FUNC(ControlLayer);
};

#endif // __CONTROLLAYER_H__
