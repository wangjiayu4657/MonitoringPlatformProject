//
//  PlayViewController.m
//  Demo-SDK3.0
//
//  Created by HuYafeng on 15/9/1.
//  Copyright (c) 2015年 sunda. All rights reserved.
//

#import "PlayViewController.h"
#import "VideoPlaySDK.h"
#import "VideoPlayInfo.h"
#import "CaptureInfo.h"
#import "VideoPlayUtility.h"
#import "RecordInfo.h"

static void *_vpHandle = NULL;

@interface PlayViewController ()

@property (weak, nonatomic) IBOutlet UIView *playView;
@property (weak, nonatomic) IBOutlet UIImageView *captureImageView;

@end

@implementation PlayViewController {
    CRealPlayURL *_realPlayURL;
    VP_HANDLE _handle;
    BOOL _isPlayBacking;
    CGFloat _startPlayBackTime;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//状态回调函数
void StatusCallBack(PLAY_STATE playState, VP_HANDLE hLogin, void *pHandl)
{
    NSLog(@"playState is %d", playState);
}

#pragma mark - Preview
- (IBAction)playAction:(UIButton *)sender {

    //获取播放地址
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    _realPlayURL = [[CRealPlayURL alloc] init];
    BOOL result = [vmsNetSDK getRealPlayURL:_serverAddress
                                toSessionID:_mspInfo.sessionID
                                 toCameraID:_cameraInfo.cameraID
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
    result = [vmsNetSDK getDeviceInfo:_serverAddress
                               toSessionID:_mspInfo.sessionID
                                toDeviceID:_cameraInfo.deviceID
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

//停止预览或回放
- (IBAction)stopAction:(UIButton *)sender {
    if (_vpHandle != NULL)
    {
        VP_Logout(_vpHandle);
        _vpHandle = NULL;
    }
}

#pragma mark - PlayBack
//开始回放
- (IBAction)playBackAction:(UIButton *)sender {
    [self startPlayBackFromTheTime:[NSDate date].timeIntervalSince1970 - 5*60]; //从5分钟前开始回放
}

//开始回放
- (BOOL)startPlayBackFromTheTime:(NSTimeInterval)timeInterval {
    if (_vpHandle != NULL)
    {
        VP_Logout(_vpHandle);
        _vpHandle = NULL;
    }
    
    //查询录像片段
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    formatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:timeInterval]; //Demo演示从5分钟前开始回放.如需在回放时调整回放时间，可以停止回放后立即用新的回放开始时间进行回放
    NSString *startPlayTimeStr = [formatter stringFromDate:date];
    ABSTIME stratTime; //查询录像片段的开始时间
    ABSTIME endTime;
    
    NSRange range;
    range.length = 4;
    range.location = 0;
    stratTime.year = endTime.year = [[startPlayTimeStr substringWithRange:range] intValue];
    
    range.location = 5;
    range.length = 2;
    stratTime.month = endTime.month = [[startPlayTimeStr substringWithRange:range] intValue];
    
    range.location = 8;
    stratTime.day = endTime.day = [[startPlayTimeStr substringWithRange:range] intValue];
    
    stratTime.hour = 0;
    stratTime.minute = 0;
    stratTime.second = 0;
    
    endTime.hour = 23;
    endTime.minute = 59;
    endTime.second = 59;
    
    CRecordInfo *recordInfo = [[CRecordInfo alloc] init];
    NSString *serverAddr = [[NSUserDefaults standardUserDefaults] objectForKey:_serverAddress];
    BOOL result = [vmsNetSDK queryCameraRecord:_serverAddress
                                   toSearchPos:(_cameraInfo.cascadeFlag == 1 ? SP_NCG : SP_VRM)
                                   toSessionID:_mspInfo.sessionID
                                    toCameraID:_cameraInfo.cameraID
                                  toRecordType:[NSString stringWithFormat:@"%d", RECORD_TYPE_PLAN]
                                   toRecordPos:[NSString stringWithFormat:@"%d", RECORD_POS_DEVICE]
                                   reocordGuid:nil
                                   toStartTime:&stratTime
                                     toEndTime:&endTime
                                  toRecordInfo:recordInfo];
    if(!result)
    {
        NSLog(@"get playback URL error");
        return NO;
    }
    
    // 播放
    VideoPlayInfo *videoInfo = [[VideoPlayInfo alloc] init];
    CDeviceInfo *deviceInfo = [[CDeviceInfo alloc] init];
    result = [vmsNetSDK getDeviceInfo:serverAddr
                          toSessionID:_mspInfo.sessionID
                           toDeviceID:_cameraInfo.deviceID
                         toDeviceInfo:deviceInfo]; //设备的用户名和密码, 需要调用VMSNetSDK中的接口 getDeviceInfo 获得的CDeviceInfo中属性：userName和password获取。
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
    videoInfo.strPlayUrl    = recordInfo.segmentListPlayUrl;
    videoInfo.protocalType  = PROTOCAL_TCP;
    videoInfo.playType      = PLAY_BACK;
    videoInfo.streamMethod  = STREAM_METHOD_VTDU;
    videoInfo.streamType    = STREAM_SUB;
    videoInfo.pPlayHandle   = (id)self.playView;
    
    NSString *tmpEndDateStr = [NSString stringWithFormat:@"%4d-%02d-%02d 23:59:59",stratTime.year,stratTime.month,stratTime.day];
    videoInfo.fStartTime    = [NSDate date].timeIntervalSince1970 - 5*60; //开始回放时间
    videoInfo.fStopTime     = [[formatter dateFromString:tmpEndDateStr] timeIntervalSince1970];//结束回放时间
    
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
    
    // 开始回放
    if (_vpHandle != NULL)
    {
        if (!VP_PlayBack(_vpHandle, videoInfo.fStartTime, videoInfo.fStopTime))
        {
            NSLog(@"start VP_PlayBack failed");
            return NO;
        }
    }
        return YES;
}

//暂停回放
- (IBAction)pausePlayBackActin:(UIButton *)sender {
    if (NULL == _vpHandle)
    {
        NSLog(@"not playing");
        return;
    }
    if (YES == _isPlayBacking) {
        // 暂停远程回放
        if (!VP_PausePlayBack(_vpHandle))
        {
            NSLog(@"VP_PausePlayBack failed error code is %ld", VP_GetLastError(_vpHandle));
            return;
        }
        _isPlayBacking = NO;
    }
    else
    {
        // 重新开始远程回放
        if (!VP_ResumePlayBack(_vpHandle))
        {
            NSLog(@"VP_ResumePlayBack failed");
            return;
        }
        _isPlayBacking = YES;
    }
}

//停止回放
- (IBAction)stopPlayBackAction:(UIButton *)sender {
    [self stopAction:nil];
}

//云台控制，其他云台控制动作可在SDK的头文件中查看
- (IBAction)ptzAction:(UIButton *)sender {
    
    // 是否有云台控制权限
    if (NO == _cameraInfo.isPTZControl)
    {
        NSLog(@"no ptz Control");
    }
    
    //确认操作类型
    int commandType = 0;
    switch (sender.tag) {
        case 12:
            commandType = PTZ_CMD_UP;
            break;
        case 13:
            commandType = PTZ_CMD_DOWN;
            break;
        case 14:
            commandType = PTZ_CMD_LEFT;
            break;
        case 15:
            commandType = PTZ_CMD_RIGHT;
            break;
        case 16:
            commandType = PTZ_CMD_BRIGHTEN;
            break;
        case 17:
            commandType = PTZ_CMD_DARKEN;
            break;
        case 18:
            commandType = PTZ_CMD_ZOOMOUT;
            break;
        case 19:
            commandType = PTZ_CMD_ZOOMIN;
            break;
        default:
            break;
    }
    
    //判断是开始云台命令还是停止云台
    VMSNetSDK *vmsNetSDK = [VMSNetSDK shareInstance];
    if (sender.tag != 20) {
        //发送云台开始动作命令
        [vmsNetSDK sendStartPTZCmd:_cameraInfo.acsIP
                            toPort:_cameraInfo.acsPort
                       toSessionID:_mspInfo.sessionID
                        toCameraID:self.cameraInfo.cameraID
                           toCmdID:commandType
                          toParam1:5
                          toParam2:0
                          toParam3:0
                          toParam4:0
                         toCascade:(1 == _cameraInfo.cascadeFlag)]; //3.0SDK云台控制为UDP方式发送命令
    } else {
        //发送云台停止动作命令
        [vmsNetSDK sendStopPTZCmd:_cameraInfo.acsIP
                           toPort:_cameraInfo.acsPort
                      toSessionID:_mspInfo.sessionID
                       toCameraID:_cameraInfo.cameraID
                        toCascade:(1 == _cameraInfo.cascadeFlag)]; //3.0SDK云台控制为UDP方式发送命令
    }
}

//抓图
- (IBAction)onClickCapture:(id)sender
{
    // 获取抓图信息
    CaptureInfo *captureInfo = [[CaptureInfo alloc] init];
    if (![VideoPlayUtility getCaptureInfo:self.cameraInfo.cameraID toCaptureInfo:captureInfo])
    {
        NSLog(@"getCaptureInfo failed");
    }
    
    // 设置抓图质量 1-100 越高质量越高
    captureInfo.nPicQuality = 80;
    if (NULL == _vpHandle)
    {
        NSLog(@"not playing");
        return;
    }
    
    // 抓图
    BOOL result = VP_Capture(_vpHandle, captureInfo);
    if (NO == result)
    {
        NSLog(@"VP_Capture failed");
    }
    [_captureImageView setImage:[UIImage imageWithContentsOfFile:captureInfo.strCapturePath]];
}

// 录像
- (IBAction)onClickStartRecord:(id)sender
{
    // 获取录像信息
    RecordInfo *recordInfo = [[RecordInfo alloc] init];
    BOOL result = [VideoPlayUtility getRecordInfo:self.cameraInfo.cameraID toRecordInfo:recordInfo];
    if (NO == result)
    {
        NSLog(@"getCaptureInfo failed");
    }
    if (NULL == _vpHandle)
    {
        NSLog(@"not playing");
        return;
    }
    
    // 开始录像,录像存储的路径等信息获取成功后会保存在“recordInfo”中，Demo中不再做显示
    result = VP_StartRecord(_vpHandle, recordInfo, false);
    if (NO == result)
    {
        NSLog(@"VP_StartRecord failed, error code is %ld", VP_GetLastError(_vpHandle));
    }
    
    //播放本地录制的视频时,方法和预览类似.只需设置strPlayUrl(本地录像文件的地址),pPlayHande,streamMethod(STREAM_METHOD_LOCAL).再执行VP_Login()和VP_StartPlayRecord()即可.更多本地录像相关的方法请参考VideoPlaySDK.h
}

// 停止录像
- (IBAction)onClickStopRecord:(id)sender
{
    if (NULL == _vpHandle)
    {
        NSLog(@"not playing");
        return;
    }
    
    // 结束录像
    if (!VP_StopRecord(_vpHandle))
    {
        NSLog(@"VP_StopRecord failed");
    }
}

@end
