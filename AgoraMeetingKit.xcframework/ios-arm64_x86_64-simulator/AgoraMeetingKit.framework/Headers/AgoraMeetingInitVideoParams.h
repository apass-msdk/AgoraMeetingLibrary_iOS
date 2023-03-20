//
//  AgoraMeetingInitAgoraParams.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/10/8.
//

#import <Foundation/Foundation.h>
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 私有化声网的参数
 */
@interface AgoraMeetingInitVideoParams : NSObject

@property (strong, nonatomic)AgoraVirtualBackgroundSource *defaultVirtualBackgroundSource;
@property  (nonatomic, assign, readwrite) BOOL defaultEnableVirtualBackground;

@property (strong, nonatomic)AgoraBeautyOptions *defaultBeautyOptions;
@property  (nonatomic, assign, readwrite) BOOL defaultEnableBeautyEffect;

@property (nonatomic, assign, readwrite) AgoraVideoStreamType defaultVideoStreamType;
@property (strong, nonatomic) AgoraSimulcastStreamConfig *simulcastStreamConfig;

@end

NS_ASSUME_NONNULL_END
