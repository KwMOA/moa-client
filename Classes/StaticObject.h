//
//  StaticObject.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 5..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef StaticObject_h
#define StaticObject_h

#include <stdio.h>
#include <string>
#include "BasicDefines.h"

class StaticObject
{
protected:
    int objectType;
    char name[20];
    int price;
    int width;
    
    int staticObjectState;
    
public:
    int getObjectType() { return objectType; }
    void setObjectType(int _objectType) { objectType = _objectType; }
    
    void setName(char* _name, int nameLen) { memcpy(name, _name, nameLen); }
    char* getName() { return name; }
    
    void setPrice(int _price) { price = _price; }
    int getPrice() { return price; }
    
    void setWidth(int _width) { width = _width; }
    int getWidth() { return width; }
    
    void setStaticObjectState(int _staticObjectState) { staticObjectState = _staticObjectState; }
    int getStaticObjectState() { return staticObjectState; }
    
};

class StaticBuilding : public StaticObject
{
protected:
    int createImageCount;
    int workImageCount;
    int destroyImageCount;
    
    int createCompleteTime;
    
    int x, y;

public:
    void setCreateImageCount(int _createImageCount) { createImageCount = _createImageCount; }
    int getCreateImageCount() { return createImageCount; }
    
    void setWorkImageCount(int _workImageCount) { workImageCount = _workImageCount; }
    int getWorkImageCount() { return workImageCount; }
    
    void setDestroyImageCount(int _destroyImageCount) { destroyImageCount = _destroyImageCount; }
    int getDestroyImageCount() { return destroyImageCount; }
    
    void setCreateCompleteTime(int _createCompleteTime) { createCompleteTime = _createCompleteTime; }
    int getCreateCompleteTime() { return createCompleteTime; }
    
    int getX() { return x; }
    void setX(int _x) { x = _x; }
    
    int getY() { return y; }
    void setY(int _y) { y = _y; }
};


class StaticBuilding_1 : public StaticBuilding
{
public:
    StaticBuilding_1();
};

class StaticBuilding_2 : public StaticBuilding
{
public:
    StaticBuilding_2();
};

class StaticBuilding_3 : public StaticBuilding
{
public:
    StaticBuilding_3();
};

class StaticBuilding_4 : public StaticBuilding
{
public:
    StaticBuilding_4();
};


class StaticBuilding_5 : public StaticBuilding
{
public:
    StaticBuilding_5();
};

class StaticBuilding_6 : public StaticBuilding
{
public:
    StaticBuilding_6();
};


class StaticBuilding_7 : public StaticBuilding
{
public:
    StaticBuilding_7();
};

class StaticBuilding_8 : public StaticBuilding
{
public:
    StaticBuilding_8();
};

class StaticBuilding_9 : public StaticBuilding
{
public:
    StaticBuilding_9();
};

class StaticBuilding_10 : public StaticBuilding
{
public:
    StaticBuilding_10();
};


class StaticBuilding_11 : public StaticBuilding
{
public:
    StaticBuilding_11();
};

class StaticBuilding_12 : public StaticBuilding
{
public:
    StaticBuilding_12();
};




class StaticUnit : public StaticObject
{
protected:
    int maxHp;
    int atk;
    int atkSpeed;
    int atkLoadSpeed;
    int atkRange;
    int speed;
    int def;
    int isVisible;
    int population;
    
    int runImageCount;
    int attackImageCount;
    int deathImageCount;
    
    int attackInfluenceNum;
    
    
public:
    void setMaxHp(int _maxHp) { maxHp = _maxHp; }
    int getMaxHp() { return maxHp; }
    
    void setAtk(int _atk) { atk = _atk; }
    int getAtk() { return atk; }
    
    void setAtkSpeed(int _atkSpeed) { atkSpeed = _atkSpeed; }
    int getAtkSpeed() { return atkSpeed; }
    
    void setAtkLoadSpeed(int _atkLoadSpeed) { atkLoadSpeed = _atkLoadSpeed; }
    int getAtkLoadSpeed() { return atkLoadSpeed; }
    
    void setAtkRange(int _atkRange) { atkRange = _atkRange; }
    int getAtkRange() { return atkRange; }
    
    void setSpeed(int _speed) { speed = _speed; }
    int getSpeed() { return speed; }
    
    void setDef(int _def) { def = _def; }
    int getDef() { return def; }
    
    void setIsVisible(int _isVisible) { isVisible = _isVisible; }
    int getIsVisible() { return isVisible; }
    
    void setPopulation(int _population) { population = _population; }
    int getPopulation() { return population; }
    
    
    void setRunImageCount(int _runImageCount) { runImageCount = _runImageCount; }
    int getRunImageCount() { return runImageCount; }
    
    void setAttackImageCount(int _attackImageCount) { attackImageCount = _attackImageCount; }
    int getAttackImageCount() { return attackImageCount; }
    
    void setDeathImageCount(int _deathImageCount) { deathImageCount = _deathImageCount; }
    int getDeathImageCount() { return deathImageCount; }
    
    void setAttackInfluenceNum(int _attackInfluenceNum) { attackInfluenceNum = _attackInfluenceNum; }
    int getAttackInfluenceNum() { return attackInfluenceNum; }
};

class StaticUnit_1 : public StaticUnit
{
public:
    StaticUnit_1();
};

class StaticUnit_2 : public StaticUnit
{
public:
    StaticUnit_2();
};

class StaticUnit_3 : public StaticUnit
{
protected:
    int heal;
    bool isDetecting;
    
public:
    StaticUnit_3();
    
    void setHeal(int _heal) { heal = _heal; }
    int getHeal() { return heal; }
    
    void setIsDetecting(bool _isDetecting) { isDetecting = _isDetecting; }
    bool getIsDetecting() { return isDetecting; }
};

class StaticUnit_4 : public StaticUnit
{
protected:
    int knockBack;
    
public:
    StaticUnit_4();
    
    void setKnockBack(int _knockBack) { knockBack = _knockBack; }
    int getKnockBack() { return knockBack; }
};

class StaticUnit_5 : public StaticUnit
{
protected:
    int skillCount;
    int skillRange;
    
public:
    StaticUnit_5();
    
    void setSkillCount(int _skillCount) { skillCount = _skillCount; }
    int getSkillCount() { return skillCount; }
    
    void setSkillRange(int _skillRange) { skillRange = _skillRange; }
    int getSkillRange() { return skillRange; }
    
};

class StaticUnit_6 : public StaticUnit
{
protected:
    int graveCount;
    
public:
    StaticUnit_6();
    
    void setGraveCount(int _graveCount) { graveCount = _graveCount; }
    int getGraveCount() { return graveCount; }
    
};

class StaticUnit_7 : public StaticUnit
{
protected:
    bool isIgnoreDef;
    
public:
    StaticUnit_7();
    
    void setIsIgnoreDef(bool _isIgnoreDef) { isIgnoreDef = _isIgnoreDef; }
    bool getIsIgnoreDef() { return isIgnoreDef; }
};

class StaticUnit_8 : public StaticUnit
{
protected:
    int shield;
    int autoAroundHeal;
    
public:
    StaticUnit_8();
    
    void setShield(int _shield) { shield = _shield; }
    int getShield() { return shield; }
    
    void setAutoAroundHeal(int _autoAroundHeal) { autoAroundHeal = _autoAroundHeal; }
    int getAutoAroundHeal() { return autoAroundHeal; }
};

class StaticUnit_9 : public StaticUnit
{
protected:
    int aroundAtk;
    int aroundAtkRange;
    
public:
    StaticUnit_9();
    
    void setAroundAtk(int _aroundAtk) { aroundAtk = _aroundAtk; }
    int getAroundAtk() { return aroundAtk; }
    
    void setAroundAtkRange(int _aroundAtkRange) { aroundAtkRange = _aroundAtkRange; }
    int getAroundAtkRange() { return aroundAtkRange; }
};

#endif /* StaticObject_h */
