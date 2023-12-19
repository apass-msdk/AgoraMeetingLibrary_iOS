//
//  AgoraMeetingKit.h
//  AgoraMeetingKit
//
//  Created by tx on 2022/7/10.
//

#import <Foundation/Foundation.h>
#import "AMAccountService.h"
#import "AgoraMeetingLoginParams.h"
#import "AMPreMeetingService.h"
#import "AMErrorCode.h"
#import "AMSettingsHelper.h"
#import "AgoraMeetingInitParams.h"
#import "AMMeetingService.h"
#import "AMRTCService.h"
#import "AMInMeetingService.h"
NS_ASSUME_NONNULL_BEGIN

typedef void(^AMForceLogoutCallback)(void);

typedef void(^AMTokenTimeoutCallback)(void);

typedef void(^AMMessageCallback)(NSString* message);

typedef void (^AMLoginCallBack)(AMErrorCode code,NSString* message);

typedef void (^AMInitializeCallBack)(AMErrorCode code,NSString* message);

/**
 @brief 提供了 SDK 调用的主要方法
 */
@interface AgoraMeetingKit  : NSObject

/**
 @brief 获取 AgoraMeetingKit 实例。
 */
+ (instancetype)sharedInstance;

/**
 @brief 用户收到服务器发送的消息的回调
 @param callback  服务器发送的消息的回调
 */
- (void)setOnMessageCallback:(AMMessageCallback)callback;

/**
 @brief 设置用户在其他设备被强制登录之后，收到的回调
 @param callback  被登录收到的回调
 */
- (void)setOnForceLogoutCallBack:(AMForceLogoutCallback)callback;

/**
 @brief 设置用Token过期之后，收到的回调
 @param callback  Token过期收到的回调
 */
- (void)setOnTokenTimeoutCallback:(AMTokenTimeoutCallback)callback;


/**
 @brief 初始化函数
 @param param 一些配置参数 详见 AgoraMeetingInitParams
 @param callBack 初始化之后的回调
 */
- (void)initialize:(AgoraMeetingInitParams*)param  withCallBack:(AMInitializeCallBack)callBack;

/**
 @brief 用户登录
 @param param 一些登录参数 详见 AgoraMeetingLoginParams
 @param callBack 登录之后的回调
 */
- (void)loginWithParam:(AgoraMeetingLoginParams*)param withCallBack:(AMLoginCallBack)callBack;
 
/**
 @brief 用户登录
 @param token 口令
 @param userid  用户编号
 @param avatar 头像
 @param callBack 登录之后的回调
 */
- (void)loginByToken:(NSString*)token
            withUserid:(NSString*)userid
            withAvatar:(NSString*)avatar withCallBack:(AMLoginCallBack)callBack;



/**
 @brief 强制登录
 @param param 一些登录参数 详见 AgoraMeetingLoginParams
 @param callBack 登录之后的回调
 */
- (void)forceLoginWithParam:(AgoraMeetingLoginParams*)param withCallBack:(AMLoginCallBack)callBack;

/**
 @brief 是否登录
 */
- (BOOL)isLogin;

/**
 @brief 登出
 */
- (void)logout;

/**
 @brief 是否初始化
 */
- (BOOL)isInitialize;

/**
 @brief 得到用户服务
 */
- (AMAccountService*)getAccountServic;
 
/**
 @brief 获取预定会议服务
 */
- (AMPreMeetingService*)getPreMeetingService;

/**
 @brief 获取会议服务
 */
- (AMMeetingService*)getMeetingService;

/**
 @brief 获取设置帮助类
 */
- (AMSettingsHelper*)getSettingsHelper;

/**
 @brief  获取会议中的服务
 */
- (AMInMeetingService*)getInMeetingService;

/**
 @brief  声网的RTC服务
 */
- (AMRTCService*)getRTCService;


-(NSDictionary*)getVersionInfo;


/**
 @brief  销毁当前sdk
 */
-(void)destory;


/**
 @brief  重制当前sdk
 */
-(void)rest;


@end

NS_ASSUME_NONNULL_END
