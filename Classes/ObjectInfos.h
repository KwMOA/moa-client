#ifndef __OBJECTINFOS_H__
#define __OBJECTINFOS_H__

#include <list>

struct ButtonInfo
{
	int state;
	int buttonType;
	int objectType;
	ButtonInfo() {
		state = -1;
		buttonType = -1;
		objectType = -1;
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
	std::list<ButtonInfo> infoList;
	std::list<ButtonInfo>::iterator itr;
public:
	void createButton(ButtonInfo btnInfo);
	
	
};

#endif // __OBJECTINFOS_H__
