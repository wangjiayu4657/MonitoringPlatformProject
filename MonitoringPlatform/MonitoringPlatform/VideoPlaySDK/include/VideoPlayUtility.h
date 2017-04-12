//
//  VideoPlayUtility.h
//  PlayViewWork
//
//  Created by Dengsh on 13-10-21.
//  Copyright (c) 2013年 chenmengyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VideoPlaySDK.h"

@class CaptureInfo;
@class RecordInfo;

@interface VideoPlayUtility : NSObject

/**
 *	@brief	将double类型的时间转化成结构类型的时间
 *
 *	@param 	fTime 	double类型的时间
 *	@param 	pStructTime 	结构类型的时间
 */
+(void)transformNSTimeInterval:(NSTimeInterval)fTime
                      toStruct:(TIME_STRUCT *)pStructTime;

/**
 *	@brief	将结构类型的时间转化成double类型的时间
 *
 *	@param 	structTime 	结构类型的时间
 *	@param 	pfTime 	double类型的时间
 */
+(void)transformStruct:(TIME_STRUCT)structTime
      toNSTimeInterval:(NSTimeInterval *)pfTime;

/**
 *	@brief	生成抓图信息
 *
 *	@param 	strCameraID 	监控点或者设备标识
 *	@param 	captureInfo 	抓图信息
 *
 *	@return	YES 成功 NO 失败
 */
+(BOOL)getCaptureInfo:(NSString *)strCameraID
        toCaptureInfo:(CaptureInfo *)captureInfo;

/**
 *	@brief	生成录像信息
 *
 *	@param 	strCameraID 	监控点或者设备标识
 *	@param 	recordInfo 	录像信息
 *
 *	@return	YES 成功 NO 失败
 */
+(BOOL)getRecordInfo:(NSString *)strCameraID
        toRecordInfo:(RecordInfo *)recordInfo;

@end
