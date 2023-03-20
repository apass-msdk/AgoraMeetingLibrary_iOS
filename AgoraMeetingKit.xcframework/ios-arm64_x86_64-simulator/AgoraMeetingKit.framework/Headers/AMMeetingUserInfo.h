//
//  AMMeetingUserInfo.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMMeetingUserInfo : NSObject

/**
 @brief  邮箱
 */
@property (nullable, nonatomic, retain, readwrite) NSString * email;

/**
 @brief 昵称
 */
@property (nullable, nonatomic, retain, readwrite) NSString * nickname;

/**
 @brief 手机号码
 */
@property (nullable, nonatomic, retain, readwrite) NSString * mobile;

/**
 @brief 用户ID
 */
@property (nullable, nonatomic, retain, readwrite) NSString * userid;

/**
 @brief 头像
 */
@property (nullable, nonatomic, retain, readwrite) NSString * avatar;

@end

NS_ASSUME_NONNULL_END
