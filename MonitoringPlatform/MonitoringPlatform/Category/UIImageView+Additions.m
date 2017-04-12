//
//  UIImageView+Additions.m
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import "UIImageView+Additions.h"

@implementation UIImageView (Additions)

- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents
{
    self.userInteractionEnabled = YES;
    UIControl *touchControl = [[UIControl alloc] initWithFrame:self.bounds];
    [self addSubview:touchControl];
    
    [touchControl addTarget:target action:action forControlEvents:controlEvents];
}

@end
