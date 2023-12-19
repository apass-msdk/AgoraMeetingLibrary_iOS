//
//  AMMeetingService.h
//  AgoraMeetingKit
//
//  Created by tx on 2022/7/10.
//

#import <Foundation/Foundation.h>
#import "AMErrorCode.h"
#import "AgoraMeetingCreateMeetingParams.h"
#import "AgoraMeetingJoinMeetingParams.h"
NS_ASSUME_NONNULL_BEGIN
typedef void (^AMMeetingCallBack)(AMErrorCode code,NSString* message);
typedef void (^AMCreateMeetingCallBack)(AMErrorCode code,NSString* message,NSString* meetingId,NSString* channelId);

/**
 @brief 会议服务
 */
@interface AMMeetingService : NSObject

/**
 @brief 创建会议
 @param createMeetingParams     参数
 @param createMeetingCallBack 结果的回调
 */
-(void)createMeeting:(AgoraMeetingCreateMeetingParams*) createMeetingParams callBack: (AMCreateMeetingCallBack) createMeetingCallBack;
 

 
/**
 @brief 加入会议
 @param joinMeetingParams     参数
 @param callBack 结果的回调
 */
-(void)joinMeeting:(AgoraMeetingJoinMeetingParams*) joinMeetingParams
          callBack: (AMMeetingCallBack)callBack;
 
 
 
@end

NS_ASSUME_NONNULL_END
