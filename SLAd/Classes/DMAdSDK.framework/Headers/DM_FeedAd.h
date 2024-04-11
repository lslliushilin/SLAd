//
//  DM_FeedAd.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/27.
//

#import <Foundation/Foundation.h>

@protocol DMFeedAdDelegate;
@class DM_FeedView;
NS_ASSUME_NONNULL_BEGIN

@interface DM_FeedAd : NSObject
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
@property (nonatomic,strong) DM_FeedView *feedView;
@property (nonatomic , copy) NSString * materialId ;


/// 初始化信息流广告和配置代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter adTemplate 样式
- (instancetype)loadFeedAdTemplateAdWithSlotID:(NSString *)slotID delegate:(id<DMFeedAdDelegate>)delegate ;
//竞价成功的上报
- (void)biddingFeedSuccess:(long)price;
//竞价失败的上报
- (void)biddingFeedFailed:(long)price Code:(DMAdBiddingCode)code;

@end

@protocol DMFeedAdDelegate <NSObject>
/// 加载成功
- (void)feedAdDidLoad :(DM_FeedAd*)feedAd;
/// 加载失败
- (void)feedAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)feedAdDidRender:(DM_FeedAd*)feedAd;;
/// 渲染失败
- (void)feedAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)feedAdDidShow:(DM_FeedAd *)feedAd;
/// 广告被点击
- (void)feedAdDidClick:(DM_FeedAd *)feedAd;
/// 广告被关闭
- (void)feedAdDidClose:(DM_FeedAd *)feedAd;

@end

NS_ASSUME_NONNULL_END
