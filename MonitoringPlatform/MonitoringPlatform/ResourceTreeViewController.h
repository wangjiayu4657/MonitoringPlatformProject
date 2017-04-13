//
//  ResourceTreeViewController.h
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/12.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VMSNetSDK.h"

@interface ResourceTreeViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) CMSPInfo *mspInfo;
@property (nonatomic, copy)   NSString *serverAddress;
@property (nonatomic, strong) CControlUnitInfo *controlUnitInfo;
@property (nonatomic, strong) CRegionInfo *regionInfo;


@end
