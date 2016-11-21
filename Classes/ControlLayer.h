#ifndef __CONTROLLAYER_H__
#define __CONTROLLAYER_H__

#include "cocos2d.h"
#include "GameDefines.h"
#include "ui/CocosGUI.h"
#include "LinkedList.h"
#include "CustomButton.h"
#include "ObjectInfos.h"
#include "GamePlayer.h"
#include "StaticObject.h"
#include <string>
#include <list>

using namespace cocos2d::ui;

class ControlLayer : public cocos2d::Layer
{
private:

	GamePlayer* gamePlayer;
    CustomButton* rootCustomButton;
    
    ObjectInfoList* objectInfoList;
	
    std::list<CustomButton*> buttonList;
    std::list<CustomButton*>::iterator buttonListItr;
    
    CustomButton* plusButton;
    CustomButton* minusButton;
    CustomButton* line1Button;
    CustomButton* line2Button;
    CustomButton* line3Button;
    
    std::list<CustomButton*> unitActionButtonList;
    
    std::list<CustomButton*> buildingCreateButtonList;
    
    std::list<CustomButton*> buildingCreateCancelButtonList;
    
    std::list<CustomButton*> upgradeCreateButtonList;
    
    std::list<CustomButton*> upgradeCreateCancelButtonList;
    
    CustomButton* createButton;
    CustomButton* cancelCreateButton;
    CustomButton* upgradeButton;
    CustomButton* upgradeCreateButton;
    
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
	void makeUnitButton(size_t location, size_t howMany, size_t upgradeCount, int firstUnit, int firstUpgrade);
	void makeDetailButton(size_t count, string name);
	void actionByBuilding(Button* refButton, size_t howMany, size_t upgradeCount, int firstUnit, int firstUpgrade);
	void actionByUnit(Button* refButton, size_t howMany);
	char* makeName(string _name, int _no);

public:

	virtual bool init();
    bool initWithParameter(GamePlayer* gamePlayer);
	void update(float dt);	
    void refreshMoveLayer(CustomButton* customButton);
    
    GamePlayer* getGamePlayer() { return gamePlayer; }
    
    void makeBuildingButton(int objectType);

    void buttonCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType, CustomButton* customButton);

    void buildingCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

    void closeButtones(CustomButton* customButton);
    
    void openButtones(CustomButton* customButton);
    
    std::list<CustomButton*>* getUnitActionButtonList() { return &unitActionButtonList; }
    std::list<CustomButton*>* getBuildingCreateButtonList() { return &buildingCreateButtonList; }
    std::list<CustomButton*>* getBuildingCreateCancelButtonList() { return &buildingCreateCancelButtonList; }
    std::list<CustomButton*>* getUpgradeCreateButtonList() { return &upgradeCreateButtonList; }
    std::list<CustomButton*>* getUpgradeCreateCancelButtonList() { return &upgradeCreateCancelButtonList; }

	void completeCreateBuildingNotify(int objectType);
	void completeUgradeNotify(int upgradeType, int upgradeCompleteNum);
	void activeBuildingNotify(int objectType);
	void activeUgradeNotify(int upgradeType, int upgradeCompleteNum);
	void activeUnitNotify(int objectType);

	// a selector callback
	void setGamePlayer(GamePlayer* _gamePlayer);

	void enterCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

	void unitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
	void upgradeCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);

	void DetailUnitCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
	void DetailUpgradeCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    
    
    std::list<CustomButton*> wholeButtonList;
    std::list<CustomButton*>::iterator wholeButtonListItr;
    
    //receive notify
    void setState(int objectType, int state);
    
    
    void update(int updateCount);
    

	// implement the "static create()" method manually
	CREATE_FUNC(ControlLayer);
};

#endif // __CONTROLLAYER_H__
