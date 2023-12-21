//
//  AgoraMeetingUpdateMeetingParams.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import "AgoraMeetingCreateMeetingParams.h"
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 会议更新参数
 */
@interface AgoraMeetingUpdateMeetingParams : AgoraMeetingCreateMeetingParams

/**
 @brief 会议编号
 */
@property (nullable, nonatomic, retain, readwrite) NSString *meetingId;
@end

NS_ASSUME_NONNULL_END
