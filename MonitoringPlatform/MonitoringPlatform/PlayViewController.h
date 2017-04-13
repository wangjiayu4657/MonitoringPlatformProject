//
//  PlayViewController.h
//  TestSDK
//
//  Created by wangjiayu on 2017/4/12.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VMSNetSDK.h"

@interface PlayViewController : UIViewController

@property (nonatomic, strong) CCameraInfo *cameraInfo;
@property (nonatomic, copy)   NSString *serverAddress;
@property (nonatomic, strong) CMSPInfo *mspInfo;

@end
