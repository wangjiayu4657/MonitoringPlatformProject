//
//  ViewController.m
//  TestSDK
//
//  Created by wangjiayu on 2017/4/11.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "HomeViewController.h"
#import "MaskView.h"
#import "NSData+ImageContentType.h"
#import "UIImage+GIF.h"
#import "User.h"
#import "YLGIFImage.h"
#import "PlayVideoController.h"
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

    [self getUserInformation];
    
    self.cameraID = [[NSUserDefaults standardUserDefaults] objectForKey:@"cameraID"];
    self.uid = [[NSUserDefaults standardUserDefaults] objectForKey:@"uid"];
    self.deviceID = [[NSUserDefaults standardUserDefaults] objectForKey:@"deviceID"];

    self.requestBtn.imageView.backgroundColor = [UIColor clearColor];
    [self.requestBtn setImage:[YLGIFImage imageNamed:@"request.gif"] forState:UIControlStateNormal];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self stopAllTimer];
}

- (void)stopAllTimer {
    [self.timer1 invalidate];
    self.timer1 = nil;
    [self.timer2 invalidate];
    self.timer2 = nil;
}

- (IBAction)requestButton:(UIButton *)sender {
    [self addMaskView];
    [self initializeTimer];
}

- (void)addMaskView {
    __weak __typeof(self)weakSelf = self;
    self.mview = [[MaskView alloc] init];
    
    self.mview.backBlock = ^{
        [weakSelf stopAllTimer];
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf.mview removeFromSuperview];
            [weakSelf.navigationController popViewControllerAnimated:YES];
        });
    };
    self.mview.contentLabel.text = @"正在请求预览,请稍后...";
    [self.view addSubview:self.mview];
}

- (void) initializeTimer {
    self.timer1 = [NSTimer scheduledTimerWithTimeInterval:3.0 target:self selector:@selector(heartbeatRequest) userInfo:nil repeats:YES];
    self.timer2 = [NSTimer scheduledTimerWithTimeInterval:4.0 target:self selector:@selector(requestPreview) userInfo:nil repeats:YES];
    
    [[NSRunLoop currentRunLoop] addTimer:self.timer1 forMode:NSRunLoopCommonModes];
    [[NSRunLoop currentRunLoop] addTimer:self.timer2 forMode:NSRunLoopCommonModes];
}

- (IBAction)logoutButton:(id)sender {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.label.text = @"正在退出登录...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *param = [NSMutableDictionary dictionaryWithCapacity:2];
    param[@"cameralId"] = self.cameraID;
    param[@"userId"] = self.uid;
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/PreviewController/remove" params:param resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
//            NSLog(@"退出:%@",responseObject);
            [self cleanDisk];
            dispatch_async(dispatch_get_main_queue(), ^{
                [hud hideAnimated:YES];
                [hud removeFromSuperViewOnHide];
                [self.navigationController popViewControllerAnimated:YES];
            });
        }else {
            [hud hideAnimated:YES];
            [hud removeFromSuperViewOnHide];
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

///请求预览
- (void)requestPreview {
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@"cameralId"] = self.cameraID;
    dict[@"userId"] = [self.uid stringValue];
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/PreviewController/preview" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
//            NSLog(@"预览:%@",responseObject);
            NSInteger code = [responseObject[@"code"] integerValue];
            if (code == 200) {
                [self.timer2 invalidate];
                self.timer2 = nil;
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.mview removeFromSuperview];
                    [self performSegueWithIdentifier:@"pushVideoController" sender:nil];
                });
            }else {
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.mview.contentLabel.text = [NSString stringWithFormat:@"当前在线人数%@人,预计等候时间2分钟",responseObject[@"msg"]];
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
//    NSLog(@"%.1f",self.time);
    NSMutableDictionary *params = [NSMutableDictionary dictionaryWithCapacity:2];
    params[@"cameralId"] = self.cameraID;
    params[@"userId"] = [self.uid stringValue];
    
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/HeartbeatController/addHeart" params:params resultBlock:^(id responseObject, NSError *error) {
        if (!error) {

        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}


///获取平台信息
- (void)getUserInformation {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.label.text = @"加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@"cameralId"] = self.cameraID;
    dict[@"userId"] = [self.uid stringValue];
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/LoginInformationController/information" params:dict resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
//            NSLog(@"平台:%@",responseObject);
            [User initWithDictionary:responseObject[@"data"]];
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

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    PlayVideoController *destination = segue.destinationViewController;
    destination.compelete = ^{
        [self stopAllTimer];
    };
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

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
