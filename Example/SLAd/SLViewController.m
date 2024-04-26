//
//  SLViewController.m
//  SLAd
//
//  Created by 刘士林 on 04/10/2024.
//  Copyright (c) 2024 刘士林. All rights reserved.
//

#import "SLViewController.h"
#import <DM_Link.h>
@interface SLViewController ()

@end

@implementation SLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [[DM_Link shareInstance] openAppWithUniversalLink:@"qw3"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
