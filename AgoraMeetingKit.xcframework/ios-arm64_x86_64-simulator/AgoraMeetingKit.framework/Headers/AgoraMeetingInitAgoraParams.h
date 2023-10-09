//
//  AgoraMeetingInitAgoraParams.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/10/8.
//

#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 私有化声网的参数
 */
@interface AgoraMeetingInitAgoraParams : NSObject
/**
 @brief 获取IP地址
 */
@property (copy, nonatomic) NSArray *_Nullable ipList;

/**
 @brief 获取domain地址
 */
@property (copy, nonatomic) NSArray *_Nullable domainList;

/**
 @brief 获取域名地址
 */
@property (nullable, nonatomic, retain, readwrite) NSString *verifyDomainName;

@property (assign, nonatomic) AgoraLocalProxyMode mode;

@end

NS_ASSUME_NONNULL_END
