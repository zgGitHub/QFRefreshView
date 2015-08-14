//
//  QFRefreshView.h
//  QFRefreshDemoByLiuWeiZhen
//
//  Created by qianfeng on 15/4/3.
//  Copyright (c) 2015年 刘威振. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, QFRefreshViewState) {
    QFRefreshViewStatePulling = 0,
    QFRefreshViewStateNormal,
    QFRefreshViewStateLoading
};

@class QFRefreshView;
typedef void (^QFRefreshViewHandler)(QFRefreshView *refreshView);

#pragma mark - QFRefreshView
@interface QFRefreshView : UIView
{
    QFRefreshViewState _state;
}

@property (nonatomic, copy) QFRefreshViewHandler handler;
@property (nonatomic, getter=isLoading) BOOL loading;

@property (nonatomic) QFRefreshViewState state;

- (void)startLoading;
- (void)stopLoading;

@end

// -----------------------------------------------------------------

#pragma mark - QFRefreshHeaderView
@interface QFRefreshHeaderView : QFRefreshView

@property (nonatomic, copy) void (^pullDownHandler)(QFRefreshView *refreshView);

@end

// -----------------------------------------------------------------

#pragma mark - QFRefreshFooterView
@interface QFRefreshFooterView : QFRefreshView

@property (nonatomic, copy) void (^pullUpHandler)(QFRefreshView *refreshView);

@end

// -----------------------------------------------------------------

@interface UIScrollView (refresh)

@property (nonatomic, copy) void (^pullDownHandler)(QFRefreshView *refreshView);
@property (nonatomic, copy) void (^pullUpHandler)(QFRefreshView *refreshView);
@property (nonatomic, strong) QFRefreshHeaderView *refreshHeaderView;
@property (nonatomic, strong) QFRefreshFooterView *refreshFooterView;
- (void)stopHeaderViewLoading;
- (void)stopFooterViewLoading;

@end
