//
//  AMSettingsHelper.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief 设置的默认的会议开启参数，结束进程之后，数据依然保留
 */
@interface AMSettingsHelper : NSObject

/**
 @brief 加入会议时，设置麦克风默认的状态
 @param open  YES:打开 NO：关闭
 */
-(void)setOpenMicrophoneWhenJoinMeeting:(BOOL)open;

/**
 @brief  当加入会议时，麦克风的状态
 @return  YES:打开 NO：关闭
 */
-(BOOL)isOpenMicrophoneWhenJoinMeeting;

/**
 @brief 加入会议时，设置摄像头默认的状态
 @param open  YES:打开 NO：关闭
 */
-(void)setOpenCameraWhenJoinMeeting:(BOOL)open;

/**
 @brief  当加入会议时，摄像头的状态
 @return  YES:打开 NO：关闭
 */
-(BOOL)isOpenCameraWhenJoinMeeting;

/**
 @brief 加入会议时，设置扬声器默认的状态
 @param open  YES:打开 NO：关闭
 */
-(void)setOpenSpeakerWhenJoinMeeting:(BOOL)open;

/**
 @brief  当加入会议时，扬声器的状态
 @return  YES:打开 NO：关闭
 */
-(BOOL)isOpenSpeakerWhenJoinMeeting;
@end

NS_ASSUME_NONNULL_END
