//
//  AMMeetingInfo.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMMeetingInfo : NSObject
@property (nullable, nonatomic, retain, readwrite) NSString *channelId;
@property (nullable, nonatomic, retain, readwrite) NSString *meetingId;
@property (nullable, nonatomic, retain, readwrite) NSString *title;
@property (nonatomic, assign, readwrite) BOOL isCanVideo;
@property (nonatomic, assign, readwrite) BOOL isScheduled;
@property (nullable, nonatomic, retain, readwrite) NSString *joinMode;
@property (nonatomic, assign, readwrite) BOOL needPassword;
@property (nonatomic, assign, readwrite) long startTime;
@property (nonatomic, assign, readwrite) long endTime;
@property (nonatomic, strong) NSArray *host;
@property (nonatomic, strong) NSArray *participant;
@property (nonatomic, assign, readwrite) long createdAt;
@property (nullable, nonatomic, retain, readwrite) NSString *createdBy;
@property (nonatomic, strong) NSArray *logs;
@property (nonatomic, assign, readwrite) BOOL locked;
@property (nonatomic, assign, readwrite) BOOL deleted;
@property (nullable, nonatomic, retain, readwrite) NSString *status;
@property (nonatomic, strong) NSArray *meetingUser;
@property (nonatomic, strong) NSArray *joinedUser;
@property (nonatomic, strong) NSArray *deletedUser;
@property (nonatomic, strong) NSArray *recording;
@end

NS_ASSUME_NONNULL_END
