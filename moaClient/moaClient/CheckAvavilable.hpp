#ifndef __CHECK_AVAILABLE_HPP__
#define __CHECK_AVAILABLE_HPP__

#include "GamePlayer.hpp"
#include "BaseObject.hpp"
#include "GameDefines.h"
#include "Building.hpp"
#include "Upgrade.hpp"

class CheckAvailable {
private:
	GamePlayer* gamePlayers;
public:
	CheckAvailable();
	CheckAvailable(GamePlayer* player);
	BaseObject* getBaseObject(int userIndex, int objectType);
	bool checkCreateBuilding(int userIndex, int objectType);
	bool checkCancelBuilding(int userIndex, int objectNo);
	bool ckeckUpgradeBuilding(int userIndex, int objectNo);
	bool checkCancleUpgradeBuilding(int userIndex, int objectNo);
	bool checkCreateUnit(int userIndex, int objectNo);

};
#endif // !__CHECK_AVAILABLE_HPP__
