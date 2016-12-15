#include "CustomButton.h"
#include "ControlLayer.h"
#include "StaticObject.h"

USING_NS_CC;
using namespace cocos2d::ui;

CustomButton::CustomButton(int _buttonType, int _objectType, ControlLayer* _controlLayer, CustomButton* _parentButton)
{
    controlLayer = _controlLayer;
    
    buttonType = _buttonType;
    objectType = _objectType;
    parentButton = _parentButton;
    opened = false;
    
    
    memset(buttonTypeName, 0, 20);
    memset(buttonName, 0, 30);
    
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
            
            if(objectType == OBJECT_TYPE_UPGRADE_1) {
                memcpy(buttonName, "upgrade_1", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_2) {
                memcpy(buttonName, "upgrade_2", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_3) {
                memcpy(buttonName, "upgrade_3", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_4) {
                memcpy(buttonName, "upgrade_4", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_5) {
                memcpy(buttonName, "upgrade_5", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_6) {
                memcpy(buttonName, "upgrade_6", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_7) {
                memcpy(buttonName, "upgrade_7", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_8) {
                memcpy(buttonName, "upgrade_8", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_9) {
                memcpy(buttonName, "upgrade_9", 9);
            } else if(objectType == OBJECT_TYPE_UPGRADE_10) {
                memcpy(buttonName, "upgrade_10", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_11) {
                memcpy(buttonName, "upgrade_11", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_12) {
                memcpy(buttonName, "upgrade_12", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_13) {
                memcpy(buttonName, "upgrade_13", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_14) {
                memcpy(buttonName, "upgrade_14", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_15) {
                memcpy(buttonName, "upgrade_15", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_16) {
                memcpy(buttonName, "upgrade_16", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_17) {
                memcpy(buttonName, "upgrade_17", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_18) {
                memcpy(buttonName, "upgrade_18", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_19) {
                memcpy(buttonName, "upgrade_19", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_20) {
                memcpy(buttonName, "upgrade_20", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_21) {
                memcpy(buttonName, "upgrade_21", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_22) {
                memcpy(buttonName, "upgrade_22", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_23) {
                memcpy(buttonName, "upgrade_23", 10);
            } else if(objectType == OBJECT_TYPE_UPGRADE_24) {
                memcpy(buttonName, "upgrade_24", 10);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_ACTION) {
            
            if(objectType == ACTION_BUTTON_TYPE_UNIT_PLUS) {
                memcpy(buttonName, "action_plus", 11);
            } else if(objectType == ACTION_BUTTON_TYPE_UNIT_MINUS) {
                memcpy(buttonName, "action_minus", 12);
            } else if(objectType == ACTION_BUTTON_TYPE_LINE_1) {
                memcpy(buttonName, "action_line_1", 13);
            } else if(objectType == ACTION_BUTTON_TYPE_LINE_2) {
                memcpy(buttonName, "action_line_2", 13);
            } else if(objectType == ACTION_BUTTON_TYPE_LINE_3) {
                memcpy(buttonName, "action_line_3", 13);
            } else if(objectType == ACTION_BUTTON_TYPE_BUILDING_CREATE) {
                memcpy(buttonName, "action_building_create", 22);
            } else if(objectType == ACTION_BUTTON_TYPE_BUILDING_CREATE_CANCEL) {
                memcpy(buttonName, "action_building_cancel_create", 29);
            } else if(objectType == ACTION_BUTTON_TYPE_UPGRADE) {
                memcpy(buttonName, "action_upgrade_upgrade", 22);
            } else if(objectType == ACTION_BUTTON_TYPE_UPGRADE_CANCEL) {
                memcpy(buttonName, "action_upgrade_cancel_upgrade", 29);
            } else {
                printf("??");
            }
        } else {
            
        }
    }
    
    
    btn = Button::create();
    btn->retain();
    btn->setAnchorPoint(Vec2(0.5, 0));
    btn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::buttonCallback, controlLayer, this));
    btn->setSwallowTouches(false); // to send touch event to control-layer 
    controlLayer->wholeButtonList.push_back(this);

    // link button with static object
    staticObject = nullptr;
    setActiveButtonList(controlLayer);
    
    if(buttonType == BUTTON_TYPE_ROOT) {
        setState(0);
    } else if(buttonType == BUTTON_TYPE_BUILDING) {
        staticObject = controlLayer->getGamePlayer()->getStaticBuildingByBuildingType(objectType);
        setState(staticObject->getStaticObjectState());
    } else if(buttonType == BUTTON_TYPE_UPGRADE) {
        staticObject = controlLayer->getGamePlayer()->getStaticUpgradeByUpgradeType(objectType);
        setState(staticObject->getStaticObjectState());
    } else if(buttonType == BUTTON_TYPE_UNIT) {
        staticObject = controlLayer->getGamePlayer()->getStaticUnitByUnitType(objectType);
        setState(staticObject->getStaticObjectState());
    }
    
//    prevStaticObjectState = staticObject->getStaticObjectState();
    
    
//    if(buttonType == BUTTON_TYPE_BUILDING)
//        setState(controlLayer->getGamePlayer()->getStaticBuildingByBuildingType(objectType)->getStaticObjectState());
//    else if(buttonType == BUTTON_TYPE_UNIT)
//        setState(controlLayer->getGamePlayer()->getStaticUnitByUnitType(objectType)->getStaticObjectState());
//    else if(buttonType == BUTTON_TYPE_UPGRADE) {
//        setState(STATIC_OBJECT_STATE_DISABLE);
//    } else {
//        setState(0);
//    }
    
    //set child button
//    setChildButton(controlLayer);
    
//    //set close
//    close();
    
    
    //add parentheses
    if(activeButtonList != nullptr && activeButtonList->size() != 0) {
        CustomButton* cb = activeButtonList->front();
        
        if(cb != nullptr) {
            Sprite* parentheses = Sprite::create("control_btn/left_parentheses.png");
            parentheses->setAnchorPoint(Vec2(0.5, 0));
            
            cb->getButton()->addChild(parentheses, 10);
        }
        
        cb = activeButtonList->back();
        
        if(cb != nullptr) {
            Sprite* parentheses = Sprite::create("control_btn/right_parentheses.png");
            parentheses->setAnchorPoint(Vec2(0.5, 0));
            parentheses->setPositionX(115.5);
            
            cb->getButton()->addChild(parentheses, 10);
        }
    }
    
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
    
    setChildButton(controlLayer);
    
    
    
    memset(buttonStateName, 0, 10);

    if(buttonType == BUTTON_TYPE_ROOT) {

    } else {
        if(buttonType == BUTTON_TYPE_BUILDING) {
            
            if(state == STATIC_OBJECT_STATE_DISABLE) {
                memcpy(buttonStateName, "disble", 6);
            } else if(state == STATIC_OBJECT_STATE_ABLE) {
                memcpy(buttonStateName, "able", 4);
            } else if(state == STATIC_OBJECT_STATE_BUILDING_CREATING) {
                memcpy(buttonStateName, "able", 4);
            } else if(state == STATIC_OBJECT_STATE_BUILDING_UPGRADING) {
                memcpy(buttonStateName, "able", 4);
            } else if(state == STATIC_OBJECT_STATE_ACTIVE) {
                memcpy(buttonStateName, "active", 6);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_UNIT) {

            
            if(state == STATIC_OBJECT_STATE_DISABLE) {
                memcpy(buttonStateName, "disble", 6);
            } else if(state == STATIC_OBJECT_STATE_ABLE) {
                memcpy(buttonStateName, "active", 6);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_UPGRADE) {
            
            if(state == STATIC_OBJECT_STATE_DISABLE) {
                memcpy(buttonStateName, "disble", 6);
            } else if(state == STATIC_OBJECT_STATE_ABLE) {
                memcpy(buttonStateName, "able", 4);
            } else if(state == STATIC_OBJECT_STATE_UPGRADE_UPGRADING) {
                memcpy(buttonStateName, "able", 4);
            } else if(state == STATIC_OBJECT_STATE_ACTIVE) {
                memcpy(buttonStateName, "disble", 6);
            } else {
                
            }
            
        } else if(buttonType == BUTTON_TYPE_ACTION) {
            memcpy(buttonStateName, "able", 4);

        } else {
            
        }
        

        char buttonName1[100] = {0, };
        sprintf(buttonName1, "control_btn/control_btn_%s_%s.png", buttonStateName, buttonName);
        
        //press button
        char buttonName2[100] = {0, };
        sprintf(buttonName2, "control_btn/control_btn_%s_%s.png", buttonStateName, buttonName);
        
        
        btn->loadTextures(buttonName1, buttonName2);
        
        prevStaticObjectState = state;
    }
}


std::list<CustomButton*>* CustomButton::open()
{
    opened = true;
    
    return buttonList;
}

int CustomButton::close()
{
    opened = false;
    
    int closeCount = 0;
    for(buttonListItr = buttonList->begin(); buttonListItr != buttonList->end(); buttonListItr++)
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

void CustomButton::setChildButton(ControlLayer* _controlLayer)
{
    if(buttonType == BUTTON_TYPE_ROOT) {
        buttonList = activeButtonList;
    } else if(buttonType == BUTTON_TYPE_BUILDING) {
        if(state == STATIC_OBJECT_STATE_DISABLE) {
            buttonList = nullptr;
        } else if(state == STATIC_OBJECT_STATE_ABLE) {
            buttonList = controlLayer->getBuildingCreateButtonList();
//            controlLayer->attachedBuildingCreateButton = this;
        } else if(state == STATIC_OBJECT_STATE_BUILDING_CREATING) {
            buttonList = controlLayer->getBuildingCreateCancelButtonList();
//            controlLayer->attachedBuildingCreateCancelButton = this;
        } else if(state == STATIC_OBJECT_STATE_ACTIVE) {
            buttonList = activeButtonList;
        } else if(state == STATIC_OBJECT_STATE_BUILDING_UPGRADING) {
            buttonList = controlLayer->getUpgradeCreateCancelButtonList();
//            controlLayer->attachedUpgradeCreateCancelButton = this;
        } else {
            printf("??");
        }
        
    } else if(buttonType == BUTTON_TYPE_UNIT) {
        if(state == STATIC_OBJECT_STATE_DISABLE) {
            buttonList = nullptr;
        } else if(state == STATIC_OBJECT_STATE_ABLE) {
            buttonList = controlLayer->getUnitActionButtonList();
//            controlLayer->attachedUnitActionButton = this;
        } else {
            printf("??");
        }
        
    } else if(buttonType == BUTTON_TYPE_UPGRADE) {
        if(state == STATIC_OBJECT_STATE_DISABLE) {
            buttonList = nullptr;
        } else if(state == STATIC_OBJECT_STATE_ABLE) {
            buttonList = controlLayer->getUpgradeCreateButtonList();
//            controlLayer->attachedUpgradeCreateButton = this;
        } else if(state == STATIC_OBJECT_STATE_UPGRADE_UPGRADING) {
            buttonList = nullptr;
        } else if(state == STATIC_OBJECT_STATE_ACTIVE) {
            buttonList = nullptr;
        } else {
            printf("??");
        }
        
    } else {
        
    }
}

void CustomButton::setActiveButtonList(ControlLayer* _controlLayer)
{
    activeButtonList = new std::list<CustomButton*>();
    
    if(buttonType == BUTTON_TYPE_ROOT) {
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_1, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_2, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_3, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_4, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_5, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_6, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_7, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_8, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_9, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_10, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_11, controlLayer, this));
        activeButtonList->push_back(new CustomButton(BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_12, controlLayer, this));
        
        return ;
    }
    
    switch (objectType) {
        case OBJECT_TYPE_BUILDING_1:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_1, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_2:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_2, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_3:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_1, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_2, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_3, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_4:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_4, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_5, controlLayer, this));
            
        }
            break;
        case OBJECT_TYPE_BUILDING_5:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_6, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_7, controlLayer, this));
            
        }
            break;
        case OBJECT_TYPE_BUILDING_6:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_2, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_3, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_7:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_3, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_4, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_5, controlLayer, this));
            
        }
            break;
        case OBJECT_TYPE_BUILDING_8:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_6, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_7, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_8, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_9:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_9, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_10, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_11, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_12, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_13, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_14, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_10:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_15, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_16, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_17, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_18, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_11:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_19, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_20, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_21, controlLayer, this));
        }
            break;
        case OBJECT_TYPE_BUILDING_12:
        {
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_22, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_23, controlLayer, this));
            activeButtonList->push_back(new CustomButton(BUTTON_TYPE_UPGRADE, OBJECT_TYPE_UPGRADE_24, controlLayer, this));
        }
            break;
            
        default:
            break;
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


void CustomButton::update(int updateCount)
{
    int staticObjectState = 0;
    
    switch (buttonType) {
        case BUTTON_TYPE_ROOT:
        {
            setState(0);
            
            break;
        }
            
        case BUTTON_TYPE_BUILDING:
        {
            StaticBuilding* staticBuilding = (StaticBuilding*)staticObject;
            
            staticObjectState = staticBuilding->getStaticObjectState();
            
            setState(staticObjectState);
            
            if(staticObjectState == STATIC_OBJECT_STATE_DISABLE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_ABLE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_BUILDING_CREATING) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_ACTIVE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_BUILDING_UPGRADING) {
            } else {
            }
            
            break;
        }
        case BUTTON_TYPE_UPGRADE:
        {
            
            staticObjectState = staticObject->getStaticObjectState();
            
            setState(staticObjectState);

            if(staticObjectState == STATIC_OBJECT_STATE_DISABLE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_ABLE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_UPGRADE_UPGRADING) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_ACTIVE) {
            } else {
            }
            
            break;
        }
        case BUTTON_TYPE_UNIT:
        {
            
            staticObjectState = staticObject->getStaticObjectState();

            setState(staticObjectState);
            
            if(staticObjectState == STATIC_OBJECT_STATE_DISABLE) {
            } else if(staticObjectState == STATIC_OBJECT_STATE_ABLE) {
            } else {
            }
            
            break;
        }
        case BUTTON_TYPE_ACTION:
        {
            setState(0);
            break;
        }
        default:
            
            break;
    }
}


bool CustomButton::isChangedState()
{
    if(staticObject == nullptr) {
        return false;
    }
    
    if(prevStaticObjectState != staticObject->getStaticObjectState())
    {
        return true;
    }
    
    return false;
}
