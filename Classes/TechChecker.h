#ifndef __TECH_CHECKER_H__
#define __TECH_CHECKER_H__

class GamePlayer;
class BaseObject;

class TechChecker {
protected:
	GamePlayer* gamePlayers;
public:
	TechChecker(GamePlayer* player);
	BaseObject* getBaseObject(int userIndex, int objectType);
	bool checkCreateBuilding(int userIndex, int objectType);
	bool checkCancelBuilding(int userIndex, int objectNo);
	bool ckeckUpgradeBuilding(int userIndex, int objectNo);
	bool checkCancleUpgradeBuilding(int userIndex, int objectNo);
	bool checkCreateUnit(int userIndex, int objectNo);

};
#endif // !__TECH_CHECKER_H__
