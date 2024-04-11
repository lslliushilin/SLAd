//
//  DM_InterstitialAd.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/27.
//

#import <Foundation/Foundation.h>

@protocol DMInterstitialAdDelegate;
@class DM_InterstitialView;
NS_ASSUME_NONNULL_BEGIN

@interface DM_InterstitialAd : NSObject
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;
//竞价成功地址
@property (nonatomic , copy ,readonly) NSString * winNoticeUrl ;
//竞价失败地址
@property (nonatomic , copy, readonly) NSString * lnurl ;
@property (nonatomic , copy) NSString * materialId ;

/// 初始化信息流广告和配置代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter adTemplate 样式
- (instancetype)loadInterstitialAdTemplateAdWithSlotID:(NSString *)slotID delegate:(id<DMInterstitialAdDelegate>)delegate ;
//竞价成功的上报
- (void)biddingInterstitialSuccess:(long)price;
//竞价失败的上报
- (void)biddingInterstitialFailed:(long)price Code:(DMAdBiddingCode)code;
//展示广告
-(void)showInterstitialViewInRootViewController:(UIViewController *)viewController;

@end

@protocol DMInterstitialAdDelegate <NSObject>
/// 加载成功
- (void)interstitialAdDidLoad :(DM_InterstitialAd*)interstitialAd;
/// 加载失败
- (void)interstitialAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)interstitialAdDidRender:(DM_InterstitialAd*)interstitialAd;;
/// 渲染失败
- (void)interstitialAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)interstitialAdDidShow:(DM_InterstitialAd *)interstitialAd;
/// 广告被点击
- (void)interstitialAdDidClick:(DM_InterstitialAd *)interstitialAd;
/// 广告被关闭
- (void)interstitialAdDidClose:(DM_InterstitialAd *)interstitialAd;

@end

NS_ASSUME_NONNULL_END
