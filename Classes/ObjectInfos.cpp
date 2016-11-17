#include "ObjectInfos.h"
#include "GameDefines.h"


ObjectInfoList::ObjectInfoList()
{

	//Button Building
//
//	infoList.push_back(new ButtonInfo("Building_1", BUTTON_STATE_IDLE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_1));
//	infoList.push_back(new ButtonInfo("Building_2", BUTTON_STATE_IDLE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_2));
//	infoList.push_back(new ButtonInfo("Building_3", BUTTON_STATE_ACTIVE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_3));
//	infoList.push_back(new ButtonInfo("Building_4", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_4));
//	infoList.push_back(new ButtonInfo("Building_5", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_5));
//	infoList.push_back(new ButtonInfo("Building_6", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_6));
//	infoList.push_back(new ButtonInfo("Building_7", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_7));
//	infoList.push_back(new ButtonInfo("Building_8", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_8));
//	infoList.push_back(new ButtonInfo("Building_9", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_9));
//	infoList.push_back(new ButtonInfo("Building_10", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_10));
//	infoList.push_back(new ButtonInfo("Building_11", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_11));
//	infoList.push_back(new ButtonInfo("Building_12", BUTTON_STATE_NONE, BUTTON_TYPE_BUILDING, OBJECT_TYPE_BUILDING_12));
//
//	//Button Unit
//
//	infoList.push_back(new ButtonInfo("Unit_1", BUTTON_STATE_IDLE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_1));
//	infoList.push_back(new ButtonInfo("Unit_2", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_2));
//	infoList.push_back(new ButtonInfo("Unit_3", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_3));
//	infoList.push_back(new ButtonInfo("Unit_4", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_4));
//	infoList.push_back(new ButtonInfo("Unit_5", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_5));
//	infoList.push_back(new ButtonInfo("Unit_6", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_6));
//	infoList.push_back(new ButtonInfo("Unit_7", BUTTON_STATE_NONE, BUTTON_TYPE_UNIT, OBJECT_TYPE_UNIT_7));
//
//	//Button Upgrade
//
//	infoList.push_back(new ButtonInfo("Upgrade_1", BUTTON_STATE_ACTIVE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_1));
//	infoList.push_back(new ButtonInfo("Upgrade_2", BUTTON_STATE_ACTIVE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_2));
//	infoList.push_back(new ButtonInfo("Upgrade_3", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_3));
//	infoList.push_back(new ButtonInfo("Upgrade_4", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_4));
//	infoList.push_back(new ButtonInfo("Upgrade_5", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_5));
//	infoList.push_back(new ButtonInfo("Upgrade_6", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_6));
//	infoList.push_back(new ButtonInfo("Upgrade_7", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_7));
//	infoList.push_back(new ButtonInfo("Upgrade_8", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_8));
//	infoList.push_back(new ButtonInfo("Upgrade_9", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_9));
//	infoList.push_back(new ButtonInfo("Upgrade_10", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_10));
//	infoList.push_back(new ButtonInfo("Upgrade_11", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_11));
//	infoList.push_back(new ButtonInfo("Upgrade_12", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_12));
//	infoList.push_back(new ButtonInfo("Upgrade_13", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_13));
//	infoList.push_back(new ButtonInfo("Upgrade_14", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_14));
//	infoList.push_back(new ButtonInfo("Upgrade_15", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_15));
//	infoList.push_back(new ButtonInfo("Upgrade_16", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_16));
//	infoList.push_back(new ButtonInfo("Upgrade_17", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_17));
//	infoList.push_back(new ButtonInfo("Upgrade_18", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_18));
//	infoList.push_back(new ButtonInfo("Upgrade_19", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_19));
//	infoList.push_back(new ButtonInfo("Upgrade_20", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_20));
//	infoList.push_back(new ButtonInfo("Upgrade_21", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_21));
//	infoList.push_back(new ButtonInfo("Upgrade_22", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_22));
//	infoList.push_back(new ButtonInfo("Upgrade_23", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_23));
//	infoList.push_back(new ButtonInfo("Upgrade_24", BUTTON_STATE_NONE, BUTTON_TYPE_UPGRADE, UPGRADE_TYPE_24));
//



}

ButtonInfo* ObjectInfoList::getInfo(int btnType, int objectType)
{
	for (itr = infoList.begin(); itr != infoList.end(); itr++) {
		ButtonInfo* btnInfo = (ButtonInfo*)* itr;
		if(btnInfo->buttonType == btnType && btnInfo->objectType == objectType)
		return btnInfo;
	}
	return nullptr;
}

ButtonInfo * ObjectInfoList::getInfoByName(std::string _name)
{
	for (itr = infoList.begin(); itr != infoList.end(); itr++) {
		ButtonInfo* btnInfo = (ButtonInfo*)* itr;
		if (btnInfo->name.compare(_name)== 0)
			return btnInfo;
	}
	return nullptr;
}





