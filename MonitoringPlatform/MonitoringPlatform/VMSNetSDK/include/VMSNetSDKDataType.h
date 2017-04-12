//
//  VMSNetSDKDataType.h
//  VMSNetSDK
//
//  Created by Dengsh on 13-7-19.
//  Copyright (c) 2013年 Dengsh. All rights reserved.
//

#import <Foundation/Foundation.h>

/********* define *************************************************************/
#define DATA_BOUNDARY @"------HikvisionFormBoundary9sZiFmmnHIfIILI"

#define PTZ_OUT_TIME            600     // 云台超时

// 终端类型
#define MOBILE_TYPE_IPHONE      1       // iPhone
#define MOBILE_TYPE_IPAD        2       // iPad
#define MOBILE_TYPE_ANPHONE     3       // Android Phone
#define MOBILE_TYPE_ANPAD       4       // Android Pad
#define MOBILE_TYPE_WP7         5       // Windows Phone 7

// 监控点类型
#define CAMERA_TYPE_UNKNOWN     -1      // 未知类型
#define CAMERA_TYPE_BOX_CAMERA  0       // 枪机
#define CAMERA_TYPE_DOME_CAMERA 1       // 半球
#define CAMERA_TYPE_FAST_CAMERA 2       // 快球
#define CAMERA_TYPE_PTZ_CAMERA  3       // 带云台的枪机
#define CAMERA_TYPE_YS_CAMERA   4       //萤石云

// 标记点类型
#define POINT_TYPE_ALL          0       // 所有点(包含监控点、报警输入、报警输出、兴趣点)
#define POINT_TYPE_CAMERA       1       // 监控点
#define POINT_TYPE_ALARMIN      2       // 报警输入
#define POINT_TYPE_ALARMOUT     3       // 报警输出
#define POINT_TYPE_INTEREST     4       // 兴趣点

// 云台控制命令
#define PTZ_CMD_UP              1       // 云台向上
#define PTZ_CMD_DOWN            2       // 云台向下
#define PTZ_CMD_LEFT            3       // 云台向左
#define PTZ_CMD_RIGHT           4       // 云台向右
#define PTZ_CMD_BRIGHTEN        5       // 图像变亮
#define PTZ_CMD_DARKEN          6       // 图像变暗
#define PTZ_CMD_ZOOMIN          7       // 镜头拉近
#define PTZ_CMD_ZOOMOUT         8       // 镜头拉远
#define PTZ_CMD_FOCUSNEAR       9       // 镜头近焦
#define PTZ_CMD_FOCUSFAR        10      // 镜头远焦
#define PTZ_CMD_UPLEFT          11      // 云台左上
#define PTZ_CMD_UPRIGHT         12      // 云台右上
#define PTZ_CMD_DOWNLEFT        13      // 云台左下
#define PTZ_CMD_DOWNRIGHT       14      // 云台右下
#define PTZ_CMD_STOP            15      // 云镜停止
#define PTZ_CMD_AOTUPAN         16      // 自动扫描
#define PTZ_CMD_SETPRESET       17      // 设置预置点
#define PTZ_CMD_GOTOPRESET      18      // 转到预置点
#define PTZ_CMD_CLEPRESET       19      // 清空预置点

#define PTZ_CME_SCAN_OPEN       3      // 雨刷开
#define PTZ_CME_SCAN_CLOSE      3      // 雨刷关
#define PTZ_CME_LIGHT_OPEN      2      // 灯光开
#define PTZ_CME_LIGHT_CLOSE     2      // 灯光关
#define PTZ_CME_ONEKEYFORCUS_OPEN       24      // 聚焦开
#define PTZ_CME_ONEKEYFORCUS_CLOSE      25      // 聚焦关
#define PTZ_CME_INITCAMERA_OPEN         200      // 初始化相机开
#define PTZ_CME_INITCAMERA_CLOSE        201      // 初始化相机关
#define PTZ_CME_3DZOOM                  99      // 3D放大

// 录像类型
#define RECORD_TYPE_PLAN        1       // 计划录像
#define RECORD_TYPE_MOVE        2       // 移动录像
#define RECORD_TYPE_MANU        16      // 手动录像
#define RECORD_TYPE_ALARM       4       // 报警录像

// 存储位置类型
#define RECORD_POS_IPSAN        0       // IPSAN
#define RECORD_POS_DEVICE       1       // 设备录像
#define RECORD_POS_PCNVR        2       // PCNVR
#define RECORD_POS_ENVR         3       // ENVR
#define RECORD_POS_CISCO        4       // CISCO
#define RECORD_POS_DSNVR        5       // DSNVR
#define RECORD_POS_CVR          7       // CVR
#define RECORD_POS_CLOUD        6      // 云存储

//VRM4.x版本存储位置类型
#define RECORD_POS_DEVICE_VRMV40        0   //设备
#define RECORD_POS_PCNVR_VRMV40         1   //PCNVR
#define RECORD_POS_CVR_ENVR_VRMV40      2   //CVR/ENVR
#define RECORD_POS_CLOUD_VRMV40         3   //云存储

// 错误码定义
#define VMSNETSDK_NO_ERROR                          0       // 没有错误

// 操作错误(100-120)
#define VMSNETSDK_INPUT_PARAM_ERROR                 100     // 输入参数错误

// http请求相关(120-140)
#define VMSNETSDK_HTTP_NEW_URL_OBJ_FAIL             120     // 创建url对象失败
#define VMSNETSDK_HTTP_NEW_REQUEST_OBJ_FAIL         121     // 创建request对象失败
#define VMSNETSDK_HTTP_REQUEST_TIMEOUT              122     // http请求超时
#define VMSNETSDK_HTTP_REQUEST_EXCEPTION            123     // http请求异常
#define VMSNETSDK_HTTP_REQUEST_RETURN_NULL          124     // http请求返回空
#define VMSNETSDK_HTTP_REQUEST_NO_NETWORK           125     // 当前无网络
#define VMSNETSDK_HTTP_REQUEST_CONNECT_FAIL         126     // http链接失败

// XML解析相关(140-160)
#define VMSNETSDK_XMLPARSER_NEW_DATADOC_OBJ_FAIL    140     // 创建data doc对象失败
#define VMSNETSDK_XMLPARSER_GET_ROOTNODE_FAIL       141     // 获取root节点失败
#define VMSNETSDK_XMLPARSER_PARSESTATUS_FAIL        142     // 解析返回状态码和描述失败

// msp服务器返回错误(160-300)
#define VMSNETSDK_MSP_NO_DATA                       160     // 不存在数据
#define VMSNETSDK_MSP_PARAM_ERROR                   161     // URL请求时参数缺少或参数错误
#define VMSNETSDK_MSP_SESSION_ERROR                 162     // 会话错误
#define VMSNETSDK_MSP_USER_NOT_EXIST                163     // 用户不存在
#define VMSNETSDK_MSP_PASSOWRD_ERROR                164     // 密码错误
#define VMSNETSDK_MSP_DEVICE_NOT_EXIST              165     // 设备不存在
#define VMSNETSDK_MSP_CAMERA_NOT_EXIST              166     // 监控点不存在
#define VMSNETSDK_MSP_LINE_NOT_EXIST                167     // 线路不存在
#define VMSNETSDK_MSP_CTRLUNIT_NOT_EXIST            168     // 控制中心不存在
#define VMSNETSDK_MSP_REGION_NOT_EXIST              169     // 区域不存在
#define VMSNETSDK_MSP_VTDU_DISABLE                  170     // 流媒体没有被启用
#define VMSNETSDK_MSP_NO_PERMISSION                 171     // 没有权限
#define VMSNETSDK_MSP_RECORDPOS_NOT_EXIST           172     // 录像不存在
#define VMSNETSDK_MSP_USER_BLOCKED                  173     // 用户被冻结
#define VMSNETSDK_MSP_USER_LOGGIN                   174     // 用户已经登录
#define VMSNETSDK_MSP_NO_SUPPORT                    175     // 没有支持
#define VMSNETSDK_MSP_UNKNOWN_ERROR                 199     // 未知错误
#define VMSNETSDK_MSP_ERROR_NEED_DESCRIBE           198     // 平台需要提示的错误描述
#define VMSNETSDK_MSP_SERVER_EXCEPTION              200     // 服务器异常
#define VMSNETSDK_MSP_USERNAME_OR_PASSWORD_ERROR    201     // 用户名或密码错误（V4.0.0新增）
#define VMSNETSDK_MSP_EXCEPTION                     230     //自动登录票据错误或已经失效(V4.2.1增加)
//安全加固
#define VMSNETSDK_MSP_FISRTLOGIN                    (20030) //首次登陆需要修改密码
#define VMSNETSDK_MSP_PASSWORD_WEAK                 (20031) //密码太弱需要修改密码
#define VMSNETSDK_MSP_PASSWORD_OUTOFDATA            (20032) //密码过期需要修改密码

//更新
#define VMSNETSDK_MSP_UPDATE_NOPHONE                (242)
#define VMSNETSDK_MSP_UPDATE_VERIFICATIONERROR      (243)
// MAG服务器返回错误码(301-400)
#define VMSNETSDK_MAG_REGISTERFAIL                  301     // 注册失败
#define VMSNETSDK_MAG_LOGOUTFAIL                    302     // 注销失败
#define VMSNETSDK_MAG_QUERYRECORD_FAIL              303     // 录像查询，失败
#define VMSNETSDK_MAG_QUERYRECORD_PARAMINCOMPLETE   304     // 录像查询，参数不全
#define VMSNETSDK_MAG_QUERYRECORD_CAMERANOTEXIST    305     // 录像查询，监控点不存在
#define VMSNETSDK_MAG_QUERYRECORD_OPERATIONFAIL     306     // 录像查询，操作失败
#define VMSNETSDK_MAG_QUERYRECORD_NOSUPPORT         307     // 录像查询，不支持
#define VMSNETSDK_MAG_QUERYRECORD_CONNECTSERVERFAIL 308     // 录像查询，连接服务器失败
#define VMSNETSDK_MAG_PTZCONTROL_FAIL               309     // 云台控制，失败
#define VMSNETSDK_MAG_PTZCONTROL_LOGINVAGFAIL       310     // 云台控制，登录VAG失败
#define VMSNETSDK_MAG_PTZCONTROL_PARSECOMMANDFAIL   311     // 云台控制，无法解析云台控制命令号
#define VMSNETSDK_MAG_PTZCONTROL_PRIORITYLOWER      312     // 云台控制，云台控制权限太低
#define VMSNETSDK_MAG_PTZCONTROL_CHANNELISLOCKED    313     // 云台控制，云台控制通道被锁定
#define VMSNETSDK_MAG_PTZCONTROL_CHANNELNOTEXIST    314     // 云台控制，通道编号不存在
#define VMSNETSDK_MAG_PTZCONTROL_LOGINDEVICEFAIL    315     // 云台控制，登录设备失败
#define VMSNETSDK_MAG_IOCONTROL_DIRSERVERCONNECTFAIL 316    // I/O控制，目录服务器连接失败
#define VMSNETSDK_MAG_ERROR                         317     // MAG出错
#define VMSNETSDK_MAG_GETPLATSERVERINFOFAIL         318     // MAG获取平台服务器信息失败

// 用户能力集
#define USER_CAPABILITY_PREVIEW             @"1"                                /**< 实时预览权限 */
#define USER_CAPABILITY_PLAYBACK            @"2"                                /**< 远程回放权限 */
#define USER_CAPABILITY_APPLICATION         @"5"                                /**< 行业应用加载权限 */
#define USER_CAPABILITY_GISMAP              @"6"                                /**< GIS地图加载权限 */
#define USER_CAPABILITY_MESSAGE             @"7"                                /**< 消息推送加载权限 */
#define USER_CAPABILITY_SEARCH              @"8"                                /**< 搜索监控点权限 */

// 监控点能力集
#define CAMERA_CAPABILITY_PREVIEW           @"1"                                /**< 监控点预览权限 */
#define CAMERA_CAPABILITY_PLAYBACK          @"2"                                /**< 监控点回放权限 */
#define CAMERA_CAPABILITY_CORRECTION        @"3"                                /**< 监控点地理位置矫正权限 */

/********* struct *************************************************************/
typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}ABSTIME, *PABSTIME;

/********* enum ***************************************************************/
typedef enum
{
    SP_VRM = 0,         /**< 查询VRM上的录像信息 */
    SP_NCG = 1,         /**< 查询NCG上的录像信息 */
}SEARCH_POS;

typedef enum PointType                                                          /**< gis点类型 */
{
    PointTypeCamera = 1,                                                        /**< 监控点 */
    PointTypeAlarmInput,                                                        /**< 报警输入 */ 
    PointTypeAlarmOutput,                                                       /**< 报警输出 */
    PointTypeAnnotation,                                                        /**< 兴趣点 */
    PointTypePhone,                                                             /**< 单兵 */
    PointTypeCar,                                                               /**< 车载 */
    PointTypeBayonet,                                                           /**< 卡口 */
}PointType;

typedef enum CameraType                                                         /**< 监控点类型 */
{
    Rifle = 0,                                                                  /**< 枪机 */
    Hemisphere,                                                                 /**< 半球 */
    Fastball,                                                                   /**< 快球 */
    PTZ,                                                                        /**< 云台 */
}CameraType;

typedef enum MessageType                                                        /**< 消息类型 */
{
    SM = 0,                                                                     /**< 系统消息 */
    PM = 1,                                                                     /**< 平台公告 */
    AM = 2,                                                                     /**< 报警消息 */
    TM = 3,                                                                     /**< 所有消息类型 */
}MessageType;

typedef enum MapType
{
    eEzMap = 0,                                                                 /**< 山海经纬地图 */
    eStaticMap,                                                                 /**< 静态地图 */
    eGoogleMap,                                                                 /**< google地图 */
    eArcGisMap,                                                                 /**< ArcGIS地图 */
    eWebGisMap,                                                                 /**< WebGIS地图 */
}MapType;

typedef enum
{
    eCamera      = 0x1 << 0,                                                    /**< 监控点 */
    eAlarmInput  = 0x1 << 1,                                                    /**< 报警输入 */
    eAlarmOutput = 0x1 << 2,                                                    /**< 报警输出 */
    ePortableDVR = 0x1 << 3,                                                    /**< 单兵设备 */
    eMobileDVR   = 0x1 << 4,                                                    /**< 车载 */
    eAll         = eCamera | eAlarmInput | eAlarmOutput | ePortableDVR | eMobileDVR /**< 所有类型 */
}GisPointType;


typedef NS_ENUM(NSInteger, ENCRYPT_TYPE)
{
    ENCRYPT_TYPE_MD5  = 0,
    ENCRYPT_TYPE_AHS256  = 1,

};
/********* classes ************************************************************/
/**
 *	@brief	服务器信息
 */
@interface CServInfo : NSObject
{
    NSString *_servAddr;                                                        // 服务器地址
    int _port;                                                                  // 服务器端口
}

@property (nonatomic, copy) NSString *servAddr;
@property (nonatomic, assign) int port;

@end

/**
 *	@brief	web app 信息
 */
@interface CWebAppInfo : NSObject
{
    NSString *_appName;                                                         // app 名称
    NSString *_appIconUrl;                                                      // app 图标链接
    NSString *_appLinkUrl;                                                      // app 连接地址
    int _appIndex;                                                              // app 排序位置
}

@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appIconUrl;
@property (nonatomic, copy) NSString *appLinkUrl;
@property (nonatomic, assign) int appIndex;

@end

/**
 *	@brief	MSP登录信息,登录MSP后返回
 */
@interface CMSPInfo : NSObject
{
    NSString *_sessionID;                                                       // 会话ID
    NSString *_userCapability;                                                  // 用户能力集
    NSString *_userID;                                                          // 用户ID
    NSArray *_vmsList;                                                          // 电视墙服务器信息列表
    NSArray *_webAppList;                                                       // web app 列表 (元素为WebAppInfo)
    BOOL _isWebAppDefaultSel;                                                   // web app 是否默认选中
    BOOL _isLocalTitleVisible;                                                  // 本地标题栏是否可见，1:可见 0:不可见
    CServInfo *_pushServerInfo;                                                 // 推送服务器信息
    
    // V4.0.0新增
    double _lifeTime;
    int    _appVersion;
    int    _appNetID;
    BOOL   _isInternet;                                                         // YES-公网 NO-专网
    BOOL   _isTokenVerify;                                                      // 平台是否校验token
    CServInfo *_magStreamServer;
    CServInfo *_magFileServer;
    CServInfo *_magHttpServer;
    CServInfo *_magGPSServer;
    CServInfo *_magNotifyServer;
    CServInfo *_magTalkServer;
    NSString  *_userName;
    NSString  *_password;
    BOOL    _isLoginModifyPassword;  //是否第一次登录
    NSString *_strLoginModifyPasswordID;
    NSInteger _patlformPasswordLevel;
    NSTimeInterval _loginTime;
    ENCRYPT_TYPE _passwordEncrypt;
    //6.4.2新增
    NSString *_autoLoginSession;
}

@property (nonatomic, copy)   NSString  *sessionID;
@property (nonatomic, copy)   NSString  *userCapability;
@property (nonatomic, copy)   NSString  *userID;
@property (nonatomic, retain) NSArray   *vmsList;
@property (nonatomic, retain) NSArray   *webAppList;
@property (nonatomic, assign) BOOL       isWebAppDefaultSel;
@property (nonatomic, assign) BOOL       isLocalTitleVisible;
@property (nonatomic, retain) CServInfo *pushServerInfo;

// V4.0.0新增
@property (nonatomic, assign) double     lifeTime;
@property (nonatomic, assign) int        appVersion;
@property (nonatomic, assign) int        appNetID;
@property (nonatomic, assign) BOOL       isInternet;
@property (nonatomic, assign) BOOL       isTokenVerify;
@property (nonatomic, retain) CServInfo *magStreamServer;
@property (nonatomic, retain) CServInfo *magFileServer;
@property (nonatomic, retain) CServInfo *magHttpServer;
@property (nonatomic, retain) CServInfo *magGPSServer;
@property (nonatomic, retain) CServInfo *magNotifyServer;
@property (nonatomic, retain) CServInfo *magTalkServer;
@property (nonatomic, copy)   NSString  *userName;
@property (nonatomic, copy)   NSString  *password;
@property (nonatomic, assign) BOOL isLoginModifyPassword;
@property (nonatomic, copy)   NSString  *strLoginModifyPasswordID;
@property (nonatomic, assign) NSInteger patlformPasswordLevel;
@property (nonatomic, assign) NSTimeInterval loginTime;
@property (nonatomic, assign) ENCRYPT_TYPE passwordEncrypt;
@property (nonatomic, copy) NSString *autoLoginSession;
@end

/**
 *	@brief	控制中心
 */
@interface CControlUnitInfo : NSObject
{
    int _controlUnitID;                                                         // 控制中心ID
    int _parentID;                                                              // 控制中心父亲ID
    NSString *_name;                                                            // 控制中心名称
    
    // V4.0.0新增
    BOOL _cascadeFlag;                                                          // YES:级联 NO:非级联
    int _currentOnlineNum;
    int _totalNum;
}

@property (nonatomic, assign) int controlUnitID;
@property (nonatomic, assign) int parentID;
@property (nonatomic, copy)   NSString *name;

// V4.0.0新增
@property (nonatomic, assign) BOOL cascadeFlag;
@property (nonatomic, assign) int currentOnlineNum;
@property (nonatomic, assign) int totalNum;

@end

/**
 *	@brief	区域信息
 */
@interface CRegionInfo : NSObject
{
    int       _regionID;                                                        // 区域ID
    int       _controlUnitID;                                                   // 控制中心ID
    int       _parentID;                                                        // 控制中心父亲ID
    NSString *_name;                                                            // 控制中心名称
}

@property (nonatomic, assign)   int              regionID;
@property (nonatomic, assign)   int              controlUnitID;
@property (nonatomic, assign)   int              parentID;
@property (nonatomic, copy)     NSString        *name;

@end

/**
 *	@brief	设备信息
 */
@interface CDeviceInfo : NSObject
{
    NSString *_cameraID;                                                        // 监控点ID
    NSString *_deviceIP;                                                        // 设备IP
    int _devicePort;                                                            // 设备端口
    NSString *_userName;                                                        // 用户名
    NSString *_password;                                                        // 密码
    NSString *_deviceType;                                                      // 设备类型
    NSString *_deviceSupplier;                                                  // 设备供应商(V1.1)HIKVISION、DAHUA
    NSString *_indexCode;                                                       // 设备编号
    NSString *_deviceName;                                                      // 设备名称
}

@property (nonatomic, copy) NSString *cameraID;
@property (nonatomic, copy) NSString *deviceIP;
@property (nonatomic, assign) int devicePort;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *deviceType;
@property (nonatomic, copy) NSString *deviceSupplier;
@property (nonatomic, copy) NSString *indexCode;
@property (nonatomic, copy) NSString *deviceName;

@end

/**
 *	@brief	监控点信息
 */
@interface CCameraInfo : NSObject
{
    NSString *_cameraID;                                                        // 监控点ID
    NSString *_name;                                                            // 监控点名称
    int _cameraType;                                                            // 监控点类型 0-枪机 1-半球 2-快球 3-云台 4-萤石云
    BOOL _isOnline;                                                             // 监控点是否在线
    BOOL _isPTZControl;                                                         // 是否具有云台控制权限
    NSString *_deviceID;                                                        // 设备ID
    int _channelNo;                                                             // 通道号
    NSArray *_userCapability;                                                   // 用户能力说明 1-实时预览 2-远程回放 (3-地理位置矫正 4-云台控制权限 V4.0.0新增)
    NSArray *_recordPos;                                                        // 录像位置
    NSString *_acsIP;                                                           // 云台控制IP
    int _acsPort;                                                               // 云台控制端口
    int _collectedFlag;                                                         // 收藏标识 0: 未收藏 1: 收藏
    int _groupID;                                                               // 该监控点所在平台分组id
    int _cascadeFlag;                                                           // 级联标识 0: 非级联 1: 级联
    NSString *_longitude;                                                       // 经度
    NSString *_latitude;                                                        // 纬度
    
    // V4.0.0新增
    int _deviceNetID;                                                           // 设备网域ID
    //V4.2.0 行业对接MAG支持4.xVRM时需要用到GUID，录像计划唯一标示符,与recordPos一一对应
    NSArray * _guidArray;
    // 监控预览 字体叠加
    BOOL _isOverlay;
}

@property (nonatomic, copy) NSString *cameraID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) int cameraType;
@property (nonatomic, assign) BOOL isOnline;
@property (nonatomic, assign) BOOL isPTZControl;
@property (nonatomic, copy) NSString *deviceID;
@property (nonatomic, assign) int channelNo;
@property (nonatomic, retain) NSArray *userCapability;
@property (nonatomic, retain) NSArray *recordPos;
@property (nonatomic, copy) NSString *acsIP;
@property (nonatomic, assign) int acsPort;
@property (nonatomic, assign) int collectedFlag;
@property (nonatomic, assign) int groupID;
@property (nonatomic, assign) int cascadeFlag;
@property (nonatomic, copy) NSString *longitude;
@property (nonatomic, copy) NSString *latitude;

// V4.0.0新增
@property (nonatomic, assign) int deviceNetID;
@property (nonatomic, copy) NSArray *guidArray;
@property (nonatomic, assign) BOOL  isOverlay;

@end

/**
 *	@brief	录像片段信息
 */
@interface CRecordSegment : NSObject
{
    ABSTIME   _beginTime;                                                       // 开始时间
    ABSTIME   _endTime;                                                         // 结束时间
    int       _recordType;                                                      // 录像类型
    int       _mediaDataLen;                                                    // 媒体数据大小
    int       _metaDataLen;
    BOOL      _isLocked;                                                        // 是否锁定录像
    NSString *_playUrl;                                                         // 播放地址
    bool      _isNCG;
}

@property (nonatomic, assign)   ABSTIME          beginTime;
@property (nonatomic, assign)   ABSTIME          endTime;
@property (nonatomic, assign)   int              recordType;
@property (nonatomic, assign)   int              mediaDataLen;
@property (nonatomic, assign)   int              metaDataLen;
@property (nonatomic, assign)   BOOL             isLocked;
@property (nonatomic, copy)     NSString        *playUrl;
@property (nonatomic, assign)   bool             isNCG;

/**
 *	@brief	设置开始时间
 *
 *	@param 	beginTime 	开始时间
 */
- (void)setBeginTime:(ABSTIME)beginTime;

/**
 *	@brief	设置结束时间
 *
 *	@param 	endTime 	结束时间
 */
- (void)setEndTime:(ABSTIME)endTime;

@end

/**
 *	@brief	录像信息
 */
@interface CRecordInfo : NSObject
{
    int              _queryType;                                                // 录像类型
    BOOL             _isRecvAll;                                                // 是否接收完毕
    int              _segmentCount;                                             // 录像片段数
    NSString        *_segmentListPlayUrl;                                       // 录像片段播放地址
    NSMutableArray  *_recSegmentList;                                           // 录像片段列表
}

@property (nonatomic, assign)   int               queryType;
@property (nonatomic, assign)   BOOL              isRecvAll;
@property (nonatomic, assign)   int               segmentCount;
@property (nonatomic, copy)     NSString         *segmentListPlayUrl;
@property (nonatomic, retain)   NSMutableArray   *recSegmentList;

@end

/**
 *	@brief	电视墙信息
 */
@interface CTVWallInfo : NSObject
{
    int       _tvWallID;                                                        // 电视墙ID
    NSString *_name;                                                            // 电视墙名称
    int       _curSceneID;                                                      // 当前场景
    NSString *_curSceneName;                                                    // 当前场景名称
}

@property (nonatomic, assign)   int               tvWallID;
@property (nonatomic, copy)     NSString         *name;
@property (nonatomic, assign)   int               curSceneID;
@property (nonatomic, copy)     NSString         *curSceneName;

@end

/**
 *	@brief	电视墙详细信息
 */
@interface CTVWallDetailInfo : NSObject
{
    CTVWallInfo *_tvWallInfo;                                                   // 电视墙信息
    int          _width;                                                        // 电视墙宽
    int          _height;                                                       // 电视墙高
    NSMutableArray *_dlpList;                                                   // 大屏列表(存放DLPInfo结构对象列表)
}

@property (nonatomic, retain) CTVWallInfo      *tvWallInfo;
@property (nonatomic, assign) int               width;
@property (nonatomic, assign) int               height;
@property (nonatomic, retain) NSMutableArray   *dlpList;

@end

/**
 *	@brief	场景信息
 */
@interface CSceneInfo : NSObject
{
    int             _tvWallID;                                                  // 电视墙ID
    int             _sceneID;                                                   // 场景ID
    NSString       *_name;                                                      // 电视墙名称
    int             _isDefaultScene;                                            // 是否是默认场景
    int             _isAlarmScene;                                              // 是否是报警场景
    int             _width;                                                     // 电视墙宽
    int             _height;                                                    // 电视墙高
    NSMutableArray *_dlpList;                                                   // 大屏列表(存放DLPInfo结构对象列表)
}

@property (nonatomic, assign)   int               tvWallID;
@property (nonatomic, assign)   int               sceneID;
@property (nonatomic, copy)     NSString         *name;
@property (nonatomic, assign)   int               isDefaultScene;
@property (nonatomic, assign)   int               isAlarmScene;
@property (nonatomic, assign)   int               width;
@property (nonatomic, assign)   int               height;
@property (nonatomic, retain)   NSMutableArray   *dlpList;

@end

/**
 *	@brief	大屏列表
 */
@interface CDLPInfo : NSObject
{
    int             _DLPID;                                                     // 大屏ID
    NSString       *_name;                                                      // 大屏名称
    int             _row;                                                       // 大屏中监视器的行数
    int             _col;                                                       // 大屏中监视器的列数
    int             _left;                                                      // 大屏左上角X坐标
    int             _top;                                                       // 大屏左上角Y坐标
    int             _width;                                                     // 大屏宽度
    int             _height;                                                    // 大屏高度
    NSMutableArray *_monitorList;                                               // 监视器列表(存放MonitorInfo信息)
    NSMutableArray *_jiontWndList;                                              // 拼接屏列表(存放JoinWndInfo信息)
}

@property (nonatomic, assign)   int               DLPID;
@property (nonatomic, copy)     NSString         *name;
@property (nonatomic, assign)   int               row;
@property (nonatomic, assign)   int               col;
@property (nonatomic, assign)   int               left;
@property (nonatomic, assign)   int               top;
@property (nonatomic, assign)   int               width;
@property (nonatomic, assign)   int               height;
@property (nonatomic, retain)   NSMutableArray   *monitorList;
@property (nonatomic, retain)   NSMutableArray   *jiontWndList;

@end

/**
 *	@brief	监视屏信息
 */
@interface CMonitorInfo : NSObject
{
    NSString    *_name;                                                         // 监视屏名称(关联解码器的名称,如BNC_2_3)
    int          _subSys;                                                       // 子系统编号
    int          _index;                                                        // 输出通道编号
    int          _subWndNum;                                                    // 画面分隔数
    int          _pos;                                                          // 显示位置(从0开始编号,从上到下,从左到右)
    int          _resolution;                                                   // 分辨率(预留)
    int          _videoMode;                                                    // 视频制式(PAL和NTSC)
    int          _audioWnd;                                                     // 声音子窗口编号
    NSMutableArray *_monitorSubWndList;                                         // 监视屏子窗口列表(存放MonitorSubWndInfo信息)
}

@property (nonatomic, copy)     NSString         *name;
@property (nonatomic, assign)   int               subSys;
@property (nonatomic, assign)   int               index;
@property (nonatomic, assign)   int               subWndNum;
@property (nonatomic, assign)   int               pos;
@property (nonatomic, assign)   int               resolution;
@property (nonatomic, assign)   int               videoMode;
@property (nonatomic, assign)   int               audioWnd;
@property (nonatomic, retain)   NSMutableArray   *monitorSubWndList;

@end

/**
 *	@brief	监视屏子窗口信息
 */
@interface CMonitorSubWndInfo : NSObject
{
    int          _subWndID;                                                     // 子窗口ID
    int          _status;                                                       // 子窗口状态(0-空闲,1-实时预览,2表-回放,3-报警,4-轮巡)
    BOOL         _isAudioOn;                                                    // 音频是否打开
    CDeviceInfo *_deviceInfo;                                                   // 设备信息
    int          _channelNo;                                                    // 通道号
}

@property (nonatomic, assign)   int               subWndID;
@property (nonatomic, assign)   int               status;
@property (nonatomic, assign)   BOOL              isAudioOn;
@property (nonatomic, retain)   CDeviceInfo      *deviceInfo;
@property (nonatomic, assign)   int               channelNo;

@end

/**
 *	@brief	拼接屏信息
 */
@interface CJointWndInfo : NSObject
{
    int             _jiontWndID;                                                // 拼接屏窗口ID(客户端操作使用)
    NSMutableArray *_posList;                                                   // 拼接窗口所在的监视屏位置列表
    NSMutableArray *_jointSubWndList;                                           // 拼接屏子窗口信息列表(存放JointSubWndInfo信息)
}

@property (nonatomic, assign)   int                  jiontWndID;
@property (nonatomic, retain)   NSMutableArray      *posList;
@property (nonatomic, retain)   NSMutableArray      *jointSubWndList;

@end

/**
 *	@brief	拼接屏子窗口信息(开窗窗口)
 */
@interface CJointSubWndInfo : NSObject
{
    int             _subWndID;                                                  // 子窗口ID
    int             _status;                                                    // 子窗口状态(0-空闲,1-实时预览,2表-回放,3-报警,4-轮巡)
    BOOL            _isAudioOn;                                                 // 音频是否打开
    int             _left;                                                      // 子窗口左上角X坐标
    int             _top;                                                       // 子窗口左上角Y坐标
    int             _width;                                                     // 子窗口宽
    int             _heigth;                                                    // 子窗口高
    CDeviceInfo    *_deviceInfo;                                                // 设备信息
    int             _channelNo;                                                 // 通道号
}

@property (nonatomic, assign)   int                  subWndID;
@property (nonatomic, assign)   int                  status;
@property (nonatomic, assign)   BOOL                 isAudioOn;
@property (nonatomic, assign)   int                  left;
@property (nonatomic, assign)   int                  top;
@property (nonatomic, assign)   int                  width;
@property (nonatomic, assign)   int                  heigth;
@property (nonatomic, retain)   CDeviceInfo         *deviceInfo;
@property (nonatomic, assign)   int                  channelNo;

@end

/**
 *	@brief	控制参数
 */
@interface CControlParam : NSObject
{
    int _tvWallID;                                                              // 电视墙ID
    int _DLPID;                                                                 // 大屏ID
    int _subWndType;                                                            // 子窗口类型(0表示监视器,1表示拼接屏)
    int _monitorOrJointID;                                                      // 监视器或拼接屏ID(根据subWndType来定)
    int _subWndID;                                                              // 子窗口ID
}

@property (nonatomic, assign)   int                  tvWallID;
@property (nonatomic, assign)   int                  DLPID;
@property (nonatomic, assign)   int                  subWndType;
@property (nonatomic, assign)   int                  monitorOrJointID;
@property (nonatomic, assign)   int                  subWndID;

@end

/**
 *	@brief	客户端版本信息
 */
@interface CClientVersionInfo : NSObject
{
    NSString *_versionDesc;                                                     // 最新版本描述,格式为V3.00.00 build20120512
    NSString *_downloadAddr;                                                    // 软件下载地址
}

@property (nonatomic, copy) NSString *versionDesc;
@property (nonatomic, copy) NSString *downloadAddr;

@end

/**
 *	@brief	服务器版本信息
 */
@interface CServerVersionInfo : NSObject
{
    int       _platformID;                                                      // 平台ID
    NSString *_platformVersion;                                                 // 平台版本
    NSString *_MSPVersion;                                                      // MSP版本信息
    NSString *_MAGVersion;                                                      // MAG版本信息
    NSString *_VTDUVersion;                                                     // VTDU版本信息
    NSString *_PTZProxyVersion;                                                 // 云台代理服务器版本信息
    NSString *_VMSVersion;                                                      // 电视墙服务器版本信息
}

@property (nonatomic, assign)   int       platformID;
@property (nonatomic, copy)     NSString *platformVersion;
@property (nonatomic, copy)     NSString *MSPVersion;
@property (nonatomic, copy)     NSString *MAGVersion;
@property (nonatomic, copy)     NSString *VTDUVersion;
@property (nonatomic, copy)     NSString *PTZProxyVersion;
@property (nonatomic, copy)     NSString *VMSVersion;

@end

/**
 *	@brief	线路信息
 */
@interface CLineInfo : NSObject
{
    int         _lineID;                                                        // 线路ID
    NSString   *_lineName;                                                      // 线路名称
}

@property (nonatomic, assign)   int       lineID;
@property (nonatomic, copy)     NSString *lineName;

@end

/**
 *	@brief	设备GPS信息
 */
@interface CDeviceGPSInfo : NSObject
{
    NSString    *_deviceID;                                                     // 设备ID
    NSString    *_gpsTime;                                                      // GSP采集时间
    NSString    *_speed;                                                        // 速度(km/h)
    float       _direction;                                                     // 方向(以正北为基准，顺时针旋转方向)
    double      _longitude;                                                     // 经度
    double      _latitude;                                                      // 纬度
}

@property (nonatomic, copy)     NSString *deviceID;
@property (nonatomic, copy)     NSString *gpsTime;
@property (nonatomic, copy)     NSString *speed;
@property (nonatomic, assign)   float    direction;
@property (nonatomic, assign)   double   longitude;
@property (nonatomic, assign)   double   latitude;

@end

/**
 *	@brief	GIS点信息
 */
@interface CGISCameraInfo : NSObject
{
    NSString       *_cameraID;                                                  /**< 监控点ID */
    NSString       *_name;                                                      /**< 监控点名称 */
    NSMutableArray *_userCapability;                                            /**< 用户能力说明 1-实时预览 2-远程回放 3-地理位置矫正 */
    CameraType      _cameraType;                                                /**< 监控点类型 */
    BOOL            _isOnline;                                                  /**< 监控点是否在线 */
    double          _longitude;                                                 /**< 经度 */
    double          _latitude;                                                  /**< 纬度 */
    PointType       _pointType;                                                 /**< gis地图监控点类型 */
    NSString       *_deviceID;                                                  /**< 设备id */
    NSString       *_deviceName;                                                /**< 设备名称 */
    
    // V4.0.0新增
    NSString       *_controlUnitID;                                             /**< 所属的控制单元ID */
    NSString       *_objectID;                                                  /**< 关联对象ID */
}

@property (nonatomic, copy)   NSString        *cameraID;
@property (nonatomic, copy)   NSString        *name;
@property (nonatomic, retain) NSMutableArray  *userCapability;
@property (nonatomic, assign) CameraType      cameraType;
@property (nonatomic, assign) BOOL            isOnline;
@property (nonatomic, assign) double          longitude;
@property (nonatomic, assign) double          latitude;
@property (nonatomic, assign) PointType       pointType;
@property (nonatomic, copy)   NSString        *deviceID;
@property (nonatomic, copy)   NSString        *deviceName;

// V4.0.0新增
@property (nonatomic, copy)   NSString *controlUnitID;
@property (nonatomic, copy)   NSString *objectID;

@end

@interface CClusterInfo : NSObject

@property (nonatomic, assign) int    pointType;                                 /**< 标记点类型 */
@property (nonatomic, assign) int    total;                                     /**< 聚合总数 */
@property (nonatomic, assign) double longitude;                                 /**< 经度 */
@property (nonatomic, assign) double latitude;                                  /**< 维度 */

@end

@interface CArcgisMapLevel : NSObject

@property (nonatomic, assign) int    level;
@property (nonatomic, assign) double resolution;
@property (nonatomic, assign) double scale;

@end

/**
 *  ArcGIS地图初始化信息
 */
@interface CArcgisInitInfo : NSObject
{
    NSString        *_imageUrl;                                                 /**< 影像地图服务地址 */
    NSString        *_vectorUrl;                                                /**< 矢量地图服务地址 */
    NSString        *_reverseUrl;                                               /**< 地理反编码服务地址 */
    double          _xMin;
    double          _yMin;
    double          _xMax;
    double          _yMax;
    NSUInteger      _wkid;
    NSArray         *_levelList;
}

@property (nonatomic, copy)   NSString        *imageUrl;
@property (nonatomic, copy)   NSString        *vectorUrl;
@property (nonatomic, copy)   NSString        *reverseUrl;
@property (nonatomic, assign) double          xMin;
@property (nonatomic, assign) double          yMin;
@property (nonatomic, assign) double          xMax;
@property (nonatomic, assign) double          yMax;
@property (nonatomic, assign) NSUInteger      wkid;
@property (nonatomic, copy)   NSArray         *levelList;

@end

/**
 *  GIS地图初始化信息
 */
@interface CGisInitInfo : NSObject
{
    MapType         _mapType;                                                   /**< 地图类型 */
    double          _initLng;                                                   /**< 地图初始化中心点位置 － 经度 */
    double          _initLat;                                                   /**< 地图初始化中心点位置 － 纬度 */
    CArcgisInitInfo *_arcgisInitInfo;                                           /**< Arcgis地图初始化信息 */
}

@property (nonatomic, assign) MapType         mapType;
@property (nonatomic, assign) double          initLng;
@property (nonatomic, assign) double          initLat;
@property (nonatomic, retain) CArcgisInitInfo *arcgisInitInfo;

@end

/**
 *	@brief	播放地址
 */
@interface CRealPlayURL : NSObject
{
    NSString       *_url1;                                                      // vtdu地址
    NSString       *_url2;                                                      // mag地址
}

@property (nonatomic, copy)     NSString        *url1;
@property (nonatomic, copy)     NSString        *url2;

@end

/**
 *  报警cameraInfo
 */
@interface CAlarmCameraInfo : CCameraInfo
{
    NSInteger _type;
    NSString *_pictureUrl;
}
@property(nonatomic,assign)NSInteger type;
@property(nonatomic,copy)NSString *pictureUrl;


@end
/**
 *   消息信息
 */
@interface CMessage : NSObject
{
    NSString        *_strMessageID;                                             /**< 消息ID */
    MessageType      _messageType;                                              /**< 消息类型 */
    NSString        *_strMessageTitle;                                          /**< 消息标题 */
    NSString        *_strMessageContent;                                        /**< 消息内容 */
    NSString        *_strMessageDescription;                                    /**< 消息描述 */
    BOOL             _bChecked;                                                 /**< 是否已读标识 */
    NSTimeInterval   _lMessageCreateTime;                                       /**< 消息创建时间 */
    NSString        *_strCameraID;                                              /**< 监控点ID */
    NSString        *_strPicUrl;                                                /**< 图片url */
    double           _flongitude;                                               /**< 经度 */
    double           _flatitude;                                                /**< 纬度 */
    NSString        *_strLocation;
    NSArray         *_linkageCameraList;                                        /*联动监控点列表*/
}

@property (nonatomic, copy)     NSString        *strMessageID;
@property (nonatomic, assign)   MessageType      messageType;
@property (nonatomic, copy)     NSString        *strMessageTitle;
@property (nonatomic, copy)     NSString        *strMessageContent;
@property (nonatomic, copy)     NSString        *strMessageDescription;
@property (nonatomic, assign)   BOOL             bChecked;
@property (nonatomic, assign)   NSTimeInterval   lMessageCreateTime;
@property (nonatomic, copy)     NSString        *strCameraID;
@property (nonatomic, copy)     NSString        *strPicUrl;
@property (nonatomic, assign)   double           flongitude;
@property (nonatomic, assign)   double           flatitude;
@property (nonatomic, copy)     NSString        *strLocation;
@property (nonatomic, copy)      NSArray         *linkageCameraList;
@end

/**
 *   消息信息 v4.2
 */
@interface CKMSInfo : NSObject
{
    NSString        *_KMSUserName;                                       /**< KMS服务器用户名 */
    NSString        *_KMSPassword;                                       /**< KMS服务器密码 */
    NSString        *_KMSToken;                                          /**< KMS Token */

}

@property (nonatomic, copy)     NSString        *KMSUserName;
@property (nonatomic, copy)     NSString        *KMSPassword;
@property (nonatomic, copy)     NSString        *KMSToken;

@end

/**
 *  未读消息数信息
 */
@interface CUnreadMsgCountInfo : NSObject
{
    int     _iTotalCount;                                                       /**< 所有未读消息数量 */
    int     _iSMCount;                                                          /**< 未读系统消息数量 */
    int     _iPMCount;                                                          /**< 未读平台消息数量 */
    int     _iTMCount;                                                          /**< 未读任务消息数量 */
    int     _iAMCount;                                                          /**< 未读报警消息数量 */
}

@property (nonatomic, assign) int     iTotalCount;
@property (nonatomic, assign) int     iSMCount;
@property (nonatomic, assign) int     iPMCount;
@property (nonatomic, assign) int     iTMCount;
@property (nonatomic, assign) int     iAMCount;

@end

/**
 *  @author sunda, 16-02-25 16:02:14
 *
 *  最新软件信息
 */
@interface AppPlatformLatestAppInfo : NSObject

@property (nonatomic, copy) NSString *appURL;
@property (nonatomic, copy) NSString *latestVersion;
@property (nonatomic, copy) NSString *latestBuild;
@property (nonatomic, copy) NSString *updateInfo;

@end

/**
 *  @author sunda, 16-02-25 16:02:51
 *
 *  用户信息
 */
@interface AppPlatformUserInfo : NSObject

@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *contactAddress;
@property (nonatomic, copy) NSString *phoneNumber;
@property (nonatomic, copy) NSString *mailAddress;

@end
