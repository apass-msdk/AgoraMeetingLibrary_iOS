//
//  IInMeetingOTDataController.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/9/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 @brief OT数据控制器的的事件
 */
@protocol AgoraMeetingInMeetingOTDataDelegate <NSObject>
@optional

/**
 @brief 接受数据的事件
 */
- (void)onReceiveMessage:(NSDictionary *)dic;

@end

/**
 @brief OT数据控制器
 */
@interface InMeetingOTDataController : NSObject

/**
 @brief OT数据控制器的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingInMeetingOTDataDelegate> delegate;

/**
 @brief 删除OT数据
 @param groupName 群组名称
 @param key 关键字
 */
- (void)del:(NSString *)groupName key:(NSString *)key;

/**
 @brief 添加OT数据
 @param groupName 群组名称
 @param key 关键字
 @param value 值
 */
- (void)put:(NSString *)groupName key:(NSString *)key value:(NSString *)value;

/**
 @brief 得到群组的OT数据
 @param groupName 群组名称
 @return  数据
 */
- (NSDictionary *)getGroup:(NSString *)groupName;
@end

NS_ASSUME_NONNULL_END
