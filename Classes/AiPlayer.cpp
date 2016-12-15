
#include "AiPlayer.h"
#include "GameWorld.h"
#include "TaskManager.h"
#include "GameManager.h"
#include "ClientInput.h"
#include "GameDefines.h"
#include "BaseObject.h"

AIPlayer::AIPlayer(GameWorld* _gameWorld, int _aiType, int _playerIndex) : GamePlayer(_gameWorld, _playerIndex)
{
    aiType = _aiType;
    currentTick = 0;
    testUnitCreateNum = 0;
    
    setGold(100000000);
}


void AIPlayer::update(int updateCount)
{
    GamePlayer::update(updateCount);
    
    currentTick++;
    
    if(testUnitCreateNum > 190) {
        testUnitCreateNum = 190;
    }
    
    if((currentTick) % (200 - testUnitCreateNum) == 0) {
        testUnitCreateNum += 10;
        {
        CreateUnitCI* ci1 = new CreateUnitCI();
        ci1->objectType = OBJECT_TYPE_UNIT_1;
        ci1->objectNo = 0;
        ci1->objectCount = 1;
        ci1->lineNo = 1;
        getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci1);
        
        CreateUnitCI* ci2 = new CreateUnitCI();
        ci2->objectType = OBJECT_TYPE_UNIT_1;
        ci2->objectNo = 0;
        ci2->objectCount = 1;
        ci2->lineNo = 2;
        getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci2);
        
        CreateUnitCI* ci3 = new CreateUnitCI();
        ci3->objectType = OBJECT_TYPE_UNIT_1;
        ci3->objectNo = 0;
        ci3->objectCount = 1;
        ci3->lineNo = 3;
        getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci3);
        }
        {
            CreateUnitCI* ci1 = new CreateUnitCI();
            ci1->objectType = OBJECT_TYPE_UNIT_2;
            ci1->objectNo = 0;
            ci1->objectCount = 1;
            ci1->lineNo = 1;
            getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci1);
            
            CreateUnitCI* ci2 = new CreateUnitCI();
            ci2->objectType = OBJECT_TYPE_UNIT_2;
            ci2->objectNo = 0;
            ci2->objectCount = 1;
            ci2->lineNo = 2;
            getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci2);
            
            CreateUnitCI* ci3 = new CreateUnitCI();
            ci3->objectType = OBJECT_TYPE_UNIT_2;
            ci3->objectNo = 0;
            ci3->objectCount = 1;
            ci3->lineNo = 3;
            getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci3);
            
        }
    }
}
