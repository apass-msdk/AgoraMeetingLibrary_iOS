//
//  InMeetingVideoController.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/7/13.
//

#import "AMErrorCode.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 会中视频控制器
 */
@interface InMeetingVideoController : NSObject

/**
 @brief 摄像头的状态
 @return YES:打开  NO:关闭
 */
- (BOOL)isOpenCamera;

/**
 @brief 打开摄像头
 @param open 打开
 @return 操作码
 */
- (AMErrorCode)openCamera:(BOOL)open;

/**
 @brief 接受主持人的请求来打开摄像头
 @param open 打开
 @param fromHost 是否是主持人的请求
 @return 操作码
 */
- (AMErrorCode)openCamera:(BOOL)open fromHost:(BOOL)fromHost;

/**
 @brief 接受主持人的请求来打开摄像头
 @param open 打开
 @param fromHost 是否是主持人的请求
 @param reason 原因
 @return 操作码
 */
- (AMErrorCode)openCamera:(BOOL)open fromHost:(BOOL)fromHost reason:(NSString *)reason;

/**
 @brief 切换前后摄像头
 @return 操作码
 */
- (AMErrorCode)switchCamera;

/**
 @brief 用户切换视频状态
 @return 操作码
 */
- (AMErrorCode)switchOpenCamera;

/**
 @brief 禁止接受某个用户的视频流
 @param userId 用户编号
 @param mute 是否禁止
 */
- (void)muteRemoteVideoStream:(NSString *)userId mute:(BOOL)mute;

/**
 @brief 前置摄像头的状态
 @return YES:打开  NO:关闭
 */
- (BOOL)isFrontCamera;

/**
 @brief 设置订阅的视频流类型
 @param userId 用户编号
 @param streamType 视频流类型。
 */
- (void)setRemoteVideoStream:(NSString *)userId
                        type:(AgoraVideoStreamType)streamType;

@end

NS_ASSUME_NONNULL_END
