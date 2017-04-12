//
//  UIColor+Hex.m
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import "UIColor+Hex.h"

@implementation UIColor (Hex)

+ (instancetype)colorWithHex:(NSUInteger)hex
{
    return [self colorWithHex:hex alpha:1.0];
}

+ (instancetype)colorWithHex:(NSUInteger)hex alpha:(CGFloat)alpha
{
    return [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 green:((float)((hex & 0xFF00) >> 8))/255.0 blue:((float)(hex & 0xFF))/255.0 alpha:alpha];
}

@end
