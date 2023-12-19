//
//  AgoraMeetingLoginParams.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 @brief 登录参数
 */
@interface AgoraMeetingLoginParams : NSObject

/**
 @brief 从服务器获取的token
 */
@property (nullable, nonatomic, retain, readwrite) NSString * ticket;

/**
 @brief 用户编号
 */
@property (nullable, nonatomic, retain, readwrite) NSString * userid;

/**
 @brief 头像
 */
@property (nullable, nonatomic, retain, readwrite) NSString * avatar;

@end

NS_ASSUME_NONNULL_END
