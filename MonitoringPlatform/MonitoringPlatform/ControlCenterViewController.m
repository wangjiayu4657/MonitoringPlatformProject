//  Demo-SDK3.0
//
//  Created by sunda on 15/8/31.
//  Copyright (c) 2015年 sunda. All rights reserved.
//

#import "ControlCenterViewController.h"
#import "VMSNetSDK.h"
#import "VMSNetSDKDataType.h"
#import "ResourceTreeViewController.h"

@interface ControlCenterViewController (){
    NSMutableArray *_lineList;
    int _selectedLineID;
}

@property (weak, nonatomic) IBOutlet UITextField *serverAddressTextField;
@property (weak, nonatomic) IBOutlet UITextField *userNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *passwordTextField;
@property (weak, nonatomic) IBOutlet UIPickerView *linePickerView;
@property (weak, nonatomic) IBOutlet UIButton *loginButton;
@property (weak, nonatomic) IBOutlet UIButton *confirmButton;

@end

@implementation ControlCenterViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    //视图设置
    _userNameTextField.hidden = YES;
    _passwordTextField.hidden = YES;
    _loginButton.hidden = YES;
    _linePickerView.hidden = YES;
    _confirmButton.hidden = YES;
    self.title = @"登录";
    
    //设置代理和数据源
    _linePickerView.delegate = self;
    _linePickerView.dataSource = self;
    _serverAddressTextField.delegate = self;
}
#pragma mark - Button Action
- (IBAction)selectLineAction:(UIButton *)sender {
    //获取线路列表
//    _lineList = [NSMutableArray array];
//    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
//    if (_serverAddressTextField.text.length <= 7) {
//        _serverAddressTextField.text = @"http://111.40.20.65:82";
//        //        _serverAddressTextField.text = @"http://10.33.27.240"; //内网测试环境
//    }
//    BOOL result = [vmsNetSDK getLineList:_serverAddressTextField.text toLineInfoList:_lineList]; //执行方法后，将把线路列表写入_lineList
//    if (NO == result) {
//        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"提示"
//                                                            message:@"获取线路失败"
//                                                           delegate:nil cancelButtonTitle:@"好"
//                                                  otherButtonTitles:nil, nil];
//        [alertView show];
//        return;
//    }
//    [_serverAddressTextField resignFirstResponder];
//    
//    //让用户选择线路（或者程序中自动判断并选择最优线路)
//    _linePickerView.hidden = NO;
//    _confirmButton.hidden = NO;
//    [_linePickerView reloadAllComponents];
//    _selectedLineID = [_lineList[0] lineID];
    
}

- (IBAction)confirmAction:(UIButton *)sender {
    _linePickerView.hidden = YES;
    _confirmButton.hidden = YES;
    _userNameTextField.hidden = NO;
    _passwordTextField.hidden = NO;
    _loginButton.hidden = NO;
}

- (IBAction)loginAction:(UIButton *)sender {
    //登录
    CMSPInfo *mspInfo = [[CMSPInfo alloc] init];
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    if (0 == _userNameTextField.text.length && 0 == _passwordTextField.text.length) {
        _userNameTextField.text = @"admin"; //内网测试环境
        _passwordTextField.text = @"Abc123++";
    }
    BOOL result = [vmsNetSDK login:_serverAddressTextField.text
                        toUserName:_userNameTextField.text
                        toPassword:_passwordTextField.text
                          toLineID:_selectedLineID
                     passwordLevel:3 //用户密码强度由开发者自行判断,强度由弱到强分别为0,1,2,3
                        toServInfo:mspInfo]; //方法执行后，msp信息将写入mapInfo
    if (NO == result) {
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"提示"
                                                            message:@"登录失败"
                                                           delegate:nil cancelButtonTitle:@"好"
                                                  otherButtonTitles:nil, nil];
        [alertView show];
        return;
    }
    
    //登录成功后推到组织结构的控制器,并给其绑定数据
    ResourceTreeViewController *resourceTreeVC = [[ResourceTreeViewController alloc] init];
    resourceTreeVC.mspInfo = mspInfo;
    resourceTreeVC.serverAddress = _serverAddressTextField.text;
    [self.navigationController pushViewController:resourceTreeVC animated:YES];
}

#pragma mark - textField Delegate
- (void)textFieldDidBeginEditing:(UITextField *)textField {
    _serverAddressTextField.text = @"http://";
}

#pragma mark - PickView Delegate and DataSource
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return _lineList.count;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    CLineInfo *lineInfo = _lineList[row];
    return  [lineInfo lineName];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    _selectedLineID = [_lineList[row] lineID];
}

 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
     UIViewController *controller = [segue destinationViewController];
     NSLog(@"controller = %@",controller);
 }
 

@end
