#ifndef __CHECK_CREATE_AVAILABLE_HPP__
#define __CHECK_CREATE_AVAILABLE_HPP__

#include "CheckAvailable.hpp"

class CheckCreateAvailable : public CheckAvailable {
private:
public:
	CheckCreateAvailable(GamePlayer* player);
	BaseObject* getBaseObject(int userIndex, int objectType);
	bool checkCreateBuilding(int userIndex, int objectType);
	bool checkCancelBuilding(int userIndex, int objectNo);
	bool ckeckUpgradeBuilding(int userIndex, int objectNo);
	bool checkCancleUpgradeBuilding(int userIndex, int objectNo);
	bool checkCreateUnit(int userIndex, int objectNo);

};
#endif // __CHECK_CREATE_AVAILABLE_HPP__
