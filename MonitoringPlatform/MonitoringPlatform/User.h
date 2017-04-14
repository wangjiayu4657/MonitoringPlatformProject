//
//  User.h
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject
/** servaddr */
@property (nonatomic,strong) NSString *servaddr;
/** username */
@property (nonatomic,strong) NSString *username;
/** password */
@property (nonatomic,strong) NSString *password;
+ (void) initWithDictionary:(NSDictionary *)dictionary;
+ (instancetype) shareUser;
@end
