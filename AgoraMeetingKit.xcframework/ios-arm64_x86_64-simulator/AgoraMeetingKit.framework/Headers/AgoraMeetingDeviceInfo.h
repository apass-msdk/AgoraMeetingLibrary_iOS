//
//  AgoraMeetingDeviceInfo.h
//  DeviceDemo
//
//  Created by yaodanliang on 2023/7/12.
//

#import <AgoraRtcKit/AgoraRtcKit.h>

NS_ASSUME_NONNULL_BEGIN

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
typedef NSObject AM_DEVICE_CLASS;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
typedef AgoraRtcDeviceInfo AM_DEVICE_CLASS;
#endif

@interface AgoraMeetingDeviceInfo : AM_DEVICE_CLASS

@property (assign, nonatomic) BOOL isVirtual;

- (instancetype)initWithDevice:(AM_DEVICE_CLASS *)device;

@end

NS_ASSUME_NONNULL_END
