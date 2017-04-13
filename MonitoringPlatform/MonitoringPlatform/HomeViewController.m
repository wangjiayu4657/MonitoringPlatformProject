//
//  ViewController.m
//  TestSDK
//
//  Created by wangjiayu on 2017/4/11.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "HomeViewController.h"
#import "ControlCenterViewController.h"
#import "User.h"
#import "XTimer.h"
#import "MaskView.h"

@interface HomeViewController ()

/** 请求数据 */
@property (nonatomic,strong) NSDictionary *dict;

/** timer */
@property (nonatomic,strong) XTimer *timer1;
@property (nonatomic,strong) XTimer *timer2;

/** <#desciption#> */
@property (nonatomic,strong) MaskView *mview;

@end

@implementation HomeViewController




- (void)viewDidLoad {
    [super viewDidLoad];
//    NSLog(@"camera:%@",self.cameraID);
//    NSLog(@"uid:%@",self.uid);
    [self getUserInformation];
}



- (IBAction)requestButton:(UIButton *)sender {
    [self addMaskView];
    [self initializeTimer];
}

- (void)addMaskView {
    self.mview = [[MaskView alloc] init];
    self.mview.contentLabel.text = @"当前在线2人,预计等候时间2分钟";
    [self.view addSubview:self.mview];
}

- (void) initializeTimer {
    self.timer1 = [XTimer scheduledTimerWithTimeInterval:3.0 target:self selector:@selector(heartbeatRequest) userInfo:nil repeats:YES];
    self.timer2 = [XTimer scheduledTimerWithTimeInterval:4.0 target:self selector:@selector(requestPreview) userInfo:nil repeats:YES];
}

- (IBAction)logoutButton:(id)sender {
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *param = [NSMutableDictionary dictionaryWithCapacity:2];
    param[@"cameralId"] = self.cameraID;
    param[@"userId"] = self.uid;
    [[HttpClient sharedClient] postPath:@"http://192.168.0.108:8081/giscoop/PreviewController/remove http/1.1" params:param resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            if ([responseObject[@"msg"] isEqualToString:@"成功"]) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    
                });
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

///请求预览
- (void)requestPreview {
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@"cameralId"] = self.cameraID;
    dict[@"userId"] = [self.uid stringValue];
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/PreviewController/preview" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            NSLog(@"预览:%@",responseObject);
            NSInteger code = [responseObject[@"code"] integerValue];
            if (code == 200) {
                [self.timer2 stop];
                [self.timer2 invalidate];
                self.timer2 = nil;
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.mview removeFromSuperview];
                    [hud hideAnimated:YES];
                    [self performSegueWithIdentifier:@"pushCenterController" sender:nil];
                });
            }else {
                self.mview.contentLabel.text = responseObject[@"msg"];
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

///心跳
- (void) heartbeatRequest {
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@"cameralId"] = self.cameraID;
    dict[@"userId"] = [self.uid stringValue];
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/HeartbeatController/addHeart" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
//            NSLog(@"心跳 == %@",responseObject);
            if ([responseObject[@"msg"] isEqualToString:@"成功"]) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    //                    [self performSegueWithIdentifier:@"pushCenterController" sender:nil];
                });
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}


///获取平台信息
- (void)getUserInformation {
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@"cameralId"] = self.cameraID;
    dict[@"userId"] = [self.uid stringValue];
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/LoginInformationController/information" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            self.dict = responseObject[@"data"];
            if ([responseObject[@"msg"] isEqualToString:@"成功"]) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    
                });
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    UIViewController *destination = segue.destinationViewController;
    NSLog(@"dict = %@",self.dict);
    if ([destination respondsToSelector:@selector(setParam:)]) {
        [destination setValue:self.dict forKey:@"param"];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
