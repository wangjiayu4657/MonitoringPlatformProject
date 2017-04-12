//
//  UIColor+Hex.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Hex)

+ (instancetype)colorWithHex:(NSUInteger)hex;
+ (instancetype)colorWithHex:(NSUInteger)hex alpha:(CGFloat)alpha;

@end
