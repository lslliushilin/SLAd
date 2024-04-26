//
//  DM_Link.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DM_Link : NSObject
/**
 u-link的上报
 */
@property (nonatomic,copy) NSString *dpTrackingURL;

+(instancetype)shareInstance;

//通过UniversalLink 打开外部应用
-(void)openAppWithUniversalLink:(NSString* )uLink;
//通过 appid 打开 appstore
-(void)openUrlAppStoreWithAppId:(NSString* )appId;
//打开微信小程序
-(void)openWXWithUrl:(NSString* )url;
//是否支持微信小程序
- (BOOL)isWeChatMiniProgramSupported;
//是否支持UniversalLink
- (BOOL)isUniversalLinkSupported;
@end

NS_ASSUME_NONNULL_END
