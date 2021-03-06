#ifndef __NETWORK_MANAGER_H__
#define __NETWORK_MANAGER_H__

#include "BasicDefines.h"

#ifndef NOT_CONNECT_WITH_SERVER

#include "Network.h"

#define NetMgr NetworkManager::getInstance()

static char* IP_ADDRESS = "52.78.32.13";
static const unsigned short PORT = 20400;

enum SERVER_MODULE
{
    SERVER_MODULE_FRONT_SERVER = 0,
    SERVER_MODULE_LOBBY_SERVER,
    SERVER_MODULE_GAME_SERVER,
    SERVER_MODULE_CHATTING_SERVER,
};


class NetworkManager : public ReceiveHandler {
private:
    NetworkManager();
    ~NetworkManager();
public:
    
    static NetworkManager* instance;
    
public:
    
    static bool initInstance(char* ip, int port);
    
    static NetworkManager* getInstance() { return instance; }
    
    
    ///////////////////////////////////////////////////
    
    bool initialize(char* ip, int port);
    
    
    void Receive(ConnectInfo* connectInfo, const char* data, int dataSize) override;
    
    //////////////////////////////////HANDLE
    
    
    ////front
    
    void frontHandleFirstConnectRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void frontHandleLoginRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void frontHandleCreateAccountRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void frontHandleEnterLobbyRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    
    ////lobby
    void lobbyHandleFirstConnectRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleChannelInfoNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleFirstConnectOk(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleFirstConnectOut(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleGetChannelListRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleMoveChannelRes(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    
    void lobbyHandleGetUserInfoRes(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleEnterUserInChannelNotify(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleLeaveUserInChannelNotify(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleRequestGameRes(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleRequestGameNotify(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleRequestGameCancelRes(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    void lobbyHandleResponseGameNoNotify(ConnectInfo* connectInfo, const char* pData, int pDataSize);
    
    
    void lobbyHandleGetRoomListRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleCreateRoomRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleEnterRoomRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleEnterRoomNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleReadyRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleReadyNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleUnReadyRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleUnReadyNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleChangeTribeRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleChangeTribeNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleLeaveRoomRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleLeaveRoomNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleStartGameNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void lobbyHandleQuickPlayRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    
    ////game
    
    void gameHandleFirstConnectRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void gameHandleStartGameNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void gameHandleClientNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    void gameHandleFinishGameRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void gameHandleReconnectRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    
    ////chatting
    
    void chattingHandleFirstConnectRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void chattingHandleMoveLocationRes(ConnectInfo* connectInfo, const char* data, int dataSize);
    void chattingHandleSendChattingNotify(ConnectInfo* connectInfo, const char* data, int dataSize);
    
    
    ///////////////////// SEND
    
    
    void frontSendFirstConnectReq();
    void frontSendLoginReq(const char* userId, int16_t userIdLen);
    void frontSendCreateAccountReq(const char* userId, int16_t userIdLen, const char* nickName, int8_t nickNameLen);
    void frontSendEnterLobbyReq();
    void frontSendEnterLobbyOk();
    
    
    void lobbySendFirstConnectReq();
    void lobbySendGetChannelListReq();
    void lobbySendMoveChannelReq(int channelNo);
    
    void lobbySendGetUserInfoReq(const char* nickName, int8_t nickNameLen);
    void lobbySendRequestGameReq(const char* nickName, int8_t nickNameLen);
    void lobbySendRequestGameCancelReq();
    void lobbySendResponseGameYesReq(const char* nickName, int8_t nickNameLen);
    void lobbySendResponseGameNoReq(const char* nickName, int8_t nickNameLen);
    
    
    
    void lobbySendGetRoomListReq();
    void lobbySendCreateRoomReq(const char* roomName, int roomNameLen, int mapType);
    void lobbySendEnterRoomReq(int roomNo);
    void lobbySendReadyReq();
    void lobbySendUnReadyReq();
    void lobbySendChangeTribeReq(int tribe);
    void lobbySendLeaveRoomReq();
    void lobbySendQuickPlayReq(int tribe);
    
    
    void gameSendFirstConnectReq();
    void gameSendClientNotify(int bufferLen, const char* clientSendBuffer);
    void gameSendFinishGameReq();
    void gameSendMoveLobbyOk();
    void gameSendReconnectReq();
    
    void chattingSendFirstConnectReq();
    void chattingSendMoveLocationReq(int32_t loNo);
    void chattingSendSendChattingReq(const char* chatting, uint8_t chattingLen);
    
    int receiveData(int serverModule) { return network->receiveData(serverModule); }
    
public:
    
    Network* network;
    
    char sendBuffer[5000];
};

#else

#endif
#endif //__NETWORK_MANAGER_H__
