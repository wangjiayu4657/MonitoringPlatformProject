//
//  NSObject+Additions.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Additions)

- (NSInteger)toInt;
- (NSUInteger)toUInt;
- (NSString *)toString;
- (CGFloat)toFloat;
- (double)toDouble;
- (BOOL)toBool;

- (NSArray *)toArray;
- (NSDictionary *)toDictionary;

- (NSString *)JSONString;

@end
