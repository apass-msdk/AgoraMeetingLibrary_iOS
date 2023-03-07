//
//  IInMeetingRecordingController.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/12/7.
//

#import <Foundation/Foundation.h>
#import "AMRecordingInfo.h"
#import "AMErrorCode.h"
NS_ASSUME_NONNULL_BEGIN

typedef void (^AMInMeetingRecordingCallBack)(AMErrorCode code,NSString* message);
/**
 @brief 聊天控制器的的事件
 */
@protocol AgoraMeetingInMeetingRecordingDelegate <NSObject>
@optional

/**
@brief 开始云录制
 */
-(void)onMeetingRecordingStart:(AMRecordingInfo*) recordingInfo;

/**
 @brief 结束云录制
 */
-(void)onMeetingRecordingStop;
@end

@interface IInMeetingRecordingController : NSObject

/**
 @brief 云录制控制器的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingInMeetingRecordingDelegate> delegate;
/**
 @brief 开始云录制
 @param callBack 结果的回调
 */
-(void)startMeetingRecordingWithCallBack: (AMInMeetingRecordingCallBack)callBack;

/**
 @brief 结束云录制
 @param callBack 结果的回调
 */
-(void)stopMeetingRecordingWithCallBack: (AMInMeetingRecordingCallBack)callBack;

/**
 @brief 获取云录制记录
 */
-(AMRecordingInfo*)getRecordingInfo;

@end

NS_ASSUME_NONNULL_END
