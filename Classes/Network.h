
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <stdint.h>

#define MAX_FD_COUNT 10

#define MAX_BUFFER_LEN 5000

enum DATA_TYPE
{
    DATA_TYPE_REQ = 64,
    DATA_TYPE_PING_NOTIFY,
    DATA_TYPE_PING_OK,
};

typedef int8_t dataType_t;
typedef uint64_t dataSize_t;

#pragma pack(push, 1)
struct DataHeader
{
    dataType_t dataType;
    dataSize_t dataSize;
};
#pragma pack(pop)

class TempBufferInfo
{
public:
    TempBufferInfo();
    ~TempBufferInfo();
    void clear();
    bool isEmpty();
    
    int tempBufferSize;
    char* tempBuffer;
};

class ConnectInfo
{
public:
    ConnectInfo();
    ~ConnectInfo();
    void clear();
    
    int fd;
    int serverModule;
    TempBufferInfo tempBufferInfo;
};

class ReceiveHandler
{
public:
    virtual void Receive(ConnectInfo* connectInfo, const char* data, int dataSize) = 0;
};

class Network
{
public:
    Network();
    ~Network();
    bool initialize(ReceiveHandler* _receiveHandler);
    int connectWithServer(int serverModule, const char* ip, unsigned short port);
    int receiveData(int serverModule);
    bool sendPacket(int serverModule, const char* data, int dataSize);
    bool disconnectWithServer(int serverModule);

private:
    bool sendData(int fd, const char* data, int dataSize);
    ConnectInfo* getConnectInfo(int serverModule);

private:
    ConnectInfo fdArray[10];
    char recvBuffer[MAX_BUFFER_LEN + 1];
    DataHeader dataHeader;
    ReceiveHandler* receiveHandler;
    
public:
    int testNum = 0;
};


#endif // __NETWORK_H__
