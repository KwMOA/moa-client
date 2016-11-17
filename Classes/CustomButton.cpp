#include "CustomButton.h"
#include "ControlLayer.h"

USING_NS_CC;
using namespace cocos2d::ui;

CustomButton::CustomButton(int _buttonType, int _objectType, int _state, ControlLayer* controlLayer, CustomButton* _parentButton)
{
    buttonType = _buttonType;
    objectType = _objectType;
    parentButton = _parentButton;
    btn = Button::create();
    btn->retain();
    btn->setAnchorPoint(Vec2(0.5, 0));
    btn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::buttonCallback, controlLayer, this));

    setState(_state);
    
    //set child button
    setChildButton(controlLayer);
    
    //set close
    close();
}

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
    
    char buttonTypeName[20] = {0, };
    char buttonStateName[10] = {0, };
    char buttonName[20] = {0, };

    if(buttonType == BUTTON_TYPE_ROOT) {

    } else {
        if(buttonType == BUTTON_TYPE_BUILDING) {
            memcpy(buttonTypeName, "building", 8);
            
            if(objectType == OBJECT_TYPE_BUILDING_1) {
                memcpy(buttonName, "building_1", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_2) {
                memcpy(buttonName, "building_2", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_3) {
                memcpy(buttonName, "building_3", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_4) {
                memcpy(buttonName, "building_4", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_5) {
                memcpy(buttonName, "building_5", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_6) {
                memcpy(buttonName, "building_6", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_7) {
                memcpy(buttonName, "building_7", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_8) {
                memcpy(buttonName, "building_8", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_9) {
                memcpy(buttonName, "building_9", 10);
            } else if(objectType == OBJECT_TYPE_BUILDING_10) {
                memcpy(buttonName, "building_10", 11);
            } else if(objectType == OBJECT_TYPE_BUILDING_11) {
                memcpy(buttonName, "building_11", 11);
            } else if(objectType == OBJECT_TYPE_BUILDING_12) {
                memcpy(buttonName, "building_12", 11);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_UNIT) {
            memcpy(buttonTypeName, "unit", 4);
            
            if(objectType == OBJECT_TYPE_UNIT_1) {
                memcpy(buttonName, "unit_1", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_2) {
                memcpy(buttonName, "unit_2", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_3) {
                memcpy(buttonName, "unit_3", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_4) {
                memcpy(buttonName, "unit_4", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_5) {
                memcpy(buttonName, "unit_5", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_6) {
                memcpy(buttonName, "unit_6", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_7) {
                memcpy(buttonName, "unit_7", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_8) {
                memcpy(buttonName, "unit_8", 6);
            } else if(objectType == OBJECT_TYPE_UNIT_9) {
                memcpy(buttonName, "unit_9", 6);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_UPGRADE) {
            memcpy(buttonTypeName, "upgrade", 7);
            
            if(objectType == UPGRADE_TYPE_1) {
                memcpy(buttonName, "upgrade_1", 9);
            } else if(objectType == UPGRADE_TYPE_2) {
                memcpy(buttonName, "upgrade_2", 9);
            } else if(objectType == UPGRADE_TYPE_3) {
                memcpy(buttonName, "upgrade_3", 9);
            } else if(objectType == UPGRADE_TYPE_4) {
                memcpy(buttonName, "upgrade_4", 9);
            } else if(objectType == UPGRADE_TYPE_5) {
                memcpy(buttonName, "upgrade_5", 9);
            } else if(objectType == UPGRADE_TYPE_6) {
                memcpy(buttonName, "upgrade_6", 9);
            } else if(objectType == UPGRADE_TYPE_7) {
                memcpy(buttonName, "upgrade_7", 9);
            } else if(objectType == UPGRADE_TYPE_8) {
                memcpy(buttonName, "upgrade_8", 9);
            } else if(objectType == UPGRADE_TYPE_9) {
                memcpy(buttonName, "upgrade_9", 9);
            } else if(objectType == UPGRADE_TYPE_10) {
                memcpy(buttonName, "upgrade_10", 10);
            } else if(objectType == UPGRADE_TYPE_11) {
                memcpy(buttonName, "upgrade_11", 10);
            } else if(objectType == UPGRADE_TYPE_12) {
                memcpy(buttonName, "upgrade_12", 10);
            } else if(objectType == UPGRADE_TYPE_13) {
                memcpy(buttonName, "upgrade_13", 10);
            } else if(objectType == UPGRADE_TYPE_14) {
                memcpy(buttonName, "upgrade_14", 10);
            } else if(objectType == UPGRADE_TYPE_15) {
                memcpy(buttonName, "upgrade_15", 10);
            } else if(objectType == UPGRADE_TYPE_16) {
                memcpy(buttonName, "upgrade_16", 10);
            } else if(objectType == UPGRADE_TYPE_17) {
                memcpy(buttonName, "upgrade_17", 10);
            } else if(objectType == UPGRADE_TYPE_18) {
                memcpy(buttonName, "upgrade_18", 10);
            } else if(objectType == UPGRADE_TYPE_19) {
                memcpy(buttonName, "upgrade_19", 10);
            } else if(objectType == UPGRADE_TYPE_20) {
                memcpy(buttonName, "upgrade_20", 10);
            } else if(objectType == UPGRADE_TYPE_21) {
                memcpy(buttonName, "upgrade_21", 10);
            } else if(objectType == UPGRADE_TYPE_22) {
                memcpy(buttonName, "upgrade_22", 10);
            } else if(objectType == UPGRADE_TYPE_23) {
                memcpy(buttonName, "upgrade_23", 10);
            } else if(objectType == UPGRADE_TYPE_24) {
                memcpy(buttonName, "upgrade_24", 10);
            } else {
                
            }
            
        } else {
            
        }
        
        
        if(state == BUTTON_STATE_NONE) {
            memcpy(buttonStateName, "disble", 6);
        } else if(state == BUTTON_STATE_IDLE) {
            memcpy(buttonStateName, "active", 6);
        } else if(state == BUTTON_STATE_ACTIVE) {
            memcpy(buttonStateName, "able", 4);
        } else {
            
        }
        

        char buttonName1[100] = {0, };
        sprintf(buttonName1, "control_btn/control_btn_%s_%s.png", buttonStateName, buttonName);
        
        //press button
        char buttonName2[100] = {0, };
        sprintf(buttonName2, "control_btn/control_btn_%s_%s.png", buttonStateName, buttonName);
        
        
        btn->loadTextures(buttonName1, buttonName2);
    }
}


std::list<CustomButton*>* CustomButton::open()
{
    opened = true;
    
    return &buttonList;
}

int CustomButton::close()
{
    opened = false;
    
    int closeCount = 0;
    for(buttonListItr = buttonList.begin(); buttonListItr != buttonList.end(); buttonListItr++)
    {
        int childCloseCount = 0;
        if((*buttonListItr)->isOpened()) {
            childCloseCount += (*buttonListItr)->close();
        }
        
        closeCount += childCloseCount;
        closeCount++;
    }
    
    return closeCount;
}

void CustomButton::setChildButton(ControlLayer* controlLayer)
{
    if(buttonType == BUTTON_TYPE_ROOT) {
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_1, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_2, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_3, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_4, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_5, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_6, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_7, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_8, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_9, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_10, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_11, 1, controlLayer, this));
        buttonList.push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_12, 1, controlLayer, this));
    } else if(buttonType == BUTTON_TYPE_BUILDING) {
        
        switch (objectType) {
            case OBJECT_TYPE_BUILDING_1:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_1, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_2:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_2, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_3:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_1, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_2, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_3, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_4:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_4, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_5, 1, controlLayer, this));
                
            }
                break;
            case OBJECT_TYPE_BUILDING_5:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_6, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_7, 1, controlLayer, this));

            }
                break;
            case OBJECT_TYPE_BUILDING_6:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_2, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_3, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_7:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_3, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_4, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_5, 1, controlLayer, this));

            }
                break;
            case OBJECT_TYPE_BUILDING_8:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_6, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_7, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_8, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_9:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_9, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_10, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_11, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_12, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_13, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_14, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_10:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_15, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_16, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_17, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_18, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_11:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_19, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_20, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_21, 1, controlLayer, this));
            }
                break;
            case OBJECT_TYPE_BUILDING_12:
            {
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_22, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_23, 1, controlLayer, this));
                buttonList.push_back(new CustomButton(BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_24, 1, controlLayer, this));
            }
                break;
                
            default:
                break;
        }
        
    } else if(buttonType == BUTTON_TYPE_UNIT) {
        
        
        
    } else if(buttonType == BUTTON_TYPE_UPGRADE) {
        
        
        
    } else {
        
    }
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
