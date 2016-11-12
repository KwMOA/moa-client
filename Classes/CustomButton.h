#ifndef __CUSTOMBUTTON_H__
#define __CUSTOMBUTTON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameDefines.h"

class CustomButton : public cocos2d::ui::Button
{
private:
	int state;
	int buttonType;
	int buildingType;
	
public:
	static CustomButton* create(const std::string& normalImage,
								const std::string& selectedImage = "",
								const std::string& disableImage = "",
								TextureResType texType = TextureResType::LOCAL);
	CustomButton();

	void setBuildingType(int _Type);
	void setButtonType(int _Type);
	void setState(int _state);
	int getBuildingType(int _Type);
	int getButtonType();
	int getState();
	void changeState();

		CREATE_FUNC(CustomButton);
};

#endif // __CUSTOMBUTTON_H__
