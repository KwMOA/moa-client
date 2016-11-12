#include "CustomButton.h"

CustomButton* CustomButton::create(const std::string & normalImage, const std::string & selectedImage, const std::string & disableImage, TextureResType texType)
{
	Button *btn = new (std::nothrow) Button;
	if (btn && btn->init(normalImage, selectedImage, disableImage, texType))
	{
		btn->autorelease();
		return (CustomButton*)btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

CustomButton::CustomButton()
{

}

void CustomButton::setBuildingType(int _Type)
{
	buildingType = _Type;
}

void CustomButton::setButtonType(int _Type)
{
	buttonType = _Type;
}

void CustomButton::setState(int _state)
{
	state = _state;
}

int CustomButton::getBuildingType(int _Type)
{
	return buildingType;
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
