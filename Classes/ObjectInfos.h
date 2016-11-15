#ifndef __OBJECTINFOS_H__
#define __OBJECTINFOS_H__

#include <list>
#include<string>

struct ButtonInfo
{
	std::string name;
	int state;
	int buttonType;
	int objectType;
	int unitCount;
	ButtonInfo(std::string _name, int _state, int _buttonType, int _objectType) {
		name = _name;
		state = _state;
		buttonType = _buttonType;
		objectType = _objectType;
		unitCount = 0;
	}
	void setInfo(int _state, int _buttonType, int _objectType) {
		state = _state;
		buttonType = _buttonType;
		objectType = _objectType;
		}
};

class ObjectInfoList
{
private:
	std::list<ButtonInfo*> infoList;
	std::list<ButtonInfo*>::iterator itr;
public:
	ObjectInfoList();
	ButtonInfo* getInfo(int btnType, int objectType);
	ButtonInfo* getInfoByName(std::string _name);
};

#endif // __OBJECTINFOS_H__
