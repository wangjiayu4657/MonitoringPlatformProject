/** @file RtspClient.h
 *   @note HangZhou Hikvision System Technology Co., Ltd. All Right Reserved.
 *   @brief RTSP通信库头文件
 *  This file defines the API for RtspClient.dll
 *   @author     Weilinfeng
 *   @date       2010-09-07
 *
 *   @note Created By Weilinfeng 2010-09-07
 *   @note Added vtdu stack error code By Huyafeng 2015-03-23
 *
 *
 *   @warning
 */

#ifndef __RTSPCLIENTSDK_H__
#define __RTSPCLIENTSDK_H__

#ifdef __cpluscplus
#define RTSPCLIENTSDK_API extern
#else
#define  RTSPCLIENTSDKAPI
#endif

//#ifdef __cplusplus
//extern "C"
//{
//#endif

//#define TEST

#define RTSP_BASE_PORT				10000
#define RTSPCLIENT_MAXNUM			32

#define RTSPCLIENT_INVALIDATE_ENGINEID		-1

// 主码流
#define STREAM_TYPE_MAIN 0
// 子码流
#define STREAM_TYPE_SUB 1

/** RTP封装格式 */
#define SYSTEM_TYPE_RTP 0
/** PS封装格式*/
#define SYSTEM_TYPE_PS 1
/** MPEG4编码格式 */
#define VIDEO_TYPE_MPEG4 0
/** H264编码格式 */
#define VIDEO_TYPE_H264 1

//QCIF 176*144
#define QCIF 0
//QVAG 320*240
#define QVAG 1
//CIF 352*288
#define CIF 2
//2CIF 704*288
#define TWOCIF 3
//D1 720*576
#define D1 4

// 级联
#define CASCADE_TYPE_YES 1
// 非级联
#define CASCADE_TYPE_NO 0
// 互联网
#define NETWORK_TYPE_INTERNET 1
// 局域网
#define NETWORK_TYPE_LOCAL 0


#define RTSP_NPT_TIMETYPE                   0x8100  //NPT时间
#define RTSP_SMPTE_TIMETYPE                 0x8101	//SMPTE时间
#define RTSP_CLOCK_TIMETYPE                 0x8102	//壁钟时间

/******************************传输方式********************************************************/
#define RTPTCP_TRANSMODE				    0x0000	//RTP over TCP
#define RTPUDP_TRANSMODE				    0x0001	//RTP over UDP
#define RTPRTSP_TRANSMODE				    0x0003	//RTP over RTSP
#define RTPUDP_RELIABLE_TRANSMODE		    0x0004	//Reliable RTP over UDP
#define RTPMCAST_TRANSMODE				    0x0005	//RTP over multicast

/******************************流类型********************************************************/
#define DATATYPE_HEADER					    1		//头数据
#define DATATYPE_STREAM					    2		//流数据


#define RTSPCLIENT_INVALIDATE_ENGINEID		-1


/******************************错误码********************************************************/

#define RTSPCLIENT_HPR_INIT_FAIL 						1 // HPR初始化失败
#define RTSPCLIENT_MSG_MANAGE_RUN_FAIL					2 // 消息队列启动失败
#define RTSPCLIENT_NO_INIT								3 // RtspClient未初始化
#define RTSPCLIENT_PROTOCOL_NOTSUPPORT      			4 // 协议不支持
#define RTSPCLIENT_CALLBACK_PARAM_NULL					5 // 回调参数为空
#define RTSPCLIENT_MOLLOC_RTSPENGINE_FAIL				6 // 创建Rtsp引擎失败
#define RTSPCLIENT_RTSPENGINE_EXCEED_ERROR				7 // 分配Rtsp引擎数超过最大数（32）
#define RTSPCLIENT_ENGINEID_INVALID						8 // 无效的引擎ID
#define RTSPCLIENT_ENGINE_NOT_EXSIT						9 // 引擎不存在
#define RTSPCLIENT_ENGINE_NULL							10 // 引擎为空
#define RTSPCLIENT_START_TIME_NULL						11 // 开始时间为空
#define RTSPCLIENT_DEV_NAMEORPSW_NULL					12 // 设备名称或者密码为空
#define RTSPCLIENT_BASEPORT_ERROR						13 // 错误的基础端口号
#define RTSPCLIENT_MALLOC_MEMORY_FAIL					14 // 内存分配失败
#define RTSPCLIENT_ENGINEER_NOINIT						15 // 引擎未初始化
#define RTSPCLIENT_VERSION_PROTOCOL_NOTSUPPORT			16 // MAG、VTDU4.0不支持Rtp or Tcp
#define RTSPCLIENT_RTSPURL_ERROR						17 // Rtsp地址错误
#define RTSPCLIENT_CONNECT_SERVER_FAIL					18 // 连接流媒体服务器失败
#define RTSPCLIENT_NO_PLAY_STATE						19	// 不在播放状态

#define RTSPCLIENT_DECRIBE_REDIRCT_FAIL					101 // Describe重定向失败
#define RTSPCLIENT_GENERATE_DESCRIBE_FAIL				102 // 生成Describe信令失败
#define RTSPCLIENT_SEND_DESCRIBE_FAIL					103 // 发送Describe信令失败
#define RTSPCLIENT_RECV_DESCRIBE_FAIL					104 // 接受Describe信令失败
#define RTSPCLIENT_DESCRIBE_STATUS_NO_200OK				105 // Describe回复非200OK
#define RTSPCLIENT_PARSE_DESCRIBE_FAIL					106 // Describe解析失败

#define RTSPCLIENT_GENERATE_SETUP_FAIL					201 // 生成Setup信令失败
#define RTSPCLIENT_SEND_SETUP_FAIL						202 // 发送Setup信令失败
#define RTSPCLIENT_RECV_SETUP_FAIL						203 // 接收Setup信令失败
#define RTSPCLIENT_SETUP_STATUS_NO_200OK				204 // Setup回复非200OK
#define RTSPCLIENT_PARSE_SETUP_FAIL						205 // 解析Setup失败

#define RTSPCLIENT_GENERATE_PLAY_FAIL					301 // 生成Play信令失败
#define RTSPCLIENT_SEND_PLAY_FAIL						302 // 发送Play信令失败
#define RTSPCLIENT_RECV_PLAY_FAIL						303 // 接收Play信令失败
#define RTSPCLIENT_PLAY_STATUS_NO_200OK					304 // Play回复非200OK

#define RTSPCLIENT_GENERATE_CHANGERATE_FAIL				401 // 创建改变速率信令失败
#define RTSPCLIENT_SEND_CHANGERATE_FAIL					402 // 发送改变速率信令失败
#define RTSPCLIENT_RECV_CHANGERATE_FAIL					403 // 接收改变速率信令失败
#define RTSPCLIENT_CHANGERATE_STATUS_NO_200OK			404 // 改变速率回复非200OK

#define RTSPCLIENT_GENERATE_FORCEIFRAME_FAIL			501 // 创建强制I帧信令失败
#define RTSPCLIENT_SEND_FORCEIFRAME_FAIL				502 // 发送强制I帧信令失败
#define RTSPCLIENT_RECV_FORCEIFRAME_FAIL				503 // 接收强制I帧信令失败
#define RTSPCLIENT_FORCEIFRAME_STATUS_NO_200OK			504 // 强制I帧回复非200OK

#define RTSPCLIENT_GENERATE_RANDOMPLAY_FAIL				601 // 创建随机定位信令失败
#define RTSPCLIENT_SEND_RANDOMPLAY_FAIL					602 // 发送随机定位信令失败
#define RTSPCLIENT_RECV_RANDOMPLAY_FAIL					603 // 接收随机定位信令失败
#define RTSPCLIENT_RANDOMPLAY_STATUS_NO_200OK			604 // 随机定位回复非200OK

#define RTSPCLIENT_GENERATE_PAUSE_FAIL					701 // 创建暂停信令失败
#define RTSPCLIENT_SEND_PAUSE_FAIL						702 // 发送暂停信令失败
#define RTSPCLIENT_RECV_PAUSE_FAIL						703 // 接收暂停信令失败
#define RTSPCLIENT_PAUSE_STATUS_NO_200OK				704 // 暂停回复非200OK
#define RTSPCLIENT_NOT_PAUSE_STATE_FAIL					705 // 不在暂停状态

#define RTSPCLIENT_GENERATE_RESUME_FAIL					801 // 创建恢复信令失败
#define RTSPCLIENT_SEND_RESUME_FAIL						802 // 发送恢复信令失败
#define RTSPCLIENT_RECV_RESUME_FAIL						803 // 接收恢复信令失败
#define RTSPCLIENT_RESUME_STATUS_NO_200OK				804 // 恢复回复非200OK


#define RTSPCLIENT_MOLLOC_RTPUDPENGINE_FAIL				901 // 创建RtpUdp引擎失败
#define RTSPCLIENT_INIT_RTPUDPENGINE_FAIL				902 // 初始化RtpUdp引擎失败
#define RTSPCLIENT_START_RTPUDPENGINE_FAIL				903 // 开始RtpUdp引擎失败

#define RTSPCLIENT_MOLLOC_RTCPUDPENGINE_FAIL			1001 // 创建RtcpUdp引擎失败
#define RTSPCLIENT_INIT_RTCPUDPENGINE_FAIL				1002 // 初始化RtcpUdp引擎失败
#define RTSPCLIENT_START_RTCPUDPENGINE_FAIL				1003 // 开始RtcpUdp引擎失败

#define RTSPCLIENT_MOLLOC_RTPTCPENGINE_FAIL				1101 // 创建RtpTcp引擎失败
#define RTSPCLIENT_INIT_RTPTCPENGINE_FAIL				1102 // 初始化RtpTcp引擎失败
#define RTSPCLIENT_START_RTPTCPENGINE_FAIL				1103 // 开始 RtpTcp引擎失败

#define RTSPCLIENT_MOLLOC_RTPRTSPENGINE_FAIL		    1201 // 创建RtpRtsp引擎失败
#define RTSPCLIENT_INIT_RTPRTSPENGINE_FAIL				1202 // 初始化RtpRtsp引擎失败
#define RTSPCLIENT_START_RTPRTSPENGINE_FAIL				1203 // 开始RtpRtsp引擎失败

/***********************错误堆栈错误**add by hyf 2015-3-23*************************/
#define STREAM_CLIENT_ERRNO_START						3000
#define STREAM_CLIENT_NO_RTSP_SESSION					-3 + STREAM_CLIENT_ERRNO_START	// 流媒体客户端会话已经用尽
#define STREAM_CLIENT_NO_INIT							-2 + STREAM_CLIENT_ERRNO_START  // 流媒体客户端未初始化
#define STREAM_CLIENT_ERR_NO_DEF						-1 + STREAM_CLIENT_ERRNO_START  // 错误未定义
#define STREAM_CLIENT_NOERROR							0 + STREAM_CLIENT_ERRNO_START	// 没有错误
#define STREAM_CLIENT_SAESSION_INVALID					1 + STREAM_CLIENT_ERRNO_START	// 会话无效
#define STREAM_CLIENT_OVER_MAX_CONN						2 + STREAM_CLIENT_ERRNO_START	// 连接到流媒体的超过最大会话个数
#define STREAM_CLIENT_NETWORK_FAIL_CONNECT				3 + STREAM_CLIENT_ERRNO_START	// 连接流媒体服务器失败。流媒体服务器不在线或网络原因引起的连接超时等
#define STREAM_CLIENT_DEVICE_OFF_LIEN					4 + STREAM_CLIENT_ERRNO_START	// 请求前端设备不在线
#define STREAM_CLIENT_DEVICE_OVER_MAX_CONN				5 + STREAM_CLIENT_ERRNO_START	// 请求前端设备超过最大用户连接数
#define STREAM_CLIENT_RECV_ERROR						6 + STREAM_CLIENT_ERRNO_START	// 接收数据错误
#define STREAM_CLIENT_RECV_TIMEOUT						7 + STREAM_CLIENT_ERRNO_START	// 接收数据超时
#define STREAM_CLIENT_SEND_ERROR						8 + STREAM_CLIENT_ERRNO_START	// 发送数据错误
#define STREAM_CLIENT_TRANSMETHOD_INVALID				9 + STREAM_CLIENT_ERRNO_START	// 传输方式无效
#define STREAM_CLIENT_CREATESOCKET_ERROR				10 + STREAM_CLIENT_ERRNO_START	// 创建SOCKET出错
#define STREAM_CLIENT_SETSOCKET_ERROR					11 + STREAM_CLIENT_ERRNO_START	// 设置SOCKET出错
#define STREAM_CLIENT_BINDSOCKET_ERROR					12 + STREAM_CLIENT_ERRNO_START	// 绑定SOCKET出错
#define STREAM_CLIENT_LISTENSOCKET_ERROR				13 + STREAM_CLIENT_ERRNO_START	// 监听SOCKET出错
#define STREAM_CLIENT_URL_FORMAT_ERROR					14 + STREAM_CLIENT_ERRNO_START	// 请求URL格式无效
#define STREAM_CLIENT_RTSP_STATE_INVALID				15 + STREAM_CLIENT_ERRNO_START	// RTSP状态无效
#define STREAM_CLIENT_RTSP_RSP_ERROR					16 + STREAM_CLIENT_ERRNO_START	// RTSP回应错误（RTSP语法错误，必须包含的字段未包含）
#define STREAM_CLIENT_RTSP_RSP_STATE_ERROR				17 + STREAM_CLIENT_ERRNO_START	// RTSP回应状态错误（不等于200或302）
#define STREAM_CLIENT_PARSE_SDP_FAIL					18 + STREAM_CLIENT_ERRNO_START	// 解析SDP（Session Description Protocol）失败
#define STREAM_CLIENT_PARSE_RTSP_FAIL					19 + STREAM_CLIENT_ERRNO_START	// 解析RTSP信令失败
#define STREAM_CLIENT_MEDIACOUNT_LESS_ZERO				20 + STREAM_CLIENT_ERRNO_START	// 解析SDP时，未解析到traceID
#define STREAM_CLIENT_SEND_DESCRIBE_FAIL				21 + STREAM_CLIENT_ERRNO_START	// 发送describe信令失败
#define STREAM_CLIENT_SEND_SETUP_FAIL					22 + STREAM_CLIENT_ERRNO_START	// 发送setup信令失败
#define STREAM_CLIENT_SEND_PLAY_FAIL					23 + STREAM_CLIENT_ERRNO_START	// 发送play信令失败
#define STREAM_CLIENT_SEND_PAUSE_FAIL					24 + STREAM_CLIENT_ERRNO_START	// 发送pause信令失败
#define STREAM_CLIENT_SEND_TRERDOWN_FAIL				25 + STREAM_CLIENT_ERRNO_START	// 发送teardown信令失败
#define STREAM_CLIENT_RECV_DESCRIBE_TIMEOUT				26 + STREAM_CLIENT_ERRNO_START	// 接收describe信令超时
#define STREAM_CLIENT_RECV_SETUP_TIMEOUT				27 + STREAM_CLIENT_ERRNO_START	// 接收setup信令超时
#define STREAM_CLIENT_RECV_PLAY_TIMEOUT					28 + STREAM_CLIENT_ERRNO_START	// 接收play信令超时
#define STREAM_CLIENT_RECV_PAUSE_TIMEOUT				29 + STREAM_CLIENT_ERRNO_START	// 接收pause信令超时
#define STREAM_CLIENT_RECV_TEARDOWN_TIMEOUT				30 + STREAM_CLIENT_ERRNO_START	// 接收teardown信令超时
#define STREAM_CLIENT_DESCRIBE_RSP_ERROR				31 + STREAM_CLIENT_ERRNO_START	// describe信令响应错误
#define STREAM_CLIENT_SETUP_RSP_ERROR					32 + STREAM_CLIENT_ERRNO_START	// setup信令响应错误
#define STREAM_CLIENT_PLAY_RSP_ERROR					33 + STREAM_CLIENT_ERRNO_START	// play信令响应错误
#define STREAM_CLIENT_PAUSE_RSP_ERROR					34 + STREAM_CLIENT_ERRNO_START	// pause信令响应错误
#define STREAM_CLIENT_TEARDOWN_RSP_ERROR				35 + STREAM_CLIENT_ERRNO_START	// teardown信令响应错误
#define STREAM_CLIENT_REDIRECT_ERROR					36 + STREAM_CLIENT_ERRNO_START	// 重定向失败
#define STREAM_CLIENT_UDP_GET_SERVER_PROT_FAIL			37 + STREAM_CLIENT_ERRNO_START	// 从RTSP的setup信令解析服务器端口失败
#define STREAM_CLIENT_CREATE_UPD_CONNECT_FAIL			38 + STREAM_CLIENT_ERRNO_START	// 创建UDP异步网络连接失败
#define STREAM_CLIENT_OPEN_UDP_CONNECT_FAIL				39 + STREAM_CLIENT_ERRNO_START	// 打开UDP异步网络连接失败
#define STREAM_CLIENT_UDP_ASYNC_RECV_FAIL				40 + STREAM_CLIENT_ERRNO_START	// UDP投递异步接收请求失败
#define STREAM_CLIENT_OPT_BACK_DATE_ERROR				41 + STREAM_CLIENT_ERRNO_START	// 相对时间回放时间错误
#define STREAM_CLIENT_ABS_BACK_DATE_ERROR				42 + STREAM_CLIENT_ERRNO_START	// 绝对时间回放时间错误
#define STREAM_CLIENT_MSG_CB_INVALID					43 + STREAM_CLIENT_ERRNO_START	// 设置消息回调无效
#define STREAM_CLIENT_SEND_PTZ_FAILED					44 + STREAM_CLIENT_ERRNO_START	// 发送云台控制信令失败
#define STREAM_CLIENT_SEND_FORCEIFRAM_FAILED			45 + STREAM_CLIENT_ERRNO_START	// 发送强制I帧信令失败
#define STREAM_CLIENT_SEND_GETVEDIOPARAM_FAILED			46 + STREAM_CLIENT_ERRNO_START	// 发送获取视频参数信令失败
#define STREAM_CLIENT_SEND_SETVEDIOPARAM_FAILED			47 + STREAM_CLIENT_ERRNO_START	// 发送设置视频参数信令失败
#define STREAM_CLIENT_RECV_PTZ_TIMEOUT					48 + STREAM_CLIENT_ERRNO_START	// 接收云台控制信令超时
#define STREAM_CLIENT_RECV_FORCEIFRAM_TIMEOUT			49 + STREAM_CLIENT_ERRNO_START	// 接收强制I帧信令超时
#define STREAM_CLIENT_RECV_GETVEDIOPARAM_TIMEOUT		50 + STREAM_CLIENT_ERRNO_START	// 接收获取视频参数信令超时
#define STREAM_CLIENT_RECV_SETVEDIOPARAM_TIMEOUT		51 + STREAM_CLIENT_ERRNO_START	// 接收设置视频参数信令超时
#define STREAM_CLIENT_FUNCTION_NO_ACHIEVE				52 + STREAM_CLIENT_ERRNO_START	// 函数未实现	函数未实现功能，不支持调用
#define STREAM_CLIENT_CONFIG_RTSP_SESSION_FAILED		53 + STREAM_CLIENT_ERRNO_START	// 配置RTSP会话失败
#define STREAM_CLIENT_FUNC_PARAM_INVALID				54 + STREAM_CLIENT_ERRNO_START	// 函数参数无效
#define STREAM_CLIENT_SESSION_POINTER_INVALID			55 + STREAM_CLIENT_ERRNO_START	// 会话指针无效
#define STREAM_CLIENT_MEMORY_LACK						56 + STREAM_CLIENT_ERRNO_START	// 申请内存失败
#define STREAM_CLIENT_SEND_SETPARAMETER_FAILED			57 + STREAM_CLIENT_ERRNO_START	// 发送设置参数信令失败
#define STREAM_CLIENT_RECV_SETPARAMETER_TIMEOUT			58 + STREAM_CLIENT_ERRNO_START	// 接收设置参数信令超时
#define STREAM_CLIENT_SEND_HEARTBEAT_FAILED				59 + STREAM_CLIENT_ERRNO_START	// 发送心跳信令失败
#define STREAM_CLIENT_RECV_HEARTBEAT_TIMEOUT			60 + STREAM_CLIENT_ERRNO_START	// 接收心跳信令超时
#define STREAM_CLIENT_PUSHDATA_TRANSMETHOD_INVALID		61 + STREAM_CLIENT_ERRNO_START	// 推流传输方式无效（仅支持RTPUDP_TRANSMODE）
#define STREAM_CLIENT_PERMISSION_LACK					62 + STREAM_CLIENT_ERRNO_START  // 权限不足
#define STREAM_CLIENT_ANALYZE_DATA_FAILED				63 + STREAM_CLIENT_ERRNO_START	// 帧分析失败
#define STREAM_CLIENT_VTM_PARSE_ERROR					64 + STREAM_CLIENT_ERRNO_START	// 信令解析出错（VTM）
#define STREAM_CLIENT_VTM_EMPTY_CLUSTER					65 + STREAM_CLIENT_ERRNO_START	// 集群中无vtdu存在（VTM）
#define STREAM_CLIENT_VTM_OVERLOAD_ERROR				66 + STREAM_CLIENT_ERRNO_START	// 集群超载时，权限不足（VTM）
#define STREAM_CLIENT_VTM_LACK_PERMISSION				67 + STREAM_CLIENT_ERRNO_START	// 权限限制（VTM）	请求VTM失败
#define STREAM_CLIENT_VTM_SERVER_INTERNAL				68 + STREAM_CLIENT_ERRNO_START	// 服务器内部错误（VTM）

//消息回调错误定义(流媒体客户端产生)
#define STREAM_CLIENT_SEND_HEARTBEAT_FAIL				4001 + STREAM_CLIENT_ERRNO_START	// 发送心跳失败
#define STREAM_CLIENT_HEARTBEAT_TIMEOUT					4002 + STREAM_CLIENT_ERRNO_START	// 心跳超时
#define STREAM_CLIENT_NOT_SUPPORT_PS_STREAM				4003 + STREAM_CLIENT_ERRNO_START	// 不支持转封装成PS码流标识，消息数据回调中使用

//消息回调错误定义(流媒体服务器产生)
#define STREAM_CLIENT_ERR_FROM_SERVER					8000 + STREAM_CLIENT_ERRNO_START	// 总的错误码，根据这个错误码进行判断
#define STREAM_CLIENT_CLICK								8001 + STREAM_CLIENT_ERRNO_START	// 因权限不足，被踢掉
#define STREAM_CLIENT_LOCATION_FAILED					8002 + STREAM_CLIENT_ERRNO_START	// 回放定位失败
#define STREAM_CLIENT_DEVICE_NET_ERROR					8500 + STREAM_CLIENT_ERRNO_START	// 错误
#define STREAM_CLIENT_DEVICE_NET_ERROR_PARAM			8501 + STREAM_CLIENT_ERRNO_START	// 请求的参数错误（URL、通道不存在等）
#define STREAM_CLIENT_DEVICE_NET_ERROR_PASSWD			8502 + STREAM_CLIENT_ERRNO_START	// 用户名密码错误
#define STREAM_CLIENT_DEVICE_NET_ERROR_CONNECT			8503 + STREAM_CLIENT_ERRNO_START	// 设备不在线，或连接超时
#define STREAM_CLIENT_DEVICE_CONNECT_ERROR				8504 + STREAM_CLIENT_ERRNO_START	// 设备连接错误

//消息回调错误定义(流媒体服务器产生)
#define STREAM_CLIENT_VTM_ERR							9000 + STREAM_CLIENT_ERRNO_START	//总的错误码，根据这个错误码进行判断

/*********************************stack err end***********************************************/

#define RTSPCLIENT_MSG_PLAYBACK_FINISH      0x0100 //回放数据接收完成
#define RTSPCLIENT_MSG_BUFFER_OVERFLOW		0x0101 //数据缓存不足，建议切换低分辨率
#define RTSPCLIENT_MSG_CONNECTION_EXCEPTION	0x0102 //RTSP连接异常，建议关闭重新请求
#define RTSPCLIENT_MSG_ISCONNECTING			0x0103 // 重连中

typedef enum _MagVersion
{
	MAG_VERSION_OTHER = 0,
	MAG_VERSION_0_1 = 1
}MagVersion;

typedef int (*pRtspDataCallback)(int handle, int dataType, char* data, int len, unsigned int timestamp, int packetNo, void* pUser);
typedef int (*pRtspMsgCallback)(int handle, int opt, void* param1, void* param2, void* pUser);

typedef struct _ABS_TIME_
{
    unsigned int dwYear;
    unsigned int dwMonth;
    unsigned int dwDay;
    unsigned int dwHour;
    unsigned int dwMinute;
    unsigned int dwSecond;
}ABS_TIME, *pABS_TIME;

typedef struct _LiveInfo_
{
    /** MAG的IP */
    char* magIp;
    /** MAG的端口 */
    int magPort;
    /** 监控点的IndexCode */
	char* cameraIndexCode;
    /** 级联标识，0-非级联，1-级联 */
    int cascadeFlag;
    /** 码流类型，0-STREAM_TYPE_MAIN，1-STREAM_TYPE_SUB */
    int streamType;
    /** 客户端的网域ID */
    int mcuNetID;
    /** 设备的网域ID */
    int deviceNetID;
    /** 安全验证信息 */
    char* token;
    /** 用户权限值 */
    int iPriority;
    /** MCU是否在公网，1-公网、0-私网 */
    int isInternet;
    /** 是否编码标识 */
    bool bTranscode;
    /** 分辨率 0-QCIF 1-QVAG 2-CIF 3-TWOCIF 4-D1 */
    int resolution;
    /** 比特率 */
    int bitrate;
    /** 帧率 */
    int framerate;
    /** 编码类型  0-VIDEO_TYPE_MPEG4 1-VIDEO_TYPE_H264*/
    int videotype;
    /** 封装类型  0-SYSTEM_TYPE_RTP 1-SYSTEM_TYPE_PS*/
    int systemformat;
}LiveInfo, *PLiveInfo;

// added by hyf
typedef struct _NCG_PlaybcakInfo_
{
	/** MAG的IP */
	char* magIp;
	/** MAG的端口 */
	int magPort;
    /** 监控点的IndexCode */
	char* cameraIndexCode;
    /** 安全验证信息 */
    char* token;
    /** 录像名称 */
	char* fileName;
    /** 录像位置 */
	int recordPos;
    /** 录像类型 */
	int recordType;
    /** 开始时间 */
	char* begin;
    /** 结束时间 */
	char* end;
}NCGPlaybcakInfo, *PNCGPlaybcakInfo;

typedef struct _PlaybcakInfo_
{
	/** MAG的IP */
	char* magIp;
	/** MAG的端口 */
	int magPort;
	/** 回放地址 */
	char* playbackUrl;
    /** 安全验证信息 */
    char* token;
    /** MAG版本 */
    int magVersion;
    /** 开始时间 */
	char* begin;
    /** 结束时间 */
	char* end;
}PlaybcakInfo, *PPlaybcakInfo;

/** @fn bool RtspClientInitLib()
 *   @brief 初始化RTSP库
 *   @param [in] 无
 *   @param [out] 无
 *   @return true - 初始化成功; false - 初始化库失败
 */
RTSPCLIENTSDKAPI bool RtspClientInitLib();

/** @fn bool RtspClientFiniLib()
 *   @brief 释放RTSP库
 *   @param [in] 无
 *   @param [out] 无
 *   @return 无
 */
RTSPCLIENTSDKAPI bool RtspClientFiniLib();

/** @fn bool RtspClientCreateEngine()
 *   @brief 初始化RTSP库
 *   @param [in] rtpProtocol - RTP传输协议
 *   @param [in] dataCallBack - 数据回调函数
 *   @param [in] msgCallback - 消息回调函数
 *   @param [out] handle	- 引擎句柄
 *   @return true - 初始化成功; false - 初始化库失败
 */
RTSPCLIENTSDKAPI int RtspClientCreateEngine(int tansmethod,
                                            int (*pRTSPDataCallback)(int handle, int dataType, char* data, int len, unsigned int timestamp, int packetNo, void* pUser), 
                                            int (*pRTSPMsgCallback)(int handle, int opt, void* param1, void* param2, void* pUser), 
                                            void* pUser);

/** @fn bool RtspClientReleaseEngine(void* handle)
 *   @brief 释放RTSP库
 *   @param [in] handle - 引擎句柄
 *   @param [out] 无
 *   @return true - 成功; false - 失败
 */
RTSPCLIENTSDKAPI bool RtspClientReleaseEngine( int engineId );

/** @fn bool RtspClientStartRtspProc()
 *   @brief 开始Rtsp流程, 向服务器发送Describe\Setup\Play信令
 *   @param [in] handle - 引擎句柄
 *   @param [in] pszRtspUrl - Rtsp地址
 *   @param [out] 无
 *   @return true - 打开成功, false - 打开失败
 */
RTSPCLIENTSDKAPI bool RtspClientStartRtspProc(int engineId, const char* pszRtspUrl);

/** @fn bool RtspClientStartRtspProc()
 *   @brief 开始Rtsp流程, 向服务器发送Describe\Setup\Play信令
 *   @param [in] handle - 引擎句柄
 *   @param [in] pszRtspUrl - Rtsp地址
 *   @param [out] 无
 *   @return true - 打开成功, false - 打开失败
 */
RTSPCLIENTSDKAPI bool RtspClientStartRtspProc(int engineId, const char* pszRtspUrl, const char* deviceName, const char* devicePsw);

/** @fn bool GenerateLiveUrl()
 *   @brief 产生live url
 *   @param [in] liveInfo - 引擎句柄
 *   @param [out] buf - Rtsp地址
 *   @return true - 打开成功, false - 打开失败
 */
RTSPCLIENTSDKAPI bool GenerateLiveUrl(PLiveInfo liveInfo, char* buf);

/** @fn bool RtspClientStopRtspProc(void* handle )
 *   @brief 停止RTSP库
 *   @param [in] handle - 引擎句柄
 *   @param [out] 无
 *   @return true - 停止成功; false - 停止失败
 */
RTSPCLIENTSDKAPI bool RtspClientStopRtspProc(int engineId);

/** @fn bool GetRtspClientSession(int handle )
 *   @brief 获取Rtsp回话
 *   @param [in] handle - 引擎ID
 *   @param [out] 无
 *   @return true - 停止成功; false - 停止失败
 */
RTSPCLIENTSDKAPI char* GetRtspClientSession(int engineId);

/** @fn bool GeneratePlaybackUrl
 *   @brief 生成回放地址
 *   @param [in] playbcakInfo - 远程回放信息
 *   @param [out] buf - 生成的远程回放地址
 *   @param [out] 无
 *   @return true - 播放成功, false - 播放失败
 */
RTSPCLIENTSDKAPI bool GeneratePlaybackUrl(PPlaybcakInfo playbcakInfo, char* buf);

/** @fn bool GenerateNCGPlaybackUrl
 *   @brief 生成级联回放地址
 *   @param [in] playbcakInfo - 级联点远程回放信息
 *   @param [out] buf - 生成的远程回放地址
 *   @param [out] 无
 *   @return true - 播放成功, false - 播放失败
 */
RTSPCLIENTSDKAPI bool GenerateNCGPlaybackUrl(PNCGPlaybcakInfo playbcakInfo, char* buf);

/** @fn bool RtspClientPlaybackByTime
 *   @brief 按时间回放
 *   @param [in] handle - 引擎句柄
 *   @param [in] pszRtspUrl - 回放地址
 *   @param [in] deviceName - 设备名称
 *   @param [in] devicePsw - 设备密码
 *   @param [out] 无
 *   @param [out] 无
 *   @return true - 播放成功, false - 播放失败
 */
RTSPCLIENTSDKAPI bool RtspClientPlaybackByTime(int engineId, const char* pszRtspUrl, const char* deviceName, const char* devicePsw, pABS_TIME from, pABS_TIME to);

/** @fn bool RtspClientPause(void* handle)
 *   @brief 在绝对时间范围内，随机定位
 *   @param [in] handle - 引擎句柄
 *   @param [in] pfrom - 回放开始时间
 *   @param [in] pto - 回放结束时间，默认为空
 *   @param [out] 无
 *   @return true - 成功, false - 失败
 */
RTSPCLIENTSDKAPI bool RtspClientSetPlaybackPos(int engineId, pABS_TIME pfrom, pABS_TIME pto);

/** @fn bool RtspClientChangeRate(void* handle)
 *   @brief 快进
 *   @param [in] handle - 引擎句柄
 *   @param [in] scale为速率改变的方向, >0 播放速率加倍, <0 播放速率减半, =0 恢复正常播放速率
 *   @param [out] 无
 *   @return true - 暂停成功, false - 暂停失败
 */
RTSPCLIENTSDKAPI bool RtspClientPlaybackFast( int engineId);

/** @fn bool RtspClient_PlaybackSlow
 *   @brief 慢进
 *   @param [in] handle - 引擎句柄
 *   @param [in] scale为速率改变的方向, >0 播放速率加倍, <0 播放速率减半, =0 恢复正常播放速率
 *   @param [out] 无
 *   @return true - 暂停成功, false - 暂停失败
 */
RTSPCLIENTSDKAPI bool RtspClientPlaybackSlow( int engineId);

/** @fn bool RtspClient_PlaybackNormal
 *   @brief 恢复正常速率
 *   @param [in] handle - 引擎句柄
 *   @param [in] scale为速率改变的方向, >0 播放速率加倍, <0 播放速率减半, =0 恢复正常播放速率
 *   @param [out] 无
 *   @return true - 暂停成功, false - 暂停失败
 */
RTSPCLIENTSDKAPI bool RtspClientPlaybackNormal( int engineId);

/** @fn bool RtspClientPause(void* handle)
 *   @brief 暂停
 *   @param [in] handle - 引擎句柄
 *   @param [out] 无
 *   @return true - 成功, false - 失败
 */
RTSPCLIENTSDKAPI bool RtspClientPause(int engineId);

/** @fn bool RtspClientResume(void* handle)
 *   @brief  恢复
 *   @param [in] handle - 引擎句柄
 *   @param [out] 无
 *   @return true - 成功, false - 失败
 */
RTSPCLIENTSDKAPI bool RtspClientResume(int engineId);

/** @fn int RtspClientGetLastError()
 *  @brief  获取错误码
 *  @param [in] 无
 *  @param [out] 无
 *  @return 错误码
 */
RTSPCLIENTSDKAPI int RtspClientGetLastError();

/** @fn int GetRtspClientVersion()
 *  @brief  获取版本号
 *  @param [in] 无
 *  @param [out] 无
 *  @return 错误码
 */
RTSPCLIENTSDKAPI char* GetRtspClientVersion();

/**
 *  获得媒体头信息
 *
 *  @param engineId 引擎号
 *  @param len      媒体头长度
 *
 *  @return 媒体头信息地址
 */
RTSPCLIENTSDKAPI const char * RtspClientGetMediaHeader( int engineId, int *len);
//#ifdef __cplusplus
//}
//#endif


#endif  // __RTSPCLIENT_H__
