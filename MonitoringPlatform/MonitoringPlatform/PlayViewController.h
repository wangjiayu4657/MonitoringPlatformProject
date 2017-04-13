//
//  PlayViewController.h
//  Demo-SDK3.0
//
//  Created by HuYafeng on 15/9/1.
//  Copyright (c) 2015年 sunda. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VMSNetSDK.h"

@interface PlayViewController : UIViewController

@property (nonatomic, strong) CCameraInfo *cameraInfo;
@property (nonatomic, copy)   NSString *serverAddress;
@property (nonatomic, strong) CMSPInfo *mspInfo;

@end
