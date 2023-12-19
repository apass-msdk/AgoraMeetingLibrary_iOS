//
//  InMeetingAudioController.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/7/13.
//

#import <Foundation/Foundation.h>
#import "AMErrorCode.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, AMAudioDeviceRouting) {
    
    
    /**
     @brief 听筒
     */
    AMAudioDeviceRoutingReceiver = 1,
    
    /**
     @brief 扬声器
     */
    AMAudioDeviceRoutingSpeaker= 2,
    
    /**
     @brief 蓝牙
     */
    AMAudioDeviceRoutingBlueTooth= 3,
    
    /**
     @brief 耳机
     */
    AMAudioDeviceRoutingHeadset = 4,
    
    
};

/**
 @brief 音频控制器的事件回调
 */
@protocol AgoraMeetingIInMeetingAudioDelegate <NSObject>
@optional

/**
 * @brief 音频路由已发生变化回调
 * @routing   当前的音频路由
 */
-(void)onAudioRouteChanged:(AMAudioDeviceRouting)routing;
 
@end


/**
 @brief 音频控制器
 */
@interface InMeetingAudioController: NSObject

/**
 @brief 音频控制器的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingIInMeetingAudioDelegate> delegate;

/**
 @brief 当前的音频路由
 @return 当前的音频路由
 */
-(AMAudioDeviceRouting) getAudioDeiceRouting;

/**
 @brief 是否打开麦克风
 @param open 是否打开
 @return 操作码
 */
-(AMErrorCode)openMicrophone:(BOOL)open;

/**
 @brief 接受主持人的请求来打开麦克风
 @param open 是否打开
 @param fromHost 是否来自主持人请求
 @return 操作码
 */
-(AMErrorCode)openMicrophone:(BOOL)open fromHost:(BOOL) fromHost;

/**
 @brief 接受主持人的请求来打开麦克风
 @param open 是否打开
 @param fromHost 是否来自主持人请求
 @param reason 原因
 @return 操作码
 */
-(AMErrorCode)openMicrophone:(BOOL)open fromHost:(BOOL) fromHost reason:(NSString*)reason;

/**
 @brief 打开或者关闭扬声器
 */
-(void)useSpeakerphone:(BOOL) isSpeakerphone;
 

/**
 @brief 切换静音操作
 @return 操作码
 */
-(AMErrorCode) switchOpenMicrophone;

/**
 @brief  检测是否连接蓝牙
 @return YES:连接  NO:未连接
 */
-(BOOL)isBleToothOutput;

/**
 @param level 0 关闭 1传统降噪 2 低级ai降噪 3高级ai降噪
 @brief 设置AI降噪等级
 */
-(void)setAiNsLevel:(int)level;

/**
 @return 0 关闭 1传统降噪 2 低级ai降噪 3高级ai降噪
 @brief 获取AI降噪等级
 */
-(int)getAiNsLevel;

/**
 @param profile 音频编码属性，包含采样率、码率、编码模式和声道数。详见 AgoraAudioProfile。
 @brief 设置音频编码属性。
 */
- (int)setAudioProfile:(AgoraAudioProfile)profile;

/**
 @param scenario 音频场景：
 AUDIO_SCENARIO_DEFAULT (0):（默认）自动场景，根据用户角色和音频路由自动匹配合适的音质。
 AUDIO_SCENARIO_GAME_STREAMING (3): 高音质场景，适用于音乐为主的场景。
 AUDIO_SCENARIO_CHATROOM (5): 聊天室场景，适用于用户需要频繁上下麦的场景。该场景下，观众会收到申请麦克风权限的弹窗提示。
 AUDIO_SCENARIO_CHORUS(7): 合唱场景。适用于网络条件良好，要求极低延时的实时合唱场景。
 AUDIO_SCENARIO_MEETING(8): 会议场景，适用于人声为主的多人会议。
 @brief 设置音频场景。。
 */
- (int)setAudioScenario:(AgoraAudioScenario)scenario;
@end

NS_ASSUME_NONNULL_END
