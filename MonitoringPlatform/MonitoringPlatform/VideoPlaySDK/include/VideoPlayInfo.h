//
//  VideoPlayInfo.h
//  PlayViewWork
//
//  Created by Dengsh on 13-10-17.
//  Copyright (c) 2013年 chenmengyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VideoPlaySDK.h"

@interface VideoPlayInfo : NSObject
{
    NSString        *_strID;                                                    /**< 设备id，或者监控点id */
    long             _lChannel;                                                 /**< 通道号 */
    NSString        *_strDeviceIp;                                              /**< 设备ip */
    unsigned int     _nDevicePort;                                              /**< 设备端口 */
    NSString        *_strUser;                                                  /**< 设备用户名 */
    NSString        *_strPsw;                                                   /**< 设备密码 */
    NSString        *_strPlayUrl;                                               /**< 播放地址（如vtdu地址） */
    NSString        *_strExtentID;                                              /**< 扩展id */
    NSString        *_strExtentIp;                                              /**< 扩展ip */
    unsigned int     _nExtentPort;                                              /**< 扩展端口 */
    
    PROTOCAL_TYPE   _protocalType;                                              /**< 取流协议类型 */
    VP_STREAM_TYPE  _streamType;                                                /**< 主子码流 */
    STREAM_METHOD   _streamMethod;                                              /**< 取流方式 */
    PLAY_TYPE       _playType;                                                  /**< 播放模式 */
    
    NSTimeInterval  _fStartTime;                                                /**< 回放开始时间 */
    NSTimeInterval  _fStopTime;                                                 /**< 回放结束时间 */
        
    id              _pPlayHandle;                                               /**< 播放窗口 */
    BOOL            _bSystransform;                                             /**< 是否要开启转封装 */
    
    NSTimeInterval  _fStreamTimeOut;                                            /**< 最长不来流超时时间, 如果不设置，则默认为30秒 */
    
    unsigned int    _extentParam;                                               /**< 保留参数 */
}

@property (nonatomic, strong)   NSString        *strID;
@property (nonatomic, assign)   long             lChannel;
@property (nonatomic, strong)   NSString        *strDeviceIp;
@property (nonatomic, assign)   unsigned int     nDevicePort;
@property (nonatomic, strong)   NSString        *strUser;
@property (nonatomic, strong)   NSString        *strPsw;
@property (nonatomic, strong)   NSString        *strPlayUrl;
@property (nonatomic, strong)   NSString        *strExtentID;
@property (nonatomic, strong)   NSString        *strExtentIp;
@property (nonatomic, assign)   unsigned int     nExtentPort;
@property (nonatomic, assign)   PROTOCAL_TYPE    protocalType;
@property (nonatomic, assign)   VP_STREAM_TYPE   streamType;
@property (nonatomic, assign)   STREAM_METHOD    streamMethod;
@property (nonatomic, assign)   PLAY_TYPE        playType;
@property (nonatomic, assign)   NSTimeInterval   fStartTime;
@property (nonatomic, assign)   NSTimeInterval   fStopTime;
@property (nonatomic, assign)   id               pPlayHandle;
@property (nonatomic, assign)   BOOL             bSystransform;
@property (nonatomic, assign)   NSTimeInterval   fStreamTimeOut;
@property (nonatomic, assign)   unsigned int     extentParam;

@end
