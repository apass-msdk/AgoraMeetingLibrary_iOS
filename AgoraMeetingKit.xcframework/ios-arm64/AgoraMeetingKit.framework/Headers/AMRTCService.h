//
//  AMRTCService.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/10/1.
//

#import <Foundation/Foundation.h>
#import "AMErrorCode.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView AM_VIEW_CLASS;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView AM_VIEW_CLASS;
#endif
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 声网的RTC类的的事件
 */
@protocol AMRTCServiceDelegate <NSObject>
@optional

/**
 @brief 电脑插入设备
 */
-(void)onAddDevice:(NSString * _Nonnull)deviceId type:(AgoraMediaDeviceType)deviceType;


/**
 @brief 电脑拔出设备
 */
-(void)onRemoveDevice:(NSString * _Nonnull)deviceId type:(AgoraMediaDeviceType)deviceType;


@end

/**
 @brief 声网的RTC服务
 */
@interface AMRTCService : NSObject

/**
 @brief 声网的RTC类的的事件回调
 */
@property (weak, nonatomic) id<AMRTCServiceDelegate> delegate;
 


/**
 @brief 切换前后摄像头
 */
-(AMErrorCode)switchCamera;

/**
 @brief 声网的RTC类
 @return 声网的RTC类
 */
-(AgoraRtcEngineKit*)getRtcEngine;

/**
 @brief 开始预览
 @return 操作码  0:成功 -7:询问权限
 */
- (AMErrorCode) startPreview;

/**
 @brief 停止预览
 */
- (void)stopPreview;

 

/**
 @brief 渲染预览组件
 @param view 原生的视图
 */
- (void)bindPreview:(AM_VIEW_CLASS*)view;

/**
 @brief 渲染预览组件
 @param view 原生的视图
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
-(void)bindPreview:(AM_VIEW_CLASS*)view
    withRenderMode:(AgoraVideoRenderMode)renderMode
    withMirrorMode:(AgoraVideoMirrorMode)mirrorMode;

/**
 @brief 更新本地视图显示模式
 @param mode RENDER_MODE_HIDDEN (1)：优先保证视窗被填满。视频尺寸等比缩放，直至整个视窗被视频填满。如果视频长宽与显示窗口不同，多出的视频将被截掉。
 RENDER_MODE_FIT (2)：优先保证视频内容全部显示。视频尺寸等比缩放，直至视频窗口的一边与视窗边框对齐。如果视频长宽与显示窗口不同，视窗上未被填满的区域将被涂黑。
 @param mirrorMode
 AgoraVideoMirrorModeAuto
 0:（默认）由 SDK 决定镜像模式。
 AgoraVideoMirrorModeEnabled
 1: 启用镜像模式。
 AgoraVideoMirrorModeDisabled
 2: 关闭镜像模式。
 */
- (int)setLocalRenderMode:(AgoraVideoRenderMode)mode
                   mirror:(AgoraVideoMirrorMode)mirror;
 
/**
 @brief 移除预览组件
 @param view 原生的视图
 */
- (void)removePreview:(AM_VIEW_CLASS*)view;
 
/**
 @brief 设置分辨率和码率
 @param size 分辨率
 @param frameRate 视频编码的帧率
 */
- (void)setVideoEncoderConfiguration:(CGSize)size      frameRate:(AgoraVideoFrameRate)frameRate;

/**
 @brief  是否开启虚拟化
 @param  enable  YES:开启  NO:关闭
 */
-(void)enableVirtualBackground:(BOOL)enable;

/**
 @brief 当前开启虚拟化状态
 @return  YES:开启  NO:关闭
 */
-(BOOL)enableVirtualBackground;

/**
 @brief  设置虚拟化参数
 @param  enable   YES:开启  NO:关闭
 @param  virtualBackgroundSource  参数
 */
- (void)enableVirtualBackground:(BOOL)enable backData:(AgoraVirtualBackgroundSource *) virtualBackgroundSource;
 

/**
 @brief  得到虚拟化参数
 @return AgoraVirtualBackgroundSource  参数
 */
-(AgoraVirtualBackgroundSource *)getVirtualBackgroundSource;



/**
 @brief  是否开启美颜
 @param  enable  YES:开启  NO:关闭
 */
-(void)enableBeautyEffect:(BOOL)enable;

/**
 @brief 当前开启美颜状态
 @return  YES:开启  NO:关闭
 */
-(BOOL)enableBeautyEffect;

/**
 @brief  设置美颜化参数
 @param  enable  YES:开启  NO:关闭
 @param  options  参数
 */
-(void)setBeautyEffectOptions:(BOOL)enable options:(AgoraBeautyOptions*)options;

/**
 @brief  得到美颜参数
 @return AgoraBeautyOptions  参数
 */
-(AgoraBeautyOptions *)getBeautyEffectOptions;


#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)

/**
 @brief 获取系统中所有的音视频设备
 @param type 设备的类型，包括音、视频采集或播放设备，详见 AgoraMediaDeviceType。
 @return 调用成功时，返回 AgoraRtcDeviceInfo NSArray 对象，包含所有的音视频设备。
 */
- (NSArray<AgoraRtcDeviceInfo *> * _Nullable)enumerateDevices:(AgoraMediaDeviceType)type;

/**
 @brief 设置 SDK 使用的音频采集设备跟随系统默认的音频采集设备。
 @param enable
 是否跟随系统默认的音频采集设备：
 YES：跟随。当系统默认的音频采集设备改变时，SDK 立即切换音频采集设备。
 NO：不跟随。只有当 SDK 使用的音频采集设备被移除后，SDK 才切换至系统默认的音频采集设备。

 **/
- (int) followSystemRecordingDevice:(BOOL)enable;

/**
 @brief 设置 SDK 使用的音频播放设备跟随系统默认的音频播放设备。
 @param enable
 是否跟随系统默认的音频播放设备：
 YES：跟随。当系统默认音频播放设备发生改变时，SDK 立即切换音频播放设备。
 NO：不跟随。只有当 SDK 使用的音频播放设备被移除后，SDK 才切换至系统默认的音频播放设备。
 */
- (int) followSystemPlaybackDevice:(BOOL)enable;

/**
 @brief 指定设备
 @param type 设备的类型，包括音、视频采集或播放设备，详见 AgoraMediaDeviceType
 @param deviceId 设备 ID。可通过 enumerateDevices 获取。插拔设备不会影响 deviceId
 @return 0: 方法调用成功。 小于0: 方法调用失败
 */
- (int)setDevice:(AgoraMediaDeviceType)type deviceId:(NSString * _Nonnull)deviceId;

/**
 @brief 获取当前设备名称。
 @param type 设备的类型，包括音、视频采集或播放设备
 @return 返回值
 */
- (AgoraRtcDeviceInfo * _Nullable)getDeviceInfo:(AgoraMediaDeviceType)type;

#endif

/**
 @brief 添加主回调事件。
 @param delegate 接口类用于 SDK 向 app 发送回调事件通知，app 通过继承该接口类的方法获取 SDK 的事件通知。 接口类的所有方法都有缺省（空）实现，app 可以根据需要只继承关心的事件
 */
-(void)addDelegte:(id<AgoraRtcEngineDelegate>)delegate;

/**
 @brief 移除主回调事件。
 @param delegate 接口类用于 SDK 向 app 发送回调事件通知，app 通过继承该接口类的方法获取 SDK 的事件通知。 接口类的所有方法都有缺省（空）实现，app 可以根据需要只继承关心的事件
 */
-(void)removeDelegte:(id<AgoraRtcEngineDelegate>)delegate;


/**
 @brief 开启音频的Dump记录
 @param isOpen  true：开启 false：关闭
 */
-(int)setAudioApmDump:(BOOL)isOpen;

@end

NS_ASSUME_NONNULL_END
