//
//  AgoraMeetingInitParams.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>
#import "AgoraMeetingInitAgoraParams.h"
#import "AgoraMeetingInitVideoParams.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
NS_ASSUME_NONNULL_BEGIN
/**
 @brief 初始化参数
 */
@interface AgoraMeetingInitParams : NSObject

/**
 @brief 断网之后是否事件分发
 */
@property (nonatomic, assign, readwrite) BOOL  isEventDispatch;

/**
 @brief 是否打印日志
 */
@property (nonatomic, assign, readwrite) BOOL  enableLog;

/**
 @brief websocket的地址
 */
@property (nullable, nonatomic, retain, readwrite) NSString * wsAddress;

/**
 @brief http接口的地址
 */
@property (nullable, nonatomic, retain, readwrite) NSString * serverUrl;

/**
 @brief rtc的appid
 */
@property (nullable, nonatomic, retain, readwrite) NSString * agoraAppId;

///**
// @brief 声网ID
// */
//@property (nullable, nonatomic, retain, readwrite) NSString * agoraAppId;


/**
 @brief socket超时设置
 */
@property (nonatomic, assign, readwrite) NSTimeInterval  joinMeetingTimeout;


/**
 @brief http超时设置
 */
@property (nonatomic, assign, readwrite) NSTimeInterval  httpTimeout;


/**
 @brief 设置是否开启声网私有化
 */
@property (nonatomic, assign, readwrite) BOOL  privateAgora;


/**
 @brief 日志目录设置
 */
@property (nullable, nonatomic, retain, readwrite) NSString * logdir;


/**
 @brief 日志过期天数 默认30天
 */
@property (nonatomic, assign, readwrite) NSInteger  logExpirationDays;

 


/**
 @brief 私有化声网的参数
 */
@property (nonatomic, strong) AgoraMeetingInitAgoraParams*  agoraParams;

/**
 @brief  视频的参数
 */
@property (nonatomic, strong) AgoraMeetingInitVideoParams*  videoParams;

@end

NS_ASSUME_NONNULL_END
