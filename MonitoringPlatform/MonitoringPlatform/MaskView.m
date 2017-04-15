//
//  MaskView.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "MaskView.h"

@interface MaskView ()

@property (weak, nonatomic) IBOutlet UIImageView *imageView;


@end

@implementation MaskView

- (instancetype) init {
    if (self = [super init]) {
        self = [[[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:nil options:nil] lastObject];
        self.contentLabel.layer.borderWidth = 2.0;
        self.contentLabel.layer.borderColor = [UIColor colorWithRed:58 / 255.0 green:175 / 255.0 blue:142 / 255.0 alpha:1].CGColor;
        self.imageView.animationImages = @[
                                           [UIImage imageNamed:@"1.png"],
                                           [UIImage imageNamed:@"2.png"],
                                           [UIImage imageNamed:@"3.png"],
                                           [UIImage imageNamed:@"4.png"],
                                           [UIImage imageNamed:@"5.png"]
                                           ];
        self.imageView.animationDuration = 3.0;
        [self.imageView startAnimating];
    }
    self.frame = [UIScreen mainScreen].bounds;
    return self;
}


- (IBAction)logoutButton:(id)sender {
    
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self animated:YES];
    hud.label.text = @"正在退出登录...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *param = [NSMutableDictionary dictionaryWithCapacity:2];
    param[@"cameralId"] = [[NSUserDefaults standardUserDefaults] objectForKey:@"cameraID"];
    param[@"userId"] = [[NSUserDefaults standardUserDefaults] objectForKey:@"uid"];;
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/PreviewController/remove" params:param resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            [self cleanDisk];
            if ([responseObject[@"msg"] isEqualToString:@"成功"]) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    [hud removeFromSuperViewOnHide];
                });
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

- (void)cleanDisk {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults removeObjectForKey:@"userName"];
    [defaults removeObjectForKey:@"password"];
    [defaults removeObjectForKey:@"cameraID"];
    [defaults removeObjectForKey:@"deviceID"];
    [defaults removeObjectForKey:@"uid"];
    [defaults synchronize];
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
