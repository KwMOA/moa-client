//
//  StaticObject.h
//  moaClient
//
//  Created by kimyongchan on 2016. 10. 4..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#ifndef StaticObject_h
#define StaticObject_h

#include <string>

class StaticUnit
{
protected:
    int unitType;
    std::string name;
    int price;
    int width;
    int maxHp;
    int atk;
    int atkSpeed;
    int atkRange;
    int speed;
    int def;
    int isVisible;
    int population;
    
    
public:
    
    void setUnitType(int _unitType) { unitType = _unitType; }
    int getUnitType() { return unitType; }
    
    void setName(int _name) { name = _name; }
    std::string getName() { return name; }
    
    void setPrice(int _price) { price = _price; }
    int getPrice() { return price; }
    
    void setWidth(int _width) { width = _width; }
    int getWidth() { return width; }
    
    void setMaxHp(int _maxHp) { maxHp = _maxHp; }
    int getMaxHp() { return maxHp; }
    
    void setAtk(int _atk) { atk = _atk; }
    int getAtk() { return atk; }
    
    void setAtkSpeed(int _atkSpeed) { atkSpeed = _atkSpeed; }
    int getAtkSpeed() { return atkSpeed; }
    
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
    
    
};

class StaticUnit_1 : public StaticUnit
{
    
};

class StaticUnit_2 : public StaticUnit
{
    
};

class StaticUnit_3 : public StaticUnit
{
protected:
    int heal;
    bool isDetecting;
    
public:
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
    void setKnockBack(int _knockBack) { knockBack = _knockBack; }
    int getKnockBack() { return knockBack; }
};

class StaticUnit_5 : public StaticUnit
{
protected:
    int skillCount;
    int skillRange;
    
public:
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
    void setGraveCount(int _graveCount) { graveCount = _graveCount; }
    int getGraveCount() { return graveCount; }
    
};

class StaticUnit_7 : public StaticUnit
{
protected:
    bool isIgnoreDef;
    
public:
    void setIsIgnoreDef(bool _isIgnoreDef) { isIgnoreDef = _isIgnoreDef; }
    bool getIsIgnoreDef() { return isIgnoreDef; }
};

class StaticUnit_8 : public StaticUnit
{
protected:
    int shield;
    int autoAroundHeal;
    
public:
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
    void setAroundAtk(int _aroundAtk) { aroundAtk = _aroundAtk; }
    int getAroundAtk() { return aroundAtk; }
    
    void setAroundAtkRange(int _aroundAtkRange) { aroundAtkRange = _aroundAtkRange; }
    int getAroundAtkRange() { return aroundAtkRange; }
};

#endif /* StaticObject_h */
