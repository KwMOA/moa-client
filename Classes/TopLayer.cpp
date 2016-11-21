#include "TopLayer.h"

USING_NS_CC;


bool TopLayer::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
    
    // add "HelloWorld" splash screen"
    goldImage = Sprite::create("gold_image.png");
    
    // position the sprite on the center of the screen
    goldImage->setPosition(Vec2(DISPLAY_WIDTH - 180, DISPLAY_HEIGHT - 15));
    goldImage->setScale(0.05, 0.05);
    goldImage->setAnchorPoint(Vec2(0.5, 0.5));
    // add the sprite as a child to this layer
    this->addChild(goldImage, 0);
    
    
    gold = Label::createWithTTF("100", "fonts/Marker Felt.ttf", 16);
    gold->setPosition(Vec2(DISPLAY_WIDTH - 150, DISPLAY_HEIGHT - 15));
    gold->setAnchorPoint(Vec2(0.5, 0.5));
    
    // add the label as a child to this layer
    this->addChild(gold, 1);
    
    
    // add "HelloWorld" splash screen"
    populationImage = Sprite::create("population_image.png");
    
    // position the sprite on the center of the screen
    populationImage->setPosition(Vec2(DISPLAY_WIDTH - 80, DISPLAY_HEIGHT - 15));
    populationImage->setScale(0.05, 0.05);
    populationImage->setAnchorPoint(Vec2(0.5, 0.5));
    // add the sprite as a child to this layer
    this->addChild(populationImage, 0);
    
    population = Label::createWithTTF("0/100", "fonts/Marker Felt.ttf", 16);
    population->setPosition(Vec2(DISPLAY_WIDTH - 50, DISPLAY_HEIGHT - 15));
    population->setAnchorPoint(Vec2(0.5, 0.5));
    // add the label as a child to this layer
    this->addChild(population, 1);
    
    
    return true;
}

void TopLayer::changeGold(int _gold)
{
    char buf[20] = {0, };
    sprintf(buf, "%d", _gold);
    gold->setString(buf);
}


void TopLayer::changePopulation(int _population)
{
    char buf[8] = {0, };
    sprintf(buf, "%d/100", _population);
    population->setString(buf);
}

