//
//  MaskView.m
//  MonitoringPlatform
//
//  Created by wangjiayu on 2017/4/13.
//  Copyright © 2017年 wangjiayu. All rights reserved.
//

#import "MaskView.h"

@interface MaskView ()

@property (weak, nonatomic) IBOutlet UIImageView *imageView;


@end

@implementation MaskView

- (instancetype) init {
    if (self = [super init]) {
        self = [[[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:nil options:nil] lastObject];
        self.contentLabel.layer.borderWidth = 2.0;
        self.contentLabel.layer.borderColor = [UIColor colorWithRed:58 / 255.0 green:175 / 255.0 blue:142 / 255.0 alpha:1].CGColor;
        self.imageView.animationImages = @[
                                           [UIImage imageNamed:@"1.png"],
                                           [UIImage imageNamed:@"2.png"],
                                           [UIImage imageNamed:@"3.png"],
                                           [UIImage imageNamed:@"4.png"],
                                           [UIImage imageNamed:@"5.png"]
                                           ];
        self.imageView.animationDuration = 3.0;
        [self.imageView startAnimating];
    }
    self.frame = [UIScreen mainScreen].bounds;
    return self;
}


- (IBAction)logoutButton:(id)sender {
   
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
