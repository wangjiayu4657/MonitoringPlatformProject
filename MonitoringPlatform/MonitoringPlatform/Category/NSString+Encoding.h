//
//  NSString+Encoding.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Encoding)

- (NSString *)URLEncode;
- (NSString *)URLDecode;
- (NSString *)Base64Encode;
- (NSString *)MD5Encode;
- (NSString *)SHA1Encode;
- (NSData *)HMACSHA1WithSecretKey:(NSString *)secretKey;

@end
