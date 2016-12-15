#ifndef __TECH_CHECKER_H__
#define __TECH_CHECKER_H__

class GamePlayer;
class BaseObject;

class TechChecker {
protected:
	GamePlayer* gamePlayer;
public:
	TechChecker(GamePlayer* player);
//	BaseObject* getBaseObject(int userIndex, int objectType);
	bool checkCreateBuilding(int objectType);
	bool checkCancelBuilding(int objectNo);
	bool ckeckUpgradeBuilding(int objectNo, int upgradeType);
	bool checkCancleUpgradeBuilding(int objectNo, int upgradeType);
	bool checkCreateUnit(int objectNo, int objectType, int objectCount, int lineNo);

};
#endif // !__TECH_CHECKER_H__
