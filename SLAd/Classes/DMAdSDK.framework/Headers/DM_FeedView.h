//
//  DM_FeedView.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/3/28.
//

#import <UIKit/UIKit.h>
#import <DMAdSDK/DM_FeedAd.h>

NS_ASSUME_NONNULL_BEGIN
// 定义样式模板枚举
typedef NS_ENUM(NSInteger, DMFeedAdTemplate) {
//    左图右文
    DMFeedAdTemplateStyle1 = 1,
//    右图左文
    DMFeedAdTemplateStyle2 = 2,
//    上文下图
    DMFeedAdTemplateStyle3 = 3,
//    上图下文
    DMFeedAdTemplateStyle4 = 4,
//    自定义 会返回当前view 由用户来布局
    DMFeedAdTemplateCustom = 5
};

@class DM_ADModel;

typedef void(^ClickLinkEvent)(void);
typedef void(^ClickCloseEvent)(void);
typedef void(^DidShowEvent)(void);

@interface DM_FeedView : UIView
//背景view
@property (nonatomic, strong) UIView *bgView;
//背景image
@property (nonatomic, strong) UIImageView *adImageView;
//摇一摇gif
@property (nonatomic, strong) UIImageView *shakeView;
@property (nonatomic, strong) DM_ADModel *adModel;
//查看详情按钮
@property (nonatomic, strong) UIButton *jumpBtn;
//广告lab
@property (nonatomic, strong) UILabel *adLab;
//标题lab
@property (nonatomic, strong) UILabel *titleLab;
//关闭按钮
@property (nonatomic, strong) UIButton *closeBtn;
//app图片
@property (nonatomic, strong) UIImageView *appImageView;
//app lab
@property (nonatomic, strong) UILabel *appLab;
//当前的渲染模版
@property (nonatomic, assign) DMFeedAdTemplate adTemplate;

@property (nonatomic, copy) ClickLinkEvent linkEvent;
@property (nonatomic, copy) ClickCloseEvent closeEvent;
@property (nonatomic, copy) DidShowEvent showEvent;

-(instancetype)initWithFeedAdTemplate:(DMFeedAdTemplate)adTemplate;

@end

NS_ASSUME_NONNULL_END
