//
//  AMPreMeetingService.h
//  AgoraMeetingKit
//
//  Created by tx on 2022/7/10.
//

#import "AMErrorCode.h"
#import "AMMeetingInfo.h"
#import "AgoraMeetingCreateMeetingParams.h"
#import "AgoraMeetingListMeetingParams.h"
#import "AgoraMeetingUpdateMeetingParams.h"
#import "AgoraMeetingUserSearchParams.h"
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
typedef void (^AMInfoMeetingCallBack)(AMErrorCode code, NSString *message, AMMeetingInfo *meetingInfo);
typedef void (^AMListMeetingCallBack)(AMErrorCode code, NSString *message, NSArray *meetings);
typedef void (^AMPreMeetingCallBack)(AMErrorCode code, NSString *message);
typedef void (^AMPreCreateMeetingCallBack)(AMErrorCode code, NSString *message, NSString *meetingId, NSString *channelId);
typedef void (^AMUserSearchCallBack)(AMErrorCode code, NSString *message, NSDictionary *dic);
/**
 @brief 预约会议服务
 */
@interface AMPreMeetingService : NSObject

/**
 @brief 创建会议
 @param createMeetingParams     参数
 @param createMeetingCallBack 结果的回调
 */
- (void)createMeeting:(AgoraMeetingCreateMeetingParams *)createMeetingParams callBack:(AMPreCreateMeetingCallBack)createMeetingCallBack;

/**
 @brief 更新会议
 @param updateMeetingParams     参数
 @param updateMeetingCallBack 结果的回调
 */
- (void)updateMeeting:(AgoraMeetingUpdateMeetingParams *)updateMeetingParams callBack:(AMPreMeetingCallBack)updateMeetingCallBack;

/**
 @brief 删除会议
 @param meetingId      会议ID
 @param deleteMeetingCallBack 结果的回调
 */
- (void)deleteMeeting:(NSString *)meetingId callBack:(AMPreMeetingCallBack)deleteMeetingCallBack;

/**
 @brief 取消会议
 @param meetingId      会议ID
 @param cancelMeetingCallBack 结果的回调
 */
- (void)cancelMeeting:(NSString *)meetingId callBack:(AMPreMeetingCallBack)cancelMeetingCallBack;

/**
 @brief 会议信息
 @param channelId     会议ID
 @param onInfoMeetingCallBack 结果的回调
 */
- (void)infoMeeting:(NSString *)channelId callBack:(AMInfoMeetingCallBack)onInfoMeetingCallBack;

/**
 @brief 会议列表
 @param params     参数
 @param onListMeetingCallBack 结果的回调
 */
- (void)listMeeting:(AgoraMeetingListMeetingParams *)params callBack:(AMListMeetingCallBack)onListMeetingCallBack;

/**
 @brief 搜索会员
 @param params     参数
 @param onListMeetingCallBack 结果的回调
 */
- (void)userSearch:(AgoraMeetingUserSearchParams *)params callBack:(AMUserSearchCallBack)onUserSearchCallBack;

@end

NS_ASSUME_NONNULL_END
