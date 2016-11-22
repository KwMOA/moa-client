#ifndef __CUSTOMBUTTON_H__
#define __CUSTOMBUTTON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameDefines.h"

#include <list>

class ControlLayer;
class StaticObject;

class CustomButton
{
private:
	int state;
	int buttonType;
	int objectType;
    bool opened;
    CustomButton* parentButton;
	cocos2d::ui::Button* btn;

    char buttonTypeName[20];
    char buttonStateName[10];
    char buttonName[30];
    
    int prevStaticObjectState;
    
public:
    std::list<CustomButton*>* buttonList;
    std::list<CustomButton*>::iterator buttonListItr;
    
    std::list<CustomButton*>* activeButtonList;
    std::list<CustomButton*>::iterator activeButtonListItr;
    
    
    StaticObject* staticObject;
    
    ControlLayer* controlLayer;
    
public:
    CustomButton() {};
    CustomButton(int _buttonType, int _objectType, ControlLayer* _controlLayer, CustomButton* _parentButton);
	~CustomButton();
	void setButton(cocos2d::ui::Button* _btn);
	cocos2d::ui::Button* getButton();
	void defaultSet();
	void setobjectType(int _Type);
	void setButtonType(int _Type);
	void setState(int _state);
	int getobjectType();
	int getButtonType();
	int getState();
	void changeState();

    bool isOpened() { return opened; }
    CustomButton* getParentButton() { return parentButton; }
    std::list<CustomButton*>* open();
    int close();
    void setChildButton(ControlLayer* _controlLayer);
    void setActiveButtonList(ControlLayer* _controlLayer);
    void update(int updateCount);
    
    bool isChangedState();
};

#endif // __CUSTOMBUTTON_H__
