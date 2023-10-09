//
//  InMeetingUserInfoReason.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString *const AM_REASON_SYSTEM;
extern NSString *const AM_REASON_MYSELF;
extern NSString *const AM_REASON_HOST_TO_ME;
extern NSString *const AM_REASON_HOST_TO_ALL;
extern NSString *const AM_REASON_ALLOW_MUTED;
extern NSString *const AM_REASON_MICROPHONE_ALLOW;
@interface InMeetingUserInfoReason : NSObject

@property (nullable, nonatomic, retain, readwrite) NSString *cameraReason;

@property (nullable, nonatomic, retain, readwrite) NSString *microphoneReason;

@property (nullable, nonatomic, retain, readwrite) NSString *nicknameReason;

@property (nullable, nonatomic, retain, readwrite) NSString *avatarReason;
@end

NS_ASSUME_NONNULL_END
