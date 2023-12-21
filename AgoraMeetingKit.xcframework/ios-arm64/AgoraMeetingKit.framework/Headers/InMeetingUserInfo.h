//
//  InMeetingUserInfo.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import "AMMeetingUserInfo.h"
#import "InMeetingUserInfoReason.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 会中用户数据
 */
@interface InMeetingUserInfo : AMMeetingUserInfo

/**
 @brief  麦克风状态
 */
@property (nullable, nonatomic, retain, readwrite) NSString *microphone;

/**
 @brief  举手状态
 */
@property (nullable, nonatomic, retain, readwrite) NSString *raisehand;

/**
 @brief  摄像头状态
 */
@property (nullable, nonatomic, retain, readwrite) NSString *camera;

/**
 @brief  用户的声网ID
 */
@property (nonatomic, assign, readwrite) long agoraUserId;

/**
 @brief  用户的分享声网ID
 */
@property (nonatomic, assign, readwrite) long agoraShareUserId;

/**
 @brief  扩展字段
 */
@property (nullable, nonatomic, retain, readwrite) NSString *reserved;

/**
 @brief 各种原因
 */
@property (nonatomic, strong) InMeetingUserInfoReason *reason;

/**
 @brief  是否是主持人
 */
- (BOOL)isHost;

/**
 @brief  是否正在申请打开摄像头
 */
- (BOOL)isApplyOpenCamera;

/**
 @brief  是否正在申请打开麦克风
 */
- (BOOL)isApplyOpenMicrophone;

/**
 @brief  是否是执行主持人
 */
- (BOOL)isActingHost;

/**
 @brief  是否是联席主持人
 */
- (BOOL)isCoHost;

/**
 @brief  是否是原始主持人
 */
- (BOOL)isOriginHost;

/**
 * @biref
 * SUB_STATE_NO_SUBSCRIBED (1): 订阅失败。
 * SUB_STATE_IDLE (0): 加入频道后的初始订阅状态。
 * SUB_STATE_SUBSCRIBING (2): 正在订阅。
 * SUB_STATE_SUBSCRIBED (3): 收到了远端流，订阅成功。
 */
- (AgoraStreamSubscribeState)getVideoSubscribeState;

/**
 * @biref
 * 0：视频大流。
 * 1：视频小流。
 * -1:默认大小
 */
- (int)getStreamType;

/**
 * @biref 是否在rtc的频道内
 */
- (BOOL)isInRtcChannel;

@end

NS_ASSUME_NONNULL_END
