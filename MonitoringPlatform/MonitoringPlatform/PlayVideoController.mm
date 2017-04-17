//
//  PlayVideoController.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/14.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "PlayVideoController.h"
#import "VideoPlaySDK.h"
#import "VideoPlayInfo.h"
#import "CaptureInfo.h"
#import "VideoPlayUtility.h"
#import "RecordInfo.h"
#import "User.h"
static void *_vpHandle = NULL;


@interface PlayVideoController ()
@property (weak, nonatomic) IBOutlet UIView *playView;

@end

@implementation PlayVideoController{
    CRealPlayURL *_realPlayURL;
    VP_HANDLE _handle;
    BOOL _isPlayBacking;
    CGFloat _startPlayBackTime;
    int _selectedLineID;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(timeOut) name:@"timeOverflows" object:nil];
    _selectedLineID = 1;
}

- (void)timeOut {
    if (self.compelete) {
        self.compelete();
    }
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"温馨提示:" message:@"您的观看时间已结束，请重新排队观看!" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"好" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self.navigationController popViewControllerAnimated:YES];
    }];
    [alert addAction:ok];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    //登录
    self.mspInfo = [[CMSPInfo alloc] init];
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    User *user = [User shareUser];
    NSLog(@"%@ \n %@ \n %@",user.servaddr,user.username,user.password);
    BOOL result = [vmsNetSDK login:user.servaddr
                        toUserName:user.username
                        toPassword:user.password
                          toLineID:_selectedLineID
                     passwordLevel:3 //用户密码强度由开发者自行判断,强度由弱到强分别为0,1,2,3
                        toServInfo:self.mspInfo]; //方法执行后，msp信息将写入mapInfo
    if (NO == result) {
//        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"提示"
//                                                            message:@"登录失败"
//                                                           delegate:nil cancelButtonTitle:@"好"
//                                                  otherButtonTitles:nil, nil];
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:@"登录失败" preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *ok = [UIAlertAction actionWithTitle:@"好" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [self.navigationController popViewControllerAnimated:YES];
        }];
        [alert addAction:ok];
        [self presentViewController:alert animated:YES completion:nil];
//        [alertView show];
        return;
    }
    NSLog(@"mspInfo = %@",self.mspInfo);
    [self playVideo];
}

//状态回调函数
void StatusCallBack(PLAY_STATE playState, VP_HANDLE hLogin, void *pHandl)
{
    NSLog(@"playState is %d", playState);
}


- (void)playVideo {
    User *user = [User shareUser];
    NSString *cameraID = [[NSUserDefaults standardUserDefaults] objectForKey:@"cameraID"];
    NSString *deviceID = [[NSUserDefaults standardUserDefaults] objectForKey:@"deviceID"];
//    NSLog(@"_serverAddress = %@",user.servaddr);
//    NSLog(@"sessionID = %@",_mspInfo.sessionID);
//    NSLog(@"cameraID = %@",cameraID);
//    NSLog(@"_realPlayURL = %@",_realPlayURL);
    //获取播放地址
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    _realPlayURL = [[CRealPlayURL alloc] init];
    BOOL result = [vmsNetSDK getRealPlayURL:user.servaddr
                                toSessionID:_mspInfo.sessionID
                                 toCameraID:cameraID
                              toRealPlayURL:_realPlayURL
                               toStreamType:STREAM_SUB]; //StreamType＝0时，返回主码流和MAG地址，其＝1时返回子码流和MAG地址
    if (NO == result) {
        [[[UIAlertView alloc] initWithTitle:@"提示"
                                    message:@"获取播放地址失败"
                                   delegate:nil
                          cancelButtonTitle:@"好"
                          otherButtonTitles:nil, nil] show];
    }
    
    //获取设备信息
    VideoPlayInfo *videoInfo = [[VideoPlayInfo alloc] init];
    CDeviceInfo *deviceInfo = [[CDeviceInfo alloc] init];
    result = [vmsNetSDK getDeviceInfo:user.servaddr
                          toSessionID:_mspInfo.sessionID
                           toDeviceID:deviceID
                         toDeviceInfo:deviceInfo];
    
    // 设备的用户名和密码, 需要调用VMSNetSDK中的接口 getDeviceInfo 获得的CDeviceInfo中属性：userName和password获取。
    if(result)
    {
        videoInfo.strUser = deviceInfo.userName;
        videoInfo.strPsw = deviceInfo.password;
    }
    else
    {
        videoInfo.strUser   = @"admin";
        videoInfo.strPsw    = @"12345";
    }
    
    //填充vidioInfo
    videoInfo.strID =  _cameraInfo.cameraID;
    videoInfo.protocalType  = PROTOCAL_UDP;
    videoInfo.playType      = REAL_PLAY;
    videoInfo.streamMethod  = STREAM_METHOD_VTDU;
    VP_STREAM_TYPE streamType = STREAM_SUB;
    videoInfo.streamType    = streamType;
    videoInfo.pPlayHandle   = (id)self.playView;
    videoInfo.bSystransform = NO;
    videoInfo.strPlayUrl = _realPlayURL.url1;
    
    if (_vpHandle != NULL)
    {
        VP_Logout(_vpHandle);
        _vpHandle = NULL;
    }
    
    // 获取VideoPlaySDK 播放句柄
    if (_vpHandle == NULL)
    {
        _vpHandle = VP_Login(videoInfo);
    }
    
    // 设置状态回调
    if (_vpHandle != NULL)
    {
        VP_SetStatusCallBack(_vpHandle, StatusCallBack, (__bridge void *)self);
    }
    
    // 开始实时预览
    if (_vpHandle != NULL)
    {
        if (!VP_RealPlay(_vpHandle))
        {
            NSLog(@"start VP_RealPlay failed");
        }
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
