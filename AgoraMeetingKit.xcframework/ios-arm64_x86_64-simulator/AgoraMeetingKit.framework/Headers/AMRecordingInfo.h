//
//  AMRecordingInfo.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AMRecordingInfo : NSObject
@property (nonatomic, assign, readwrite) long startTime;
@property (nullable, nonatomic, retain, readwrite) NSString *status;
@property (nullable, nonatomic, retain, readwrite) NSString *userid;
@end

NS_ASSUME_NONNULL_END
