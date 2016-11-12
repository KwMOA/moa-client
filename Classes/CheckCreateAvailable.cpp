#include "CheckCreateAvailable.hpp"

#include "GamePlayer.hpp"
#include "BaseObject.hpp"
#include "GameDefines.h"
#include "Building.hpp"
#include "Upgrade.hpp"

#include <iostream>


CheckCreateAvailable::CheckCreateAvailable(GamePlayer* player) {
	gamePlayers = player;
}


bool CheckCreateAvailable::checkCreateBuilding(int userIndex, int objectType) {
    return true;
}

bool CheckCreateAvailable::checkCancelBuilding(int userIndex, int objectNo) {

    return true;
}

bool CheckCreateAvailable::ckeckUpgradeBuilding(int userIndex, int objectNo)
{
    return true;
}

bool CheckCreateAvailable::checkCancleUpgradeBuilding(int userIndex, int objectNo)
{
    return true;
}

bool CheckCreateAvailable::checkCreateUnit(int userIndex, int objectNo)
{
    return true;
}
