//
//  DM_Link.m
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/26.
//

#import "DM_Link.h"

@interface DM_Link ()

@property (nonatomic, strong) UIProgressView *progressView;

@end
@implementation DM_Link

+(instancetype)shareInstance{
    
    static DM_Link *link = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        link = [[self alloc] init];
    });
    return link;
}
- (void)openAppWithUniversalLink:(nonnull NSString *)uLink {
//    NSURL *url = [NSURL URLWithString:uLink];
//    if ([kApplication canOpenURL:url]) {
//        if (@available(iOS 10.0, *)) {
//            [kApplication openURL:url options:@{} completionHandler:^(BOOL success) {
//                if(success){
//                    [[DMHTTPClient shareInstance] getEventUniversalTrackingURL:self.dpTrackingURL isSuccess:@"0"];
//                }else{
//                    [[DMHTTPClient shareInstance] getEventUniversalTrackingURL:self.dpTrackingURL isSuccess:@"1"];
//                }
//            }];
//        } else {
//            // Fallback on earlier versions
//        }
//    }
    NSLog(@"openAppWithUniversalLink");
    
}
-(void) openUrlAppStoreWithAppId:(NSString* )appId {
//    if (appId == nil || [appId isEqualToString:@""]) {
//        NSLog(@"openUrlAppStoreWithAppId open url fail! appId error!");
//        return;
//    }
//    dispatch_async(dispatch_get_main_queue(), ^{
//        float version = [[[UIDevice currentDevice] systemVersion] floatValue];
//        NSString * urlStr = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/app/id%@",appId];
//        if(version >= 10.0f) {
//            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlStr] options:[[NSDictionary alloc] init] completionHandler:^(BOOL success) {
//                if (success) {
//                    NSLog(@"openUrlAppStoreWithAppId open url success! url=%@",urlStr);
//                }else {
//                    NSLog(@"openUrlAppStoreWithAppId open url fail! url=%@",urlStr);
//                }
//            }];
//        } else {
//            if (version < 7.0f) {
//                urlStr = [NSString stringWithFormat:@"http://itunes.apple.com/us/app/id%@",appId];
//            }
//            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlStr]];
//        }
//    });
}

//- (DM_WebView*)openWebviewWithUrl:(nonnull NSString *)url {
//    DM_WebView * view = [[DM_WebView alloc]init];
//    view.urlStr = url;
//    return view;
//}
- (void)openWXWithUrl:(nonnull NSString *)url {
    // 动态检查WXApi类和相关方法是否可用
    Class wxApiClass = NSClassFromString(@"WXApi");
    SEL isWXAppInstalledSel = NSSelectorFromString(@"isWXAppInstalled");
    SEL isWXAppSupportApiSel = NSSelectorFromString(@"isWXAppSupportApi");
    SEL sendReqSel = NSSelectorFromString(@"sendReq:");

    if (wxApiClass && [wxApiClass respondsToSelector:isWXAppInstalledSel] && [wxApiClass respondsToSelector:isWXAppSupportApiSel] && [wxApiClass respondsToSelector:sendReqSel]) {
        // 检查是否安装了微信并且支持API调用
        BOOL isWXAppInstalled = ((BOOL (*)(id, SEL))[wxApiClass methodForSelector:isWXAppInstalledSel])(wxApiClass, isWXAppInstalledSel);
        BOOL isWXAppSupportApi = ((BOOL (*)(id, SEL))[wxApiClass methodForSelector:isWXAppSupportApiSel])(wxApiClass, isWXAppSupportApiSel);
        
        if (isWXAppInstalled && isWXAppSupportApi) {
            // 构造跳转小程序的请求
            Class reqClass = NSClassFromString(@"WXLaunchMiniProgramReq");
            SEL objectSel = NSSelectorFromString(@"object");
            if (reqClass && [reqClass respondsToSelector:objectSel]) {
                id launchMiniProgramReq = ((id (*)(id, SEL))[reqClass methodForSelector:objectSel])(reqClass, objectSel);
                
                [launchMiniProgramReq setValue:@"gh_xxxxxxx" forKey:@"userName"]; // 小程序原始ID
                [launchMiniProgramReq setValue:@"/pages/index/index" forKey:@"path"]; // 小程序页面路径
                [launchMiniProgramReq setValue:@(0) forKey:@"miniProgramType"]; // 正式版
                // 发送请求
                ((void (*)(id, SEL, id))[wxApiClass methodForSelector:sendReqSel])(wxApiClass, sendReqSel, launchMiniProgramReq);
            }
        } else {
            // 处理微信未安装或不支持API调用的情况
        }
    } else {
        // 微信SDK未集成的处理
    }
}
- (BOOL)isWeChatMiniProgramSupported {
    // 动态检查WXApi类和相关方法是否可用
//    Class wxApiClass = NSClassFromString(@"WXApi");
//    SEL isWXAppInstalledSel = NSSelectorFromString(@"isWXAppInstalled");
//    SEL isWXAppSupportApiSel = NSSelectorFromString(@"isWXAppSupportApi");
//    SEL sendReqSel = NSSelectorFromString(@"sendReq:");
//
//    if (wxApiClass && [wxApiClass respondsToSelector:isWXAppInstalledSel] && [wxApiClass respondsToSelector:isWXAppSupportApiSel] && [wxApiClass respondsToSelector:sendReqSel]) {
//        // 检查是否安装了微信并且支持API调用
//        BOOL isWXAppInstalled = ((BOOL (*)(id, SEL))[wxApiClass methodForSelector:isWXAppInstalledSel])(wxApiClass, isWXAppInstalledSel);
//        BOOL isWXAppSupportApi = ((BOOL (*)(id, SEL))[wxApiClass methodForSelector:isWXAppSupportApiSel])(wxApiClass, isWXAppSupportApiSel);
//        
//        if (isWXAppInstalled && isWXAppSupportApi) {
//            // 构造跳转小程序的请求
//            Class reqClass = NSClassFromString(@"WXLaunchMiniProgramReq");
//            SEL objectSel = NSSelectorFromString(@"object");
//            if (reqClass && [reqClass respondsToSelector:objectSel]) {
//                return YES;
//            }
//        } else {
//            // 处理微信未安装或不支持API调用的情况
//            return NO;
//        }
//    } else {
//        // 微信SDK未集成的处理
//        return NO;
//    }
    return NO;
}
- (BOOL)isUniversalLinkSupported{
    if (@available(iOS 10.0, *)) {
        return YES;
    } else {
        return NO;
    }
}

@end
