#include "CheckAvavilable.hpp"


#include <iostream>

CheckAvailable::CheckAvailable() {

}

CheckAvailable::CheckAvailable(GamePlayer* player) {
	gamePlayers = player;
}


bool CheckAvailable::checkCreateBuilding(int userIndex, int objectType) {
	BaseObject* baseObject;
	Building* building;

	switch (objectType) {
	case OBJECT_TYPE_BUILDING_1:	//need NULL
		return true;
	case OBJECT_TYPE_BUILDING_2:	//need NULL
		return true;
	case OBJECT_TYPE_BUILDING_3:	//need BLD_1
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_1);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_4:	//need BLD_3, BLD_1_UP_1
	case OBJECT_TYPE_BUILDING_5:	//need BLD_3, BLD_1_UP_1
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_3);
		building = (Building*)gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_1);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_6:	//need BLD_5, BLD_1_UP_2
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_5);
		building = (Building*)gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_1);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_7:	//need BLD_3
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_3);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_8:	//need BLD_7, BLD_1_UP_1 
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_7);
		building = (Building*)gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_1);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_9:	//need BLD_4
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_4);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_10:	//need BLD_5
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_5);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	case OBJECT_TYPE_BUILDING_11:	//need BLD_6
	case OBJECT_TYPE_BUILDING_12:	//need BLD_6
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_6);
		if (baseObject != nullptr && baseObject->getState() == (OBJECT_STATE_IDLE, OBJECT_STATE_UPGRADING, OBJECT_STATE_CREATING_UNIT)) { return true; }

		return false;
	default:
		return false;
	}
}

bool CheckAvailable::checkCancelBuilding(int userIndex, int objectNo) {
	BaseObject* baseObject = gamePlayers[userIndex].getBuildingByObjectType(objectNo);
	if (baseObject != nullptr && baseObject->getState() == OBJECT_STATE_CREATING)
		return true;
	return false;
}

bool CheckAvailable::ckeckUpgradeBuilding(int userIndex, int objectNo)
{
	BaseObject* baseObject = gamePlayers[userIndex].getBuildingByObjectNo(objectNo);
	
	if (baseObject != nullptr && baseObject->getState() == OBJECT_STATE_IDLE)
		return true;
	return false;
}

bool CheckAvailable::checkCancleUpgradeBuilding(int userIndex, int objectNo)
{
	BaseObject* baseObject = gamePlayers[userIndex].getBuildingByObjectNo(objectNo);

	if (baseObject != nullptr && baseObject->getState() == OBJECT_STATE_UPGRADING)
		return true;
	return false;
}

bool CheckAvailable::checkCreateUnit(int userIndex, int objectNo)
{
	int objectType = gamePlayers[userIndex].getUnitByObjectNo(objectNo)->getObjectType();
	BaseObject* baseObject;
	switch (objectType) {
	case OBJECT_TYPE_UNIT_1:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_3);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_2:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_7);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_3:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_8);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_4:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_4);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_5:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_9);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_6:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_5);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_7:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_10);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	case OBJECT_TYPE_UNIT_8:
	case OBJECT_TYPE_UNIT_9:
		baseObject = gamePlayers[userIndex].getBuildingByObjectType(OBJECT_TYPE_BUILDING_6);
		if (baseObject->getState() == (OBJECT_STATE_CREATING_UNIT, OBJECT_STATE_IDLE)) { return true; }
		return false;
	default:
		return false;
	}

}
