//
//  NSData+Encoding.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Encoding)

+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
- (NSString *)Base64EncodedString;

@end
