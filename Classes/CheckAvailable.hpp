#ifndef __CHECK_AVAILABLE_HPP__
#define __CHECK_AVAILABLE_HPP__

class GamePlayer;
class BaseObject;

class CheckAvailable {
protected:
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
