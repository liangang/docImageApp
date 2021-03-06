//
//  RefreshView.h
//  TestRefreshView
//
//  Created by Jason Liu on 12-1-10.
//  Copyright 2012年 Yulong. All rights reserved.
//

// Refresh view controller show label 
#define REFRESH_LOADING_STATUS @"加载中..."
#define REFRESH_PULL_DOWN_STATUS @"下拉可以刷新..."
#define REFRESH_RELEASED_STATUS @"松开即刷新..."
#define REFRESH_UPDATE_TIME_PREFIX @"最后更新: "
#define REFRESH_HEADER_HEIGHT 60
#import <UIKit/UIKit.h>
@protocol RefreshViewDelegate;
@interface RefreshView : UIView {
    // UI
    UIImageView *refreshArrowImageView;
    UIActivityIndicatorView *refreshIndicator;
    UILabel *refreshStatusLabel;
    UILabel *refreshLastUpdatedTimeLabel;
    
    // 安装到哪个UIScrollView中
    UIScrollView *owner;
    
    // control
    BOOL isLoading;
    BOOL isDragging;
}
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *refreshIndicator;
@property (nonatomic, strong) IBOutlet UILabel *refreshStatusLabel;
@property (nonatomic, strong) IBOutlet UILabel *refreshLastUpdatedTimeLabel;
@property (nonatomic, strong) IBOutlet UIImageView *refreshArrowImageView;
@property (nonatomic, assign) BOOL isLoading;
@property (nonatomic, assign) BOOL isDragging;
@property (nonatomic, strong) UIScrollView *owner;
@property (nonatomic, weak) id<RefreshViewDelegate>delegate;// 触发有效事件后的delegate

// 安装refreshView
- (void)setupWithOwner:(UIScrollView *)owner delegate:(id)delegate;

// 开始加载和结束加载动画
- (void)startLoading;
- (void)stopLoading;

// 拖动过程中
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
@end
@protocol RefreshViewDelegate <NSObject>
// 只有向下拉时，有效的触发事件对外才是真正有用的
- (void)refreshViewDidCallBack;
@end
