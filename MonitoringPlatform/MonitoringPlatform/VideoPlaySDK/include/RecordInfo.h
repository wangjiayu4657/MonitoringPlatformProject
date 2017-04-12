//
//  RecordInfo.h
//  PlayViewWork
//
//  Created by Dengsh on 13-10-18.
//  Copyright (c) 2013年 chenmengyu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RecordInfo : NSObject
{
    NSString        *_strRecordPath;                                            /**< 录像路径 */
    NSString        *_strThumbnail;                                             /**< 缩略图路径 */
    NSString        *_strRecPicPath;                                            /**< 大图路径 */
    NSString        *_strWaterMaskImg;                                          /**< 水印路径 */
    BOOL             _bSystransform;                                            /**< 是否转封装 */
    NSTimeInterval   _fTimeInfo;                                                /**< 录像开始时间 */
}

@property(nonatomic, strong) NSString       *strRecordPath;
@property(nonatomic, strong) NSString       *strThumbnail;
@property(nonatomic, strong) NSString       *strRecPicPath;
@property(nonatomic, strong) NSString       *strWaterMaskImg;
@property(nonatomic, assign) BOOL            bSystransform;
@property(nonatomic, assign) NSTimeInterval  fTimeInfo;

@end
