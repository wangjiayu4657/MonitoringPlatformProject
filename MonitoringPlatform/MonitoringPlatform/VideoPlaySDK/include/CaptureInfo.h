//
//  CaptureInfo.h
//  PlayViewWork
//
//  Created by Dengsh on 13-10-18.
//  Copyright (c) 2013年 chenmengyu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CaptureInfo : NSObject
{
    NSString        *_strCapturePath;                                           /**< 大图路径 */
    NSString        *_strThumbnail;                                             /**< 缩略图路径 */
    NSString        *_strWaterMaskImg;                                          /**< 水印路径 */
    NSTimeInterval   _fimeInfo;                                                 /**< 抓图时间信息 */
    unsigned int     _nPicQuality;                                              /**< 大图图片质量 */
}

@property (nonatomic, strong) NSString      *strCapturePath;
@property (nonatomic, strong) NSString      *strThumbnail;
@property (nonatomic, strong) NSString      *strWaterMaskImg;
@property (nonatomic, assign) NSTimeInterval fTimeInfo;
@property (nonatomic, assign) unsigned int   nPicQuality;

@end
