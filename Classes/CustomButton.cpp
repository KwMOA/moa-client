#include "CustomButton.h"




void CustomButton::setButton(cocos2d::ui::Button* _btn)
{
	btn = _btn;
}

cocos2d::ui::Button * CustomButton::getButton()
{
	return btn;
}

void CustomButton::defaultSet()
{
	state = -1;
	buttonType = -1;
	objectType = -1;
}

void CustomButton::setobjectType(int _Type)
{
	objectType = _Type;
}

void CustomButton::setButtonType(int _Type)
{
	buttonType = _Type;
}

void CustomButton::setState(int _state)
{
	state = _state;
}

int CustomButton::getobjectType()
{
	return objectType;
}


int CustomButton::getButtonType()
{
	return buttonType;
}

int CustomButton::getState()
{
	return state;
}

void CustomButton::changeState()
{
}
