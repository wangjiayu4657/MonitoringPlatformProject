//
//  LoginViewController.m
//  TestSDK
//
//  Created by wangjiayu on 2017/4/11.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "LoginViewController.h"
#import "HomeViewController.h"

@interface LoginViewController () <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UIView *backView;
@property (weak, nonatomic) IBOutlet UITextField *accountField;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *distanceTop;

/** cameraID */
@property (nonatomic,strong) NSString *cameraID;
/** deviceID */
@property (nonatomic,strong) NSString *deviceID;

@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardWillHide:) name:UIKeyboardWillHideNotification object:nil];
}

- (void)keyBoardWillShow:(NSNotification *)notify {
    CGFloat duration = [notify.userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    CGRect rect = [notify.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGFloat offsetY = CGRectGetMaxY(self.backView.frame) - rect.origin.y;
    if (offsetY > 0) {
        self.distanceTop.constant -= (offsetY + 10);
        [UIView animateWithDuration:duration animations:^{
            [self.view layoutIfNeeded];
        }];
    }
}

- (void)keyBoardWillHide:(NSNotification *)notify {
    CGFloat duration = [notify.userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    self.distanceTop.constant = 245;
    [UIView animateWithDuration:duration animations:^{
        [self.view layoutIfNeeded];
    }];
}


///验证
- (void)validation {
    if (self.accountField.text.length == 0) {
        [MBProgressHUD showError:@"账号不能为空" toView:self.view];
        return;
    }else if (self.passwordField.text.length == 0) {
        [MBProgressHUD showError:@"密码不能为空" toView:self.view];
        return;
    }
}


- (IBAction)loginButton:(UIButton *)sender {
    
    [self validation];
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self.view];
    hud.label.text = @"正在加载中...";
    hud.mode = MBProgressHUDModeText;
    [hud showAnimated:YES];
    NSMutableDictionary *parame = [NSMutableDictionary dictionary];
    parame[@"userName"] = self.accountField.text;
    parame[@"password"] = self.passwordField.text;
    [[HttpClient sharedClient] postPath:@"http://115.29.53.215:8084/giscoop/LoginInformationController/loginInformation" params:parame resultBlock:^(id responseObject, NSError *error) {
        if (!error) {
            NSLog(@"loginInfo = %@",responseObject);
            if ([responseObject[@"msg"] isEqualToString:@"登录成功"]) {
                if (responseObject[@"data"][@"mUserCameral"] != nil) {
                    self.cameraID = responseObject[@"data"][@"mUserCameral"][@"cameraID"];
                    self.deviceID = responseObject[@"data"][@"mUserCameral"][@"deviceID"];
                }
                dispatch_async(dispatch_get_main_queue(), ^{
                    [hud hideAnimated:YES];
                    [self performSegueWithIdentifier:@"pushHomeController" sender:nil];
                });
            }
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD showError:[NSString stringWithFormat:@"%@",error]];
            });
        }
    }];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

-(void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    UIViewController *destination = segue.destinationViewController;
    if ([destination respondsToSelector:@selector(setCameraID:)]) {
        [destination setValue:self.cameraID forKey:@"cameraID"];
    }
    if ([destination respondsToSelector:@selector(setDeviceID:)]) {
        [destination setValue:self.deviceID forKey:@"deviceID"];
    }
    
}


@end
