//
//  IInMeetingChatController.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/10/26.
//

#import <Foundation/Foundation.h>
#import "AMChatMessageInfo.h"
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 聊天控制器的的事件
 */
@protocol AgoraMeetingIInMeetingChatDelegate <NSObject>
@optional

/**
 * @brief 新增消息成功所触发的事件
 * @param chatMessageInfo 消息
 */
-(void)onAddChatMessage:(AMChatMessageInfo *)chatMessageInfo;

/**
 * @brief 更新消息成功所触发的事件
 * @param chatMessageInfo 消息
 */
-(void)onUpdateChatMessage:(AMChatMessageInfo *)chatMessageInfo;

/**
 * @brief 删除消息成功所触发的事件
 * @param chatMessageInfo 消息
 */
-(void)onDeleteChatMessage:(AMChatMessageInfo *)chatMessageInfo;
@end

/**
 * @brief 获取会中的聊天控制器
 */
@interface InMeetingChatController : NSObject

/**
 @brief OT数据控制器的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingIInMeetingChatDelegate> delegate;

/**
 @brief 发送文字消息
 @param text 文字
 */
-(void)sendTextMessage:(NSString*) text;

/**
 @brief 发送文字消息
 @param localId 本地ID
 */
-(void)deleteMessage:(NSString*) localId;

/**
 @brief 根据本地ID重新发送失败了的消息
 @param localId 本地ID
 */
-(void)resendMessage:(NSString*) localId;

/**
 @brief 获取当前所有的消息
 @return 获取当前所有的消息
 */
-(NSArray*)getChatMessageList;
@end

NS_ASSUME_NONNULL_END
