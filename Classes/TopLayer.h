#ifndef __TOP_LAYER_H__
#define __TOP_LAYER_H__

#include "cocos2d.h"
#include "GameDefines.h"
#include "ui/CocosGUI.h"
#include "LinkedList.h"
#include "CustomButton.h"
#include "ObjectInfos.h"

#include <string>

using namespace cocos2d::ui;

class TopLayer : public cocos2d::Layer
{
private:
    cocos2d::Sprite* goldImage;
    cocos2d::Sprite* populationImage;
    
    cocos2d::Label* gold;
    cocos2d::Label* population;
    
public:
    void changeGold(int _gold);
    void changePopulation(int _population);
    
    
public:

	virtual bool init();


	// implement the "static create()" method manually
	CREATE_FUNC(TopLayer);
};

#endif // __CONTROLLAYER_H__
