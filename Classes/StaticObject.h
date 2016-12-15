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
#include "GamePlayer.h"
#include <cocos2d.h>

USING_NS_CC;

class Building;
class Upgrade;

class StaticObject
{
protected:
    GamePlayer* gamePlayer;
    int objectType;
    char name[20];
    int staticObjectState;
    Sprite* image;

public:
    StaticObject(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer);
    int getObjectType() { return objectType; }
    void setObjectType(int _objectType) { objectType = _objectType; }
    
    void setName(char* _name, int nameLen) { memcpy(name, _name, nameLen); }
    char* getName() { return name; }
    
    void setStaticObjectState(int _staticObjectState) { staticObjectState = _staticObjectState; }
    int getStaticObjectState() { return staticObjectState; }
    
    Sprite* getImage() { return image; }
    
    
    
//    void setUpgrade(Upgrade* _upgrade) { upgrade = _upgrade; }
//    
//    Upgrade* upgrade;
};


////////////////////////////////////////////////StaticUpgrade

class StaticUpgrade : public StaticObject
{
protected:
    int maxUpgardeCount;
    std::pair<int, int>* completeTimeAndPriceArray;
    
public:
    StaticUpgrade(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer);
    int getMaxUpgradeCount() { return maxUpgardeCount; }
    void setMaxUpgradeCount(int _maxUpgradeCount) { maxUpgardeCount = _maxUpgradeCount; }
    
    void setCompleteTimeArray(std::pair<int, int>* _completeTimeAndPriceArray) { completeTimeAndPriceArray = _completeTimeAndPriceArray; }
    std::pair<int, int>* getCompleteTimeArray() { return completeTimeAndPriceArray; }
    
    void startUpgrade();
    void cancelUpgrade();
    virtual void completeUpgrade() = 0;
    
    void setUpgrade(Upgrade* _upgrade) { upgrade = _upgrade; }

    Upgrade* upgrade;

};

class StaticUpgrade_1 : public StaticUpgrade
{
public:
    StaticUpgrade_1(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_2 : public StaticUpgrade
{
protected:
    int acquiredGoldCount;
    
public:
    StaticUpgrade_2(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_3 : public StaticUpgrade
{
public:
    StaticUpgrade_3(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_4 : public StaticUpgrade
{
public:
    StaticUpgrade_4(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_5 : public StaticUpgrade
{
public:
    StaticUpgrade_5(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_6 : public StaticUpgrade
{
public:
    StaticUpgrade_6(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_7 : public StaticUpgrade
{
public:
    StaticUpgrade_7(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_8 : public StaticUpgrade
{
public:
    StaticUpgrade_8(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_9 : public StaticUpgrade
{
public:
    StaticUpgrade_9(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_10 : public StaticUpgrade
{
public:
    StaticUpgrade_10(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_11 : public StaticUpgrade
{
public:
    StaticUpgrade_11(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_12 : public StaticUpgrade
{
public:
    StaticUpgrade_12(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_13 : public StaticUpgrade
{
public:
    StaticUpgrade_13(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_14 : public StaticUpgrade
{
public:
    StaticUpgrade_14(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_15 : public StaticUpgrade
{
public:
    StaticUpgrade_15(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_16 : public StaticUpgrade
{
public:
    StaticUpgrade_16(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_17 : public StaticUpgrade
{
public:
    StaticUpgrade_17(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_18 : public StaticUpgrade
{
public:
    StaticUpgrade_18(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_19 : public StaticUpgrade
{
public:
    StaticUpgrade_19(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_20 : public StaticUpgrade
{
public:
    StaticUpgrade_20(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_21 : public StaticUpgrade
{
public:
    StaticUpgrade_21(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_22 : public StaticUpgrade
{
public:
    StaticUpgrade_22(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_23 : public StaticUpgrade
{
public:
    StaticUpgrade_23(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};

class StaticUpgrade_24 : public StaticUpgrade
{
public:
    StaticUpgrade_24(GamePlayer* _gamePlayer);
    virtual void completeUpgrade();
};





////////////////////////////////////////////////StaticVisibleObject

class StaticVisibleObject : public StaticObject
{
protected:
    int price;
    int width;
    int height;
    
    int imageWidth;
    int imageHeight;
    
public:
    StaticVisibleObject(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer);

    void setPrice(int _price) { price = _price; }
    int getPrice() { return price; }
    
    void setWidth(int _width) { width = _width; }
    int getWidth() { return width; }
    
    void setHeight(int _height) { height = _height; }
    int getHeight() { return height; }
    
    void setImageWidth(int _imageWidth) { imageWidth = _imageWidth; }
    int getImageWidth() { return imageWidth; }
    
    void setImageHeight(int _imageHeight) { imageHeight = _imageHeight; }
    int getImageHeight() { return imageHeight; }
    
};


////////////////////////////////////////////////StaticBuilding

class StaticBuilding : public StaticVisibleObject
{
protected:
    int createImageCount;
    int workImageCount;
    int destroyImageCount;
    
    int createCompleteTime;
    
    int x, y;
    
    int maxCreateCondition;
    int createConditionCount;
    
public:
    StaticBuilding(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer);
    void setCreateImageCount(int _createImageCount) { createImageCount = _createImageCount; }
    int getCreateImageCount() { return createImageCount; }
    
    void setWorkImageCount(int _workImageCount) { workImageCount = _workImageCount; }
    int getWorkImageCount() { return workImageCount; }
    
    void setDestroyImageCount(int _destroyImageCount) { destroyImageCount = _destroyImageCount; }
    int getDestroyImageCount() { return destroyImageCount; }
    
    void setCreateCompleteTime(int _createCompleteTime) { createCompleteTime = _createCompleteTime; }
    int getCreateCompleteTime() { return createCompleteTime; }
    
    void setMaxCreateCondition(int _maxCreateCondition) { maxCreateCondition = _maxCreateCondition; }
    int getMaxCreateCondition() { return maxCreateCondition; }
    
    void setCreateConditionCount(int _createConditionCount) { createConditionCount = _createConditionCount; }
    int getCreateConditionCount() { return createConditionCount; }
    
    int getX() { return x; }
    void setX(int _x) { x = _x; }
    
    int getY() { return y; }
    void setY(int _y) { y = _y; }
    
    void startCreate(Building* building);
    void cancelCreate();
    virtual void completeCreate() = 0;
    
    void startUpgrade();
    void cancelUpgrade();
    void completeUpgrade();
    
    
public:
    Building* building;
};


class StaticBuilding_1 : public StaticBuilding
{
public:
    StaticBuilding_1(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_2 : public StaticBuilding
{
public:
    StaticBuilding_2(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_3 : public StaticBuilding
{
public:
    StaticBuilding_3(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_4 : public StaticBuilding
{
public:
    StaticBuilding_4(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};


class StaticBuilding_5 : public StaticBuilding
{
public:
    StaticBuilding_5(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_6 : public StaticBuilding
{
public:
    StaticBuilding_6(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};


class StaticBuilding_7 : public StaticBuilding
{
public:
    StaticBuilding_7(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_8 : public StaticBuilding
{
public:
    StaticBuilding_8(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_9 : public StaticBuilding
{
public:
    StaticBuilding_9(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_10 : public StaticBuilding
{
public:
    StaticBuilding_10(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};


class StaticBuilding_11 : public StaticBuilding
{
public:
    StaticBuilding_11(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};

class StaticBuilding_12 : public StaticBuilding
{
public:
    StaticBuilding_12(GamePlayer* _gamePlayer);
    virtual void completeCreate();
};



////////////////////////////////////////////////StaticUnit

class StaticUnit : public StaticVisibleObject
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
    
    int attackStartImageCount;
    int attackLoadImageCount;
    
public:
    StaticUnit(int _objectType, std::string _name, int _staticObjectState, GamePlayer* _gamePlayer);
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
    
    
    void setAttackLoadImageCount(int _attackLoadImageCount) { attackLoadImageCount = _attackLoadImageCount; }
    int getAttackLoadImageCount() { return attackLoadImageCount; }
    
    
    void setAttackStartImageCount(int _attackStartImageCount) { attackStartImageCount = _attackStartImageCount; }
    int getAttackStartImageCount() { return attackStartImageCount; }
    
};

class StaticUnit_1 : public StaticUnit
{
public:
    StaticUnit_1(GamePlayer* _gamePlayer);
    
};

class StaticUnit_2 : public StaticUnit
{
public:
    StaticUnit_2(GamePlayer* _gamePlayer);
    
};

class StaticUnit_3 : public StaticUnit
{
protected:
    int heal;
    bool isDetecting;
    
public:
    StaticUnit_3(GamePlayer* _gamePlayer);
    
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
    StaticUnit_4(GamePlayer* _gamePlayer);
    
    void setKnockBack(int _knockBack) { knockBack = _knockBack; }
    int getKnockBack() { return knockBack; }
    
};

class StaticUnit_5 : public StaticUnit
{
protected:
    int skillCount;
    int skillRange;
    
public:
    StaticUnit_5(GamePlayer* _gamePlayer);
    
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
    StaticUnit_6(GamePlayer* _gamePlayer);
    
    void setGraveCount(int _graveCount) { graveCount = _graveCount; }
    int getGraveCount() { return graveCount; }
    
};

class StaticUnit_7 : public StaticUnit
{
protected:
    bool isIgnoreDef;
    
public:
    StaticUnit_7(GamePlayer* _gamePlayer);
    
    void setIsIgnoreDef(bool _isIgnoreDef) { isIgnoreDef = _isIgnoreDef; }
    bool getIsIgnoreDef() { return isIgnoreDef; }
    
};

class StaticUnit_8 : public StaticUnit
{
protected:
    int shield;
    int autoAroundHeal;
    
public:
    StaticUnit_8(GamePlayer* _gamePlayer);
    
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
    StaticUnit_9(GamePlayer* _gamePlayer);
    
    void setAroundAtk(int _aroundAtk) { aroundAtk = _aroundAtk; }
    int getAroundAtk() { return aroundAtk; }
    
    void setAroundAtkRange(int _aroundAtkRange) { aroundAtkRange = _aroundAtkRange; }
    int getAroundAtkRange() { return aroundAtkRange; }
    
};

#endif /* StaticObject_h */
