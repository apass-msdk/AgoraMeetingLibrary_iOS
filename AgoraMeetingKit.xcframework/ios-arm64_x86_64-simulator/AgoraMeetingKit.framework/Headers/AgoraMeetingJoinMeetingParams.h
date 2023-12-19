//
//  AgoraMeetingCreateMeetingParam.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>
 
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 创建会议参数
 */
@interface AgoraMeetingJoinMeetingParams : NSObject

 
/**
 @brief  通道ID
 */
@property (nullable, nonatomic, retain, readwrite) NSString * channelId;

/**
 @brief  密码
 */
@property (nullable, nonatomic, retain, readwrite) NSString * password;

/**
 @brief  昵称
 */
@property (nullable, nonatomic, retain, readwrite) NSString * nickname;
 
/**
 @brief  默认麦克风状态
 */
@property (nonatomic, assign, readwrite) BOOL microphone;


/**
@brief  默认摄像头状态
*/
@property (nonatomic, assign, readwrite) BOOL camera;


/**
@brief  默认扬声器状态
*/
@property (nonatomic, assign, readwrite) BOOL speaker;


/**
@brief  强制退出
*/
@property (nonatomic, assign, readwrite) BOOL force;


/**
 @brief 额外的字段
 */
@property (nullable, nonatomic, retain, readwrite) NSString * reserved ;


/**
 @brief 头像
 */
@property (nullable, nonatomic, retain, readwrite) NSString * avatar ;

 

@end

NS_ASSUME_NONNULL_END
