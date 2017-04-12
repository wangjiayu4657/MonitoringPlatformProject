//
//  UIView+BorderLine.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, BorderLinePosition) {
    BorderLinePositionLeft,
    BorderLinePositionRight,
    BorderLinePositionTop,
    BorderLinePositionBottom
};

@interface UIView (BorderLine)

- (void)addBorderLineAtPosition:(BorderLinePosition)position;

@end
