//
//  DM_BannerAd.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/27.
//

#import <Foundation/Foundation.h>

@protocol DMBannerAdDelegate;
@class DM_BannerView;
NS_ASSUME_NONNULL_BEGIN

@interface DM_BannerAd : NSObject
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;
//竞价成功地址
@property (nonatomic , copy ,readonly) NSString * winNoticeUrl ;
//竞价失败地址
@property (nonatomic , copy, readonly) NSString * lnurl ;
/**
 广告视图
 */
@property (nonatomic,strong) DM_BannerView *bannerView;
@property (nonatomic , copy) NSString * materialId ;


/// 初始化信息流广告和配置代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter adTemplate 样式
- (instancetype)loadBannerAdTemplateAdWithSlotID:(NSString *)slotID delegate:(id<DMBannerAdDelegate>)delegate ;
//竞价成功的上报
- (void)biddingBannerSuccess:(long)price;
//竞价失败的上报
- (void)biddingBannerFailed:(long)price Code:(DMAdBiddingCode)code;

@end

@protocol DMBannerAdDelegate <NSObject>
/// 加载成功
- (void)bannerAdDidLoad :(DM_BannerAd*)bannerAd;
/// 加载失败
- (void)bannerAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)bannerAdDidRender:(DM_BannerAd*)bannerAd;;
/// 渲染失败
- (void)bannerAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)bannerAdDidShow:(DM_BannerAd *)bannerAd;
/// 广告被点击
- (void)bannerAdDidClick:(DM_BannerAd *)bannerAd;
/// 广告被关闭
- (void)bannerAdDidClose:(DM_BannerAd *)bannerAd;

@end

NS_ASSUME_NONNULL_END
