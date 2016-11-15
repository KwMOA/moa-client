#ifndef __CUSTOMBUTTON_H__
#define __CUSTOMBUTTON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameDefines.h"

class CustomButton
{
private:
	int state;
	int buttonType;
	int objectType;
	cocos2d::ui::Button* btn;
public:
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

};

#endif // __CUSTOMBUTTON_H__
