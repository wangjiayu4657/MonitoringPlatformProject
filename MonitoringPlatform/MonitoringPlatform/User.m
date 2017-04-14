//
//  User.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "User.h"

@implementation User

+ (instancetype)shareUser {
    static User *user = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        user = [[self alloc] init];
    });
    return user;
}

+(void)initWithDictionary:(NSDictionary *)dictionary {
    User *user = [User shareUser];
    [user setValuesForKeysWithDictionary:dictionary];
}

- (void) setValue:(id)value forUndefinedKey:(NSString *)key {
    
}

@end
