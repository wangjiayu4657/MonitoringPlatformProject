//
//  User.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "User.h"

@implementation User

+(instancetype)initWithDictionary:(NSDictionary *)dictionary {
    User *user = [[self alloc] init];
    [user setValuesForKeysWithDictionary:dictionary];
    return user;
}

- (void) setValue:(id)value forUndefinedKey:(NSString *)key {
    
}

@end
