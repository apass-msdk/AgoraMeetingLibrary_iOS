//
//  AgoraMeetingListMeetingParams.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief 会议列表参数
 */
@interface AgoraMeetingListMeetingParams : NSObject

/**
 @brief 会议状态
 @see "wating", "meeting", "finished"
 */
@property (nullable, nonatomic, retain, readwrite) NSString * status;
 
/**
 @brief 页码
 */
@property (nonatomic, assign, readwrite) int pageNum;

/**
 @brief 会议类型
 @see 'any' 所有会议，'onlyhost' 仅为主持人，'onlyparticipant' 仅为参会人
 */
@property (nullable, nonatomic, retain, readwrite) NSString * type;

/**
@brief 每页数量
 */
@property (nonatomic, assign, readwrite) int pageSize;

@end

NS_ASSUME_NONNULL_END
