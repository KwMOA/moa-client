
#include "AiPlayer.h"
#include "GameWorldImpl.hpp"
#include "TaskManager.h"
#include "GameManager.hpp"
#include "ClientInput.h"
#include "GameDefines.h"
#include "BaseObject.hpp"
#include "CheckCreateAvailable.hpp"

AIPlayer::AIPlayer(GameWorld* _gameWorld, int _aiType, int _playerIndex) : GamePlayer(_gameWorld, _playerIndex)
{
    aiType = _aiType;
    currentTick = 0;
    checker = new CheckCreateAvailable(this);
}


void AIPlayer::update(long dt)
{
    GamePlayer::update(dt);
    
    currentTick++;
    
    if(currentTick == 100) {
        CreateUnitCI* ci = new CreateUnitCI();
        ci->objectType = OBJECT_TYPE_UNIT_1;
        ci->objectNo = getBuildingByObjectType(OBJECT_TYPE_BUILDING_3)->getObjectNo();
        ci->objectCount = 1;
        ci->lineNo = 1;
        ((GameWorldImpl*)getGameWorld())->getGameManager()->getTaskManager()->pushBackAITask(ci);
    }
    if(currentTick == 120) {
        CreateUnitCI* ci = new CreateUnitCI();
        ci->objectType = OBJECT_TYPE_UNIT_1;
        ci->objectNo = getBuildingByObjectType(OBJECT_TYPE_BUILDING_3)->getObjectNo();
        ci->objectCount = 1;
        ci->lineNo = 1;
        ((GameWorldImpl*)getGameWorld())->getGameManager()->getTaskManager()->pushBackAITask(ci);
    }
}
