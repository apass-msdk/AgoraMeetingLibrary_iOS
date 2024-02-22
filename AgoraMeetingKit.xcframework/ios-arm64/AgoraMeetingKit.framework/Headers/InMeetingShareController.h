//
//  InMeetingShareController.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/7/13.
//

#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#import <Foundation/Foundation.h>
#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView AM_VIEW_CLASS;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView AM_VIEW_CLASS;
#endif
#import "AMErrorCode.h"
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 分享控制器的的事件
 */
@protocol AgoraMeetingInMeetingShareDelegate <NSObject>
@optional

/**
 @brief 其他用户正在分享屏幕
 */
- (void)onShareScreenJoinByOther;

/**
 @brief 当前用户正在分享屏幕
 */
- (void)onShareScreenStartByMySelf;

/**
 @brief 当前用户分享屏幕失败
 */
- (void)onShareScreenFailure:(int)error;

/**
 @brief 屏幕分享者发了变化
 @param uid 当前的分享者
 @param beforeUid 以前的分享者
 */
- (void)onShareScreenChange:(NSString *)uid beforeUid:(NSString *)beforeUid;

/**
 @brief 屏幕分享结束
 */
- (void)onShareScreenEnd:(NSString *)uid windowId:(NSString *)windowId;

/**
 @brief rtc共享第一帧的解码
 */
- (void)onShareFirstVideoDecoded:(NSString *)uid width:(CGFloat)width height:(CGFloat)height;

/**
 @brief rtc共享画面的改变
 */
- (void)onShareChangeVideoSize:(NSString *)uid width:(CGFloat)width height:(CGFloat)height;

@end

/**
 @brief 获取会中的分享控制器
 */
@interface InMeetingShareController : NSObject

/**
 @brief 分享控制器的的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingInMeetingShareDelegate> delegate;

/**
 @brief 设置播放共享视频的视图
 @param view 视图
 */
- (int)bindShareScreenView:(AM_VIEW_CLASS *)view;

/**
 @brief 设置播放共享视频的视图
 @param view 视图
 @param renderMode RENDER_MODE_HIDDEN (1)：优先保证视窗被填满。视频尺寸等比缩放，直至整个视窗被视频填满。如果视频长宽与显示窗口不同，多出的视频将被截掉。
 RENDER_MODE_FIT (2)：优先保证视频内容全部显示。视频尺寸等比缩放，直至视频窗口的一边与视窗边框对齐。如果视频长宽与显示窗口不同，视窗上未被填满的区域将被涂黑。
 @param mirrorMode
 AgoraVideoMirrorModeAuto
 0:（默认）由 SDK 决定镜像模式。
 AgoraVideoMirrorModeEnabled
 1: 启用镜像模式。
 AgoraVideoMirrorModeDisabled
 2: 关闭镜像模式。
 */
- (int)bindShareScreenView:(AM_VIEW_CLASS *)view
            withRenderMode:(AgoraVideoRenderMode)renderMode
            withMirrorMode:(AgoraVideoMirrorMode)mirrorMode;

/**
 @brief 解绑播放共享视频的视图
 @param view 视图
 */
- (int)removeShareScreenVideo:(AM_VIEW_CLASS *)view;

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE

/**
 @brief 开始屏幕共享
 @param mediaOptions 频道媒体设置选项
 @param screenCaptureParameters 屏幕共享的参数配置
 @return 操作码
 */
- (AMErrorCode)startShareScreenContent:(AgoraScreenCaptureParameters2 *)screenCaptureParameters
                          mediaOptions:(AgoraRtcChannelMediaOptions *)mediaOptions;

/**
 @brief 更新屏幕共享的配置
 @param mediaOptions 频道媒体设置选项
 @param screenCaptureParameters 屏幕共享的参数配置
 @return YES 修改成功 NO 修改失败
 */
- (BOOL)updateScreenCapture:(AgoraRtcChannelMediaOptions *)mediaOptions parameters:(AgoraScreenCaptureParameters2 *)screenCaptureParameters;

#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC

/**
 @brief 开启声卡采集。
 @param enabled
 YES: 开启声卡采集。
 NO:（默认）关闭声卡采集。
 */
- (int)enableLoopbackRecording:(BOOL)enabled;

/**
 @brief 获取可共享的屏幕和窗口对象列表
 @param thumbSize 屏幕或窗口的缩略图的目标尺寸（宽高单位为像素）
 @param iconSize 程序所对应的图标的目标尺寸（宽高单位为像素）
 @param includeScreen 除了窗口信息外，SDK 是否返回屏幕信息
 @return AgoraScreenCaptureSourceInfo 数组
 */
- (NSArray<AgoraScreenCaptureSourceInfo *> *_Nullable)getScreenCaptureSourcesWithThumbSize:(NSSize)thumbSize iconSize:(NSSize)iconSize includeScreen:(BOOL)includeScreen;

/**
 @brief 开始屏幕共享
 @param screenCaptureSourceInfo 共享信息
 @param mediaOptions 频道媒体设置选项
 @param screenCaptureParameters 屏幕共享的参数配置
 @param scenarioType 屏幕共享的场景
 @return 操作码
 */
- (AMErrorCode)startShareScreenContent:(AgoraScreenCaptureSourceInfo *)screenCaptureSourceInfo
                            parameters:(AgoraScreenCaptureParameters *)screenCaptureParameters
                          mediaOptions:(AgoraRtcChannelMediaOptions *)mediaOptions
                 screenCaptureScenario:(AgoraScreenScenarioType)scenarioType;
/**
 @brief 更新屏幕共享的配置
 @param mediaOptions 频道媒体设置选项
 @param screenCaptureParameters 屏幕共享的参数配置
 @return YES 修改成功 NO 修改失败
 */
- (BOOL)updateScreenCapture:(AgoraRtcChannelMediaOptions *)mediaOptions parameters:(AgoraScreenCaptureParameters *)screenCaptureParameters;

#endif

/**
 @brief 开始分享白板
 */
- (void)startShareWhiteBoardContent;

/**
 @brief 是否是当前分享的人
 @return true：是的 false：不是
 */
- (BOOL)isShareMaster;

/**
 @brief 是否是当前白板的分享者
 @return true：是的 false：不是
 */
- (BOOL)isShareWhiteBoard;

/**
 @brief 是否是当前屏幕的分享的人
 @return true：是的 false：不是
 */
- (BOOL)isShareScreen;

/**
 @brief 当前分享者的用户ID
 @return 当前分享者的用户ID
 */
- (NSString *)shareScreenUserId;

/**
 @brief 当前sdk是否是有人正在分享
 @return true：是的 false：不是
 */
- (BOOL)isSharing;

/**
 @brief 停止屏幕分享
 */
- (AMErrorCode)stopShareScreen;

/**
 * @return true：是的 false：不是
 * @brief  是否正在进行本地共享屏幕
 */
- (BOOL)isLocalSharing;

@end

NS_ASSUME_NONNULL_END
