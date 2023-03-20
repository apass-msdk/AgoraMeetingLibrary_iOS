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

///**
// @brief 声网ID
// */
//@property (nullable, nonatomic, retain, readwrite) NSString * agoraAppId;


/**
 @brief socket超时设置
 */
@property (nonatomic, assign, readwrite) NSTimeInterval  socketTimeout;


/**
 @brief http超时设置
 */
@property (nonatomic, assign, readwrite) NSTimeInterval  httpTimeout;


/**
 @brief 设置是否开启声网私有化
 */
@property (nonatomic, assign, readwrite) BOOL  privateAgora;



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
