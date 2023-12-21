//
//  AMChatMessageInfo.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/10/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, AgoraMeetingChatMessageState) {
    AgoraMeetingChatMessageStateSending = 3,
    AgoraMeetingChatMessageStateSuccess = 1,
    AgoraMeetingChatMessageStateFail = 2,
};
@interface AMChatMessageInfo : NSObject
@property (nullable, nonatomic, retain, readwrite) NSString *userid;
@property (nullable, nonatomic, retain, readwrite) NSString *msgId;
@property (nullable, nonatomic, retain, readwrite) NSString *nickname;
@property (nullable, nonatomic, retain, readwrite) NSString *avatar;
@property (nullable, nonatomic, retain, readwrite) NSString *type;
@property (nullable, nonatomic, retain, readwrite) NSString *localId;
@property (nullable, nonatomic, retain, readwrite) NSString *content;
@property (nonatomic, assign, readwrite) AgoraMeetingChatMessageState state;
@property (nonatomic, assign, readwrite) long cts;
@end

NS_ASSUME_NONNULL_END
