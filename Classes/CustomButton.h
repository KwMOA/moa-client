#ifndef __CUSTOMBUTTON_H__
#define __CUSTOMBUTTON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameDefines.h"

#include <list>

class ControlLayer;

class CustomButton
{
private:
	int state;
	int buttonType;
	int objectType;
    bool opened;
    CustomButton* parentButton;
	cocos2d::ui::Button* btn;

public:
    std::list<CustomButton*> buttonList;
    std::list<CustomButton*>::iterator buttonListItr;
    
public:
    CustomButton() {};
    CustomButton(int _buttonType, int _objectType, int state, ControlLayer* controlLayer, CustomButton* _parentButton);
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
    void setChildButton(ControlLayer* controlLayer);
};

#endif // __CUSTOMBUTTON_H__
