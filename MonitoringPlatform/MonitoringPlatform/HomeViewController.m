//
//  ViewController.m
//  TestSDK
//
//  Created by wangjiayu on 2017/4/11.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "HomeViewController.h"
#import "ControlCenterViewController.h"
#import "XTimer.h"
#import "MaskView.h"
#import "NSData+ImageContentType.h"
#import "UIImage+GIF.h"
#import "User.h"
@interface HomeViewController ()

/** 请求数据 */
@property (nonatomic,strong) NSDictionary *dict;

/** timer */
@property (nonatomic,strong) NSTimer *timer1;
@property (nonatomic,strong) NSTimer *timer2;

/** 蒙板 */
@property (nonatomic,strong) MaskView *mview;
@property (weak, nonatomic) IBOutlet UIButton *requestBtn;

@property (nonatomic,assign)  CGFloat time;

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    NSLog(@"camera:%@",self.cameraID);
//    NSLog(@"uid:%@",self.uid);
    [self getUserInformation];
    
//    NSLog(@"%@",user.uid);
    
    self.cameraID = [[NSUserDefaults standardUserDefaults] objectForKey:@"cameraID"];
    self.uid = [[NSUserDefaults standardUserDefaults] objectForKey:@"uid"];
    self.deviceID = [[NSUserDefaults standardUserDefaults] objectForKey:@"deviceID"];
    NSLog(@"cameraID ==== %@",self.cameraID);
    NSLog(@"uid ==== %@",self.uid);
    NSLog(@"deviceID ==== %@",self.deviceID);
    
    NSString *filePath = [[NSBundle bundleWithPath:[[NSBundle mainBundle] bundlePath]] pathForResource:@"request" ofType:@"gif"];
    NSData  *imageData = [NSData dataWithContentsOfFile:filePath];
    self.requestBtn.imageView.backgroundColor = [UIColor clearColor];
//    [self.requestBtn setBackgroundImage:[UIImage sd_animatedGIFWithData:imageData] forState:UIControlStateNormal];
    [self.requestBtn setImage:[UIImage sd_animatedGIFWithData:imageData] forState:UIControlStateNormal];
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
    self.timer1 = [NSTimer scheduledTimerWithTimeInterval:3.0 target:self selector:@selector(heartbeatRequest) userInfo:nil repeats:YES];
    self.timer2 = [NSTimer scheduledTimerWithTimeInterval:4.0 target:self selector:@selector(requestPreview) userInfo:nil repeats:YES];
    
    [[NSRunLoop currentRunLoop] addTimer:self.timer1 forMode:NSRunLoopCommonModes];
    [[NSRunLoop currentRunLoop] addTimer:self.timer2 forMode:NSRunLoopCommonModes];
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
            [self cleanDisk];
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
    NSLog(@"dict === %@",dict);
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/PreviewController/preview" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            NSLog(@"预览:%@",responseObject);
            NSInteger code = [responseObject[@"code"] integerValue];
            if (code == 200) {
                [self.timer2 invalidate];
                self.timer2 = nil;
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.mview removeFromSuperview];
                    [hud hideAnimated:YES];
                    self.mview.contentLabel.text = responseObject[@"msg"];
                    [self performSegueWithIdentifier:@"pushVideoController" sender:nil];
                });
            }else {
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.mview.contentLabel.text = responseObject[@"msg"];
                });
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
    self.time += 3;
    if (self.time > 60 || self.time == 60) {
        self.time = 0;
        [self.timer1 invalidate];
        self.timer1 = nil;
        [[NSNotificationCenter defaultCenter] postNotificationName:@"timeOverflows" object:nil];
    }
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *params = [NSMutableDictionary dictionaryWithCapacity:2];
    params[@"cameralId"] = self.cameraID;
    params[@"userId"] = [self.uid stringValue];
    NSLog(@"dict = %@",params);
    
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/HeartbeatController/addHeart" params:params resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            NSLog(@"心跳 == %@",responseObject);
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
            NSLog(@"平台消息:%@",responseObject);
//            self.dict = responseObject[@"data"];
            [User initWithDictionary:responseObject[@"data"]];
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

//- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
//    UIViewController *destination = segue.destinationViewController;
//    if ([destination respondsToSelector:@selector(setParam:)]) {
//        [destination setValue:self.dict forKey:@"param"];
//    }
//}

- (void)cleanDisk {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults removeObjectForKey:@"userName"];
    [defaults removeObjectForKey:@"password"];
    [defaults removeObjectForKey:@"cameraID"];
    [defaults removeObjectForKey:@"deviceID"];
    [defaults removeObjectForKey:@"uid"];
    [defaults synchronize];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
