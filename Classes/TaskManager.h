#ifndef __TASK_MANAGER_H__
#define __TASK_MANAGER_H__


#include <list>
#include <vector>
#include <functional>
#include <queue>
#include "ClientInput.h"

//#define TaskMgr TaskManager::Instance()

class GameManager;
class GameWorld;

class TaskManager{
private:
    GameManager* gameManager;
    GameWorld* m_pGameWorld;
    
    //내 컴퓨터의 일들
    std::list<ClientInputWithPacketNo> myTask;
    int myTaskPacketNo;

    //상대방 컴퓨터의 일들
    std::list<ClientInputWithPacketNo> enemyTask;
    int enemyTaskPacketNo;
    
    //서버로 전송해야 할 일들
    std::list<ClientInput*> dispatchTask;
    
    //내가 무슨 컴퓨터인지 ? A?B? [ 0 : A, 1 : B ]
    int iPlayerFlag;
    
    //네트워크 메시지 업데이트 처리 횟수
    int iCntCarryOutMessages;
    
    //해당 패킷의 내 컴퓨터의 일을 처리한다.
    void carryOutMyTask(int _packetNo);
    
    //해당 패킷의 상대방 컴퓨터의 일을 처리한다.
    void carryOutEnemyTask(int _packetNo);
    
    //메인 메시지 일 처리 함수
    void carryOutTask(ClientInput* pClientInput, int packetNo, int _iPlayerFlag);
    
    
public:
    TaskManager(GameManager* _gameManager);
    ~TaskManager();
    
    static TaskManager* Instance();
public:
    //A 컴퓨터 B 컴퓨터를 정해주기.
    void setupWhatPlayerFlag();
    
    //해당 Message를 DispatchTask에 보낸다.
    void pushBackMessage(ClientInput* ci);
    
    //해당 Message를 DispatchTask에 보낸다.
    void pushBackAITask(ClientInput* ci);
    
    //DispatchTask에 쌓인 Message를 서버로 보낸 후, Task에 전송한다.
    void dispatchToServer();
    
    //서버에서 상대방 클라이언트의 Message를 받은 후, Task에 전송한다.
    void fetchFromServer(int length, const char* str);
    
    //Task에 쌓인 메시지들을 모두 수행한다.
    bool carryOutMessages();
    
    //GameWorld를 설정한다.
    void setGameWorld(GameWorld* pGame){m_pGameWorld = pGame;}
    
    //해당 컴퓨터가 A 컴퓨터인지, B 컴퓨터인지 플레이어 번호를 얻어온다.
    int getPlayerFlag(){ return iPlayerFlag; }
    
    //네트워크 메시지 업데이트 처리 횟수
    int getCntCarryOutMessages()const{return iCntCarryOutMessages;}
    
    //통신 두절 상태이냐?
    bool isCommunicate()const;
    
    //게터 세터
    int getMyTaskPacketNo()const{return myTaskPacketNo;}
    
    int getEnemyTaskPacketNo()const{return enemyTaskPacketNo;}
    
    int getMyTaskSize()const{return (int)myTask.size();}
    
    int getEnemeyTaskSize()const{return (int)enemyTask.size();}
    
    int getMyFrontPacketNo()const{return myTask.front().packetNo;}
    
    int getEnemyFrontPacketNo()const{return enemyTask.front().packetNo;}
};

#endif //__TASK_MANAGER_H__
