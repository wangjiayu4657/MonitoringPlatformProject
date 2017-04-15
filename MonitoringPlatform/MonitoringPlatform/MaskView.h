//
//  MaskView.h
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void(^compelete)();

@interface MaskView : UIView

@property (weak, nonatomic) IBOutlet UILabel *contentLabel;

/** complete */
@property (nonatomic,strong) compelete backBlock;

@end
