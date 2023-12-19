//
//  AgoraMeetingAccountService.h
//  AgoraMeetingKit
//
//  Created by tx on 2022/7/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief 账号服务
 */
@interface AMAccountService : NSObject

/**
 @brief 账号名称
 */
-(NSString*)getAccountName;

/**
 @brief 账号头像
 */
-(NSString*)getAvatarImgUrl;

@end

NS_ASSUME_NONNULL_END
