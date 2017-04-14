//
//  DeviceInfo.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/14.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "DeviceInfo.h"

@implementation DeviceInfo

+(instancetype)shareDevice {
    static DeviceInfo *info = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        info = [[self alloc] init];
    });
    return info;
}

+ (void)initWithDictionary:(NSDictionary *)dic {
    DeviceInfo *info = [DeviceInfo shareDevice];
    [info setValuesForKeysWithDictionary:dic];
}

- (void) setValue:(id)value forUndefinedKey:(NSString *)key {
    
}


@end
