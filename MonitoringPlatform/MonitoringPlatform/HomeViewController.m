//
//  ViewController.m
//  TestSDK
//
//  Created by wangjiayu on 2017/4/11.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "HomeViewController.h"
#import "ControlCenterViewController.h"

@interface HomeViewController ()

/** 请求数据 */
@property (nonatomic,strong) NSDictionary *dict;

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (IBAction)requestButton:(id)sender {
    [self requestPreview];
}
- (IBAction)logoutButton:(id)sender {
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *param = [NSMutableDictionary dictionaryWithCapacity:2];
    param[@"cameralId"] = @"";
    param[@"userId"] = @"";
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
    //@"http://115.29.53.215:8084/giscoop/LoginInformationController/information"
    NSString *urlString = @"http://115.29.53.215:8084/giscoop/PreviewController/preview";
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:2];
    dict[@""] = @"";
    dict[@""] = @"";
    [[HttpClient sharedClient] postPath:urlString params:nil resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            if ([responseObject[@"msg"] isEqualToString:@"成功"]) {
                self.dict = responseObject[@"data"];
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    [self performSegueWithIdentifier:@"pushCenterController" sender:nil];
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
