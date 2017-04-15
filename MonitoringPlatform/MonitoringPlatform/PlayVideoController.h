//
//  PlayVideoController.h
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/14.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VMSNetSDK.h"

typedef void(^stopPlay)();
@interface PlayVideoController : UIViewController

/** 数据 */
//@property (nonatomic,strong) NSDictionary *param;

@property (nonatomic, strong) CCameraInfo *cameraInfo;
@property (nonatomic, strong) CMSPInfo *mspInfo;

/** 停止播放 */
@property (nonatomic,strong) stopPlay compelete;

@end
