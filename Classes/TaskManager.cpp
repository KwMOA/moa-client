#include "TaskManager.h"
#include "cocos2d.h"

#include "GameDefines.h"
#include "BasicDefines.h"
#include "GameWorld.h"
#include "GameClient.h"
#include "LogManager.h"
#include "GameManager.h"
#include "GameScene.h"
#include "NetworkManager.h"
USING_NS_CC;

TaskManager::TaskManager(GameManager* _gameManager)
{
    myTaskPacketNo = 2;
    enemyTaskPacketNo = 2;
    iCntCarryOutMessages = 0;

    setupWhatPlayerFlag();
    
    gameManager = _gameManager;
    
    //초기화시 각 Task에 0번, 1번, 2번 더미 패킷을 한개씩 넣어놓는다.
    for(int i=0;i<2;i++){
        myTask.push_back(ClientInputWithPacketNo(i,NULL));
        enemyTask.push_back(ClientInputWithPacketNo(i,NULL));
    }
    
}

TaskManager::~TaskManager(){
}

void TaskManager::setupWhatPlayerFlag(){

//    if(PLAY_ALONE){
//        iPlayerFlag = 0;
//    }else{        
//        //플레이어 A인가?
//        if(GameClient::GetInstance().myGameIndex == 0){
//            iPlayerFlag = 0;
//        }else{
//            iPlayerFlag = 1;
//        }
//    }
    
    //set my index 0
    iPlayerFlag = 0;
}
//DispatchTask에 쌓인 Message를 서버로 보낸 후, Task에 전송한다.
void TaskManager::dispatchToServer(){
    //메시지의 갯수
    int clientInputCount = (int)dispatchTask.size();
    
    char buffer[5000];
    memset(buffer,0,5000);
    
    int nextBuffer = 0;
    if(clientInputCount > 0){
        
        for(int i=0;i<clientInputCount;i++){
            ClientInput* ci = dispatchTask.front();
            
            //메시지 타입 저장
            memcpy(&buffer[nextBuffer], &ci->inputType, sizeof(int8_t));
            nextBuffer += sizeof(int8_t);
            
            //메시지 타입별로 저장한다.
            switch(ci->inputType){
                case CLIENT_INPUT_TYPE_CREATE_BUILDING:
                {
                    CreateBuildingCI* createBuildingCI = (CreateBuildingCI*)ci;
                    
                    memcpy(&buffer[nextBuffer], &createBuildingCI->objectType, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    break;
                }
                case CLIENT_INPUT_TYPE_CANCEL_CREATE_BUILDING:
                {
                    CancelCreateBuildingCI* cancelCreateBuildingCI = (CancelCreateBuildingCI*)ci;
                    
                    memcpy(&buffer[nextBuffer], &cancelCreateBuildingCI->objectNo, sizeof(int32_t));
                    nextBuffer += sizeof(int32_t);
                    
                    break;
                }
                case CLIENT_INPUT_TYPE_UPGRADE_BUILDING:
                {
                    UpgradeBuildingCI* upgradeBuildingCI = (UpgradeBuildingCI*)ci;
                    
                    memcpy(&buffer[nextBuffer], &upgradeBuildingCI->objectNo, sizeof(int32_t));
                    nextBuffer += sizeof(int32_t);
                    
                    memcpy(&buffer[nextBuffer], &upgradeBuildingCI->upgradeType, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    break;
                }
                case CLIENT_INPUT_TYPE_CANCEL_UPGRADE_BUILDING:
                {
                    CancelUpgradeBuildingCI* cancelUpgradeBuildingCI = (CancelUpgradeBuildingCI*)ci;
                    
                    memcpy(&buffer[nextBuffer], &cancelUpgradeBuildingCI->objectNo, sizeof(int32_t));
                    nextBuffer += sizeof(int32_t);
                    
                    memcpy(&buffer[nextBuffer], &cancelUpgradeBuildingCI->upgradeType, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    break;
                }
                case CLIENT_INPUT_TYPE_CREATE_UNIT:
                {
                    CreateUnitCI* createUnitCI = (CreateUnitCI*)ci;
                    
                    memcpy(&buffer[nextBuffer], &createUnitCI->objectNo, sizeof(int32_t));
                    nextBuffer += sizeof(int32_t);
                    
                    memcpy(&buffer[nextBuffer], &createUnitCI->objectType, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    memcpy(&buffer[nextBuffer], &createUnitCI->objectCount, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    memcpy(&buffer[nextBuffer], &createUnitCI->lineNo, sizeof(int8_t));
                    nextBuffer += sizeof(int8_t);
                    
                    break;
                }
            }
            
            myTask.push_back(ClientInputWithPacketNo(myTaskPacketNo, ci));
            dispatchTask.pop_front();
        }
        
        //서버로 buffer를 보낸다.
        if(PLAY_ALONE) {
//            fetchFromServer(nextBuffer, buffer);
        } else {
#ifndef NOT_CONNECT_WITH_SERVER

            NetMgr->gameSendClientNotify(nextBuffer,buffer);
#else

#endif
        }
    
    } else {
        
        //빈 메시지를 보낸다.
        myTask.push_back(ClientInputWithPacketNo(myTaskPacketNo, NULL));
        
        
        if(PLAY_ALONE) {
//            fetchFromServer(0, buffer);
        } else {
#ifndef NOT_CONNECT_WITH_SERVER
		
            NetMgr->gameSendClientNotify(0, buffer);
#else

#endif
        }
    }
    
    myTaskPacketNo++;
    
    if(PLAY_ALONE) {
        if(enemyTask.back().packetNo != enemyTaskPacketNo) {
            enemyTask.push_back(ClientInputWithPacketNo(enemyTaskPacketNo, NULL));
        }
        
        enemyTaskPacketNo++;
    }
}

//서버에서 상대방 클라이언트의 Message를 받은 후, Task에 전송한다.
void TaskManager::fetchFromServer(int length, const char* str){
    
    if(PLAY_ALONE) {
        
    } else {
        int nextBuffer = 0;
        
        if(length > 0){
            
            while(nextBuffer < length){
                //메시지 종류를 확인한다.
                int8_t inputType;
                memcpy(&inputType,str+nextBuffer,sizeof(int8_t));
                nextBuffer += sizeof(int8_t);
                
    //            //시간초 동기화 처리
    //            if(messageType == TelegramType::Time){
    //                float time;
    //                memcpy(&time,str+nextBuffer,sizeof(float));
    //                nextBuffer += sizeof(float);
    //                m_pGameWorld->SetStartFrame(time);
    //                continue;
    //            }
                
                ClientInput* ci;
                
                //메시지 타입별로 저장한다.
                switch(inputType){
                    case CLIENT_INPUT_TYPE_CREATE_BUILDING:
                    {
                        CreateBuildingCI* createBuildingCI = new CreateBuildingCI();
                        
                        memcpy(&createBuildingCI->objectType, str+nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        ci = createBuildingCI;
                        
                        break;
                    }
                    case CLIENT_INPUT_TYPE_CANCEL_CREATE_BUILDING:
                    {
                        CancelCreateBuildingCI* cancelCreateBuildingCI = new CancelCreateBuildingCI();
                        
                        memcpy(&cancelCreateBuildingCI->objectNo, str + nextBuffer, sizeof(int32_t));
                        nextBuffer += sizeof(int32_t);
                        
                        ci = cancelCreateBuildingCI;
                        
                        break;
                    }
                    case CLIENT_INPUT_TYPE_UPGRADE_BUILDING:
                    {
                        UpgradeBuildingCI* upgradeBuildingCI = new UpgradeBuildingCI();
                        
                        memcpy(&upgradeBuildingCI->objectNo, str + nextBuffer, sizeof(int32_t));
                        nextBuffer += sizeof(int32_t);
                        
                        memcpy(&upgradeBuildingCI->upgradeType, str + nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        ci = upgradeBuildingCI;
                        
                        break;
                    }
                    case CLIENT_INPUT_TYPE_CANCEL_UPGRADE_BUILDING:
                    {
                        CancelUpgradeBuildingCI* cancelUpgradeBuildingCI = new CancelUpgradeBuildingCI();
                        
                        memcpy(&cancelUpgradeBuildingCI->objectNo, str + nextBuffer, sizeof(int32_t));
                        nextBuffer += sizeof(int32_t);
                        
                        memcpy(&cancelUpgradeBuildingCI->upgradeType, str + nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        ci = cancelUpgradeBuildingCI;
                        
                        break;
                    }
                    case CLIENT_INPUT_TYPE_CREATE_UNIT:
                    {
                        CreateUnitCI* createUnitCI = new CreateUnitCI();
                        
                        memcpy(&createUnitCI->objectNo, str + nextBuffer, sizeof(int32_t));
                        nextBuffer += sizeof(int32_t);
                        
                        memcpy(&createUnitCI->objectType, str + nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        memcpy(&createUnitCI->objectCount, str + nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        memcpy(&createUnitCI->lineNo, str + nextBuffer, sizeof(int8_t));
                        nextBuffer += sizeof(int8_t);
                        
                        ci = createUnitCI;
                        
                        break;
                    }
                }
                
                ci->inputType = inputType;
                
                ClientInputWithPacketNo ciP(enemyTaskPacketNo, ci);
                enemyTask.push_back(ciP);
            }
            
        }else{
            //패킷이 비었지만 통신이 왔다.
            enemyTask.push_back(ClientInputWithPacketNo(enemyTaskPacketNo, NULL));
        }
    }
    enemyTaskPacketNo++;
}

//해당 Message를 DispatchTask에 보낸다.
void TaskManager::pushBackMessage(ClientInput* ci){
    dispatchTask.push_back(ci);
}

//해당 Message를 DispatchTask에 보낸다.
void TaskManager::pushBackAITask(ClientInput* ci){
    ClientInputWithPacketNo ciP(enemyTaskPacketNo, ci);
    enemyTask.push_back(ciP);
}

//Task에 쌓인 메시지들을 모두 수행한다.
void TaskManager::carryOutMessages(){
    iCntCarryOutMessages++;
    
    //상대방 컴퓨터와 통신이 두절되었는지 확인한다.
    if(!isCommunicate()){
        //통신이 두절
        LogMgr->Log("통신 두절");
        return ;
    }
    //현재 처리하는 패킷이 통신하는 패킷 번호보다 3보다 작거나 같을 때까지 모두 처리한다.
    while(myTask.front().packetNo < myTaskPacketNo - 2)
    {
        if(enemyTask.size() <= 0)
            break;
        
        int currentPacketNo = myTask.front().packetNo;
        
        
        //내가 A 컴퓨터이면 내 일을 먼저 처리한다.
        if(iPlayerFlag == 0){
            carryOutMyTask(currentPacketNo);
            carryOutEnemyTask(currentPacketNo);
        }else{  //B 컴퓨터이면 상대방 일을 먼저 처리한다.
            carryOutEnemyTask(currentPacketNo);
            carryOutMyTask(currentPacketNo);
        }
        
        //게임 업데이트
//        m_pGameWorld->updateSynch();
    }

}
//메인 일 처리 함수
void TaskManager::carryOutTask(ClientInput* pCi, int packetNo, int _iPlayerFlag){
    
    if(pCi == NULL)
        return;
    
    switch(pCi->inputType){
            
            
        case CLIENT_INPUT_TYPE_CREATE_BUILDING:
        {
            CreateBuildingCI* createBuildingCI = (CreateBuildingCI*)pCi;
            gameManager->getGameWorld()->createBuilding(_iPlayerFlag, createBuildingCI->objectType);
            
            break;
            
        }
        case CLIENT_INPUT_TYPE_CANCEL_CREATE_BUILDING:
        {
            CancelCreateBuildingCI* cancelCreateBuildingCI = (CancelCreateBuildingCI*)pCi;
            
            gameManager->getGameWorld()->cancelCreateBuilding(_iPlayerFlag, cancelCreateBuildingCI->objectNo);
            
            break;
        }
        case CLIENT_INPUT_TYPE_UPGRADE_BUILDING:
        {
            UpgradeBuildingCI* upgradeBuildingCI = (UpgradeBuildingCI*)pCi;
            
            gameManager->getGameWorld()->upgradeBuilding(_iPlayerFlag, upgradeBuildingCI->objectNo, upgradeBuildingCI->upgradeType);
            
            break;
        }
        case CLIENT_INPUT_TYPE_CANCEL_UPGRADE_BUILDING:
        {
            CancelUpgradeBuildingCI* cancelUpgradeBuildingCI = (CancelUpgradeBuildingCI*)pCi;
            
            gameManager->getGameWorld()->cancelUpgradeBuilding(_iPlayerFlag, cancelUpgradeBuildingCI->objectNo, cancelUpgradeBuildingCI->upgradeType);
            
            break;
        }
        case CLIENT_INPUT_TYPE_CREATE_UNIT:
        {
            CreateUnitCI* createUnitCI = (CreateUnitCI*)pCi;

            gameManager->getGameWorld()->createUnit(_iPlayerFlag, createUnitCI->objectNo, createUnitCI->objectType, createUnitCI->objectCount, createUnitCI->lineNo);
            
            break;
        }
        default:
        {
            break;
        }
    }
}
//내 컴퓨터의 일을 처리한다.
void TaskManager::carryOutMyTask(int _packetNo){
    while(!myTask.empty() && myTask.front().packetNo == _packetNo)
    {
        carryOutTask(myTask.front().ci, myTask.front().packetNo, iPlayerFlag);
        myTask.pop_front();
    }
}

//상대방 컴퓨터의 일을 처리한다.
void TaskManager::carryOutEnemyTask(int _packetNo){
    
    int enemyNo = 0;
    if(iPlayerFlag == 0) {
        enemyNo = 1;
    }
    
    while(!enemyTask.empty() && enemyTask.front().packetNo == _packetNo)
    {
        //혼자 실행용이면 다음 구문을 실행하지 않는다.
        carryOutTask(enemyTask.front().ci, enemyTask.front().packetNo, enemyNo);
        
        enemyTask.pop_front();
    }
    
}

//통신이 두절되었나 확인한다.
bool TaskManager::isCommunicate()const{
    //상대방에게 날아온 메시지가 비어있다면, 또는 두 컴퓨터의 패킷 차이가 3이상 차이가 난다면
    return !enemyTask.empty();
}


//
////AutoTask의 일들을 처리한다.
//void NetworkManager::CarryOutAutoTask(int _packet){
//    if(AutoTaskQueue.empty())
//        return;
//    
//    //만약 AutoTaskQueue의 top 패킷이 현재 패킷보다 느리다면 그냥 지워버린다. (그런 현상은 원래 발생해선 안된다!)
//    while(AutoTaskQueue.top()->packet < _packet){
//        auto pTask = AutoTaskQueue.top();
//        AutoTaskQueue.pop();
//        delete pTask;
//        LogMgr->Log("AutoTaskQueue.pop() 치명적 오류!!");
//    }
//    
//    while(!AutoTaskQueue.empty() &&
//          AutoTaskQueue.top()->packet == _packet){
//        
//        //일을 처리면서 Queue에서 빼낸다.
//        AutoTask* pTask = AutoTaskQueue.top();
//        AutoTaskQueue.pop();
//        
//        switch(pTask->messageType){
//            case AutoTaskType::Move:
//            {
//                auto pMove = (AutoTaskMove*)pTask;
//                //유닛 리스트를 얻어온다.
//                auto Units = m_pGameWorld->GetUnits();
//                
//                //해당 유닛의 포인터를 가져온다.
//                auto pUnit = Units[pMove->unitID];
//                
//                if(!pUnit)
//                    break;
//                
//                //해당 유닛이 죽었다면 실행시키지 않는다.
//                if(pUnit->IsDead())
//                    break;
//                    
//                //만약 유닛의 AutoTaskPacket과 동기화 되어 있지 않다면 실행시키지 않는다.
//                if(!pUnit->IsValidAutoTask(pMove->packet))
//                    break;
//                
//                //해당 유닛을 이동시킨다.
//                pUnit->MoveToPathFront(pMove->packet);
//            }
//                break;
//            case AutoTaskType::Attack:
//            {
//                auto pAttack = (AutoTaskAttack*)pTask;
//                //유닛 리스트를 얻어온다.
//                auto Units = m_pGameWorld->GetUnits();
//                
//                //해당 유닛의 포인터를 가져온다.
//                auto pUnit = Units[pAttack->unitID];
//                
//                if(!pUnit)
//                    break;
//                
//                //해당 유닛이 죽었다면 실행시키지 않는다.
//                if(pUnit->IsDead())
//                    break;
//                
//                //만약 유닛의 AutoTaskPacket과 동기화 되어 있지 않다면 실행시키지 않는다.
//                if(!pUnit->IsValidAutoTask(pAttack->packet))
//                    break;
//                
//                //해당 유닛을 이동시킨다.
//                pUnit->AttackTarget(pAttack->packet);
//            }
//                break;
//        }
//        delete pTask;
//    }
//}

