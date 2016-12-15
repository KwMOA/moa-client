#ifndef __RESULT_LAYER_H__
#define __RESULT_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include <string>

class GameScene;
class ResultLayer : public cocos2d::Layer
{
private:
    GameScene* gameScene;
public:

	virtual bool init();
    
    void setResult(GameScene* _gameScene, int result);
    
    
    // implement the "static create()" method manually
	CREATE_FUNC(ResultLayer);
};

#endif // __INFO_LAYER_H__
