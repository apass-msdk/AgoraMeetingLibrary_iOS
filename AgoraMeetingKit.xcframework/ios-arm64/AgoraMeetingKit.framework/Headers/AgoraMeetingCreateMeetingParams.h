//
//  AgoraMeetingCreateMeetingParam.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/8/15.
//

#import "AMMeetingUserInfo.h"
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 创建会议参数
 */
@interface AgoraMeetingCreateMeetingParams : NSObject

/**
 @brief  会议标题
 */
@property (nullable, nonatomic, retain, readwrite) NSString *title;

/**
 @brief  用户编号
 */
@property (nullable, nonatomic, retain, readwrite) NSString *userid;

/**
 @brief  是否允许录像
 */
@property (nonatomic, assign, readwrite) BOOL allowRecording;

/**
 @brief  默认用户进入会议时，摄像头的状态
 */
@property (nonatomic, assign, readwrite) BOOL isCanVideo;

/**
 @brief  是否是计划会议，默认否; 对非计划会议，默认开始时间为创建时间，结束时间为24小时后
 */
@property (nonatomic, assign, readwrite) BOOL isScheduled;

/**
 @brief  'any': 任何人可入会； 'strict': 非参会人员入会，需主持人同意； 'reject':拒绝非参会人员
 */
@property (nullable, nonatomic, retain, readwrite) NSString *joinMode;

/**
 @brief  是否需要会议密码,默认否
 */
@property (nonatomic, assign, readwrite) BOOL needPassword;

/**
 @brief  开始时间, 非计划会议时间为创建时间
 */
@property (nonatomic, assign, readwrite) long startTime;

/**
 @brief  结束时间，非计划会议，创建时间+24小时
 */
@property (nonatomic, assign, readwrite) long endTime;

/**
 @brief  主持人
 */
@property (nonatomic, strong) NSMutableArray *host;

/**
 @brief  参会人
 */
@property (nonatomic, strong) NSMutableArray *participant;

/**
 @brief  备选主持人
 */
@property (nonatomic, strong) NSMutableArray *alternativeHost;

/**
 @brief  入会时静音，默认否
 */
@property (nonatomic, assign, readwrite) BOOL mutedDefault;

/**
 @brief 会议密码，不传时将生成6位随机数字密码
 */
@property (nullable, nonatomic, retain, readwrite) NSString *password;

/**
 @brief  会议类型 1:普通会议 2:个人会议 默认为普通会议
 */
@property (nonatomic, assign, readwrite) int type;

/**
 @brief 自定义频道ID 不传，系统默认创建一个9位数字的频道ID， 加入会议使用频道ID
 */
@property (nullable, nonatomic, retain, readwrite) NSString *channelId;

/**
 @brief 添加主持人
 @param host 主持人
 */
- (void)addHost:(AMMeetingUserInfo *)host;

/**
 @brief 添加备选主持人
 @param alternativeHost 备选主持人
 */
- (void)addAlternativeHost:(AMMeetingUserInfo *)alternativeHost;

/**
 @brief 添加参会人
 @param participant 参会人
 */
- (void)addParticipant:(AMMeetingUserInfo *)participant;

/**
 @brief 得到主持人
 */
- (NSArray *)getHost;

/**
 @brief 得到备选主持人
 */
- (NSArray *)getAlternativeHost;

/**
 @brief 得到参会人
 */
- (NSArray *)getParticipant;

@end

NS_ASSUME_NONNULL_END
