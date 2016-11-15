
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
}


void AIPlayer::update(int updateCount)
{
    GamePlayer::update(updateCount);
    
    currentTick++;
    
//    if(currentTick == 100) {
//        CreateUnitCI* ci = new CreateUnitCI();
//        ci->objectType = OBJECT_TYPE_UNIT_1;
//        ci->objectNo = getBuildingByObjectType(OBJECT_TYPE_BUILDING_3)->getObjectNo();
//        ci->objectCount = 1;
//        ci->lineNo = 1;
//        getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci);
//    }
//    if(currentTick == 120) {
//        CreateUnitCI* ci = new CreateUnitCI();
//        ci->objectType = OBJECT_TYPE_UNIT_1;
//        ci->objectNo = getBuildingByObjectType(OBJECT_TYPE_BUILDING_3)->getObjectNo();
//        ci->objectCount = 1;
//        ci->lineNo = 1;
//        getGameWorld()->getGameManager()->getTaskManager()->pushBackAITask(ci);
//    }
}
