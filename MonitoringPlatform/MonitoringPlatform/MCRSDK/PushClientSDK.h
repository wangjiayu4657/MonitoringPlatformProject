/*
 * PushClientSDK.h
 *
 *  Created on: 2014-3-17
 *      Author: weilinfeng
 */

#ifndef PUSHCLIENTSDK_H_
#define PUSHCLIENTSDK_H_

#ifdef __cpluscplus
#define PUSHCLIENTSDK_API extern
#else
#define  PUSHCLIENTSDKAPI
#endif

#define CONNECTION_EXCEPTION 100

// 数据包类型
#define PUSH_PACKET_TYPE 0x02

/** @struct REVERSE_NOTIC_REQ_INFO
 *  @brief  反向通知请求结构体。
 *
 */
typedef struct REVERSE_NOTIC_REQ_INFO
{
    char mcuSessionId[128];     	// MCU会话ID
    int  seesionIdLen;          	// MCU会话ID长度
    char messageId[128];            // 消息在数据库中的主键值
    int  messageIdLen;				// 消息ID长度
    char messageType[128];      	// 消息类型
    int  messageTypeLen;        	// 消息类型长度
    char messageTitle[512];     	// 消息头含义
    int  messageTitleLen;       	// 消息头含义长度
    char messageTypeDescribe[512];  // 消息类型描述
    long long  messageTypeDescribeLen;    // 消息类型描述长度
    long long messageCreateTime;     	// 消息产生时间
    char iRet[16];              	// 保留
}RREVERSE_NOTIC_REQ_INFO, *PREVERSE_NOTIC_REQ_INFO;

/** @struct LUCENCY_IN_REQ_INFO
 *  @brief  请求透明通道（进）结构体。
 *
 */
typedef struct LUCENCY_IN_REQ_INFO
{
    char mcuSessionId[128]; // MCU会话ID
    int  seesionIdLen;      // MCU会话ID长度
    bool bExistDstInfo;     // 是否存在目标服务器信息，如果不存在，使用默认信息
    char dstIp[16];         // 目标服务器IP
    int  dstIpLen;          // 目标服务器IP长度
    int  dstPort;           // 目标服务器端口
    char data[1024];        // 透传数据
    int  dataLen;           // 透传数据长度
    char iRet[16];          // 保留
}RLUCENCY_IN_REQ_INFO, *PLUCENCY_IN_REQ_INFO;


typedef int (*pPacketLister)(int type, char* buffer, int buflen, void* pUser);
typedef int (*pConnectionLister)(int ErrorCode, void* pUser);

/** @fn bool PushClientInit()
 *   @brief 初始化push库
 *   @return true - 初始化成功; false - 初始化库失败
 */
PUSHCLIENTSDKAPI bool PushClientInit();

/** @fn bool PushClientFini()
 *   @brief 反初始化push库
 *   @return 无
 */
PUSHCLIENTSDKAPI void PushClientFini();

/** @fn bool PushClientConnect(void* handle)
 *   @brief 与服务器建立连接
 *   @param [in] IP - 服务器ip地址
 *   @param [in] port - 服务器端口
 *   @param [in] sessionId - msp之间的session
 *   @param [in] pUser - 用户数据
 *   @param [out] 无
 *   @return >0表示连接成功， <0表示连接失败
 */
PUSHCLIENTSDKAPI int PushClientConnect(const char *ip, int port, const char* sessionId, void* pUser);

/** @fn bool PushClientDisConnect(void* handle)
 *   @brief 与服务器建立连接
 *   @return >0表示连接成功， <0表示连接失败
 */
PUSHCLIENTSDKAPI void PushClientDisConnect();

/** @fn bool PushClientSetPacketLister(void* handle)
 *   @brief 设置数据包回调
 *   @param [in] packetLister - 数据回调函数指针
 *   @return true - 成功, false - 失败
 */
PUSHCLIENTSDKAPI bool PushClientSetPacketLister(pPacketLister packetLister);

/** @fn bool PushClientSetConnectionLister(void* handle)
 *   @brief 设置 连接回调
 *   @param [in] packetLister - 连接回调函数指针
 *   @return true - 成功, false - 失败
 */
PUSHCLIENTSDKAPI bool PushClientSetConnectionLister(pConnectionLister connectionLister);

#endif /* PUSHCLIENTSDK_H_ */
