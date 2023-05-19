//
//  AMInMeetingService.h
//  AgoraMeetingKit
//
//  Created by tx on 2022/7/10.
//

#import <Foundation/Foundation.h>
#import "AgoraMeetingJoinMeetingParams.h"
#import <AgoraRtcKit/AgoraRtcEngineKit.h>
#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView AM_VIEW_CLASS;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView AM_VIEW_CLASS;
#endif
#import "InMeetingUserInfo.h"
#import "AMErrorCode.h"
#import "InMeetingAudioController.h"
#import "InMeetingVideoController.h"
#import "InMeetingOTDataController.h"
#import "InMeetingShareController.h"
#import "InMeetingChatController.h"
#import "IInMeetingRecordingController.h"
NS_ASSUME_NONNULL_BEGIN

/**
 @brief 会中的的事件
 */
@protocol AgoraMeetingInMeetingDelegate <NSObject>
@optional
 
/**
 @brief 用户连接会议成功
 */
-(void) onMeetingConnectSuccess;
 
/**
 @brief 用户连接会议失败
 */
-(void) onMeetingConnectFailure;

/**
 @brief 其他用户加入会议
 @param uid  用户编号
 */
-(void) onMeetingUserJoin:(NSString*)uid;

/**
 @brief 当前用户加入会议
 @param uid  用户编号
 */
-(void) onMeetingMySelfJoin:(NSString*)uid;

/**
 @brief 其他用户离开会议
 @param uid  用户编号
 */
-(void) onMeetingOtherUserLeave:(NSString*)uid;
 
/**
 @brief 单个用户数据加载，当用户加入时会触发
 @param uid  用户编号
 */
-(void) onMeetingUserLoadData:(NSString*)uid;


/**
  @param uid 用户编号
  @brief 单个用户数据移除，当用户加入离开时会触发
 */
-(void) onMeetingUserRemoveData:(NSString*)uid;



/**
 @brief 用户的麦克风状态改变
 @param uid  用户编号
 @param value  on:打开 off:关闭
 @param reason 原因
 */
-(void) onMeetingUserMicrophoneChange:(NSString*)uid setValue:(NSString *)value reason:(NSString*)reason;;

/**
 @brief 用户的摄像头状态改变
 @param uid  用户编号
 @param value  on:打开 off:关闭
 @param reason 原因
 */
-(void) onMeetingUserCameraChange:(NSString*)uid setValue:(NSString *)value reason:(NSString*)reason;;

/**
 @brief 用户的扩展字改变
 @param uid  用户编号
 @param value  字符串
 */
-(void) onMeetingUserReservedChange:(NSString*)uid setValue:(NSString *)value;


/**
 @brief 用户的昵称改变
 @param uid  用户编号
 @param value  on:打开 off:关闭
 @param reason 原因
 */
-(void) onMeetingUserNickNameChange:(NSString*)uid setValue:(NSString *)value reason:(NSString*)reason;

/**
 @brief 用户的头像改变
 @param uid  用户编号
 @param value  具体值
 @param reason 原因
 */
-(void) onMeetingUserAvatarChange:(NSString*)uid setValue:(NSString *)value reason:(NSString*)reason;

/**
 @brief 用户举手状态改变
 @param uid  用户编号
 @param value  on:举起 off:放下
 */
-(void) onMeetingUserRaiseHandChange:(NSString*)uid setValue:(NSString *)value;
 
/**
 @brief 是否允许用户打开麦克风的权限被修改
 @param value  on:允许 off:不允许
 */
-(void) onMeetingPermissionCameraChange:(NSString*)value;
 
/**
 @brief 是否允许用户打开麦克风的权限被修改
 @param value  on:允许 off:不允许
 */
-(void) onMeetingPermissionMicrophoneChange:(NSString*)value;
 
/**
 @brief 入会时静音权限被修改
 @param value  on:允许 off:不允许
 */
-(void) onMeetingPermissionMuteAttendeesUponEntryChange:(NSString*)value;


/**
 @brief 是否允许用户举手的权限被修改
 @param value  on:允许 off:不允许
 */
-(void) onMeetingPermissionRaiseHandChange:(NSString*)value;

/**
 @brief 锁定会议发生变化
 @param value    on:锁定 off:解除
 */
-(void) onMeetingLockMeetingChange:(NSString*)value;
 
/**
 @brief 是否允许用户修改昵称的权限被修改
 @param value  on:允许 off:不允许
 */
-(void) onMeetingPermissionNickNameChange:(NSString*)value;

/**
 @brief 请求用户使用询问权限的方式打开摄像头
 */
-(void) onAskPermissionOpenCamera:(AMErrorCode)errorCode;
 
/**
 @brief 请求用户使用询问权限的方式打开摄像头
 */
-(void) onAskPermissionOpenMicrophone:(AMErrorCode)errorCode;

/**
 @brief 要求用户打开摄像头
 */
-(void) onAskOpenCamera;
 
/**
 @brief 要求用户打开麦克风
 */
-(void) onAskOpenMicrophone;
 
/**
 @brief 用户申请打开摄像头的请求
 @param uid  用户编号
 */
-(void) onMeetingAddCameraRequest:(NSString*)uid;;
 
/**
 @brief 用户申请打开麦克风的请求
 @param uid  用户编号
 */
-(void) onMeetingAddMicrophoneRequest:(NSString*)uid;;

/**
 @brief 用户申请打开麦克风的请求被处理
 @param uid  用户编号
 */
-(void) onMeetingDeleteMicrophoneRequest:(NSString*)uid;;

/**
 @brief 用户申请打开摄像头的请求被处理
 @param uid  用户编号
 */
-(void) onMeetingDeleteCameraRequest:(NSString*)uid;;

/**
 @brief 主持人处理申请打开摄像头的请求的结果
 @param value    on:通过 off:拒绝
 */
-(void) onApplyOpenCameraResult:(NSString*)value;
 
/**
 @brief 主持人处理申请打开麦克风的请求的结果
 @param value    on:通过 off:拒绝
 */
-(void) onApplyOpenMicrophoneResult:(NSString*)value;
 
/**
 @brief 丢失连接
 */
-(void) onLostConnect;
 
/**
 @brief 重新连接
 */
-(void) onReConnect;
 
/**
 @brief 重新连接后，重新加载的数据
 */
-(void) onReLoadData;

/**
 @brief 添加连席主持人
 @param uid  用户编号
 @param reason  改变的原因
 */
-(void) onMeetingAddCoHost:(NSString*)uid reason:(NSDictionary*)reason;

/**
 @brief 移除连席主持人
 @param uid  用户编号
 @param reason  改变的原因
 */
-(void) onMeetingRemoveCoHost:(NSString*)uid reason:(NSDictionary*)reason;

/**
 @brief 主持人发生了变化
 @param beforeUid  之前的支持人编号
 @param currentUid  当前的主持人编号
 @param reason  改变的原因
 */
-(void) onMeetingActingHostChange:(NSString*)beforeUid currentUid:(NSString*)currentUid reason:(NSDictionary*)reason;
 
/**
 @brief 当前用户被强制离开会议
 */
-(void) onMeetingForceLeave;

/**
 @brief 当前会议结束
 */
-(void) onMeetingEnd;

/**
 @brief 收到主持人发出的全体静音消息
 */
-(void)onMeetingMuteAll;

/**
 @brief 收到主持人发出的解除全体静音消息
 */
-(void)onMeetingUnMuteAll;

///**
// * @brief 获取远端的视频流
// */
//- (void)onUserVideoFrame:(AgoraOutputVideoFrame *)videoFrame uid:(NSString*)uid;
//
///**
// @brief 获取用户自己的视频流
// */
//-(void)onMySelfVideoFrame:(AgoraOutputVideoFrame *)videoFrame;

/**
 * @param uid 用户编号
 * @param txQuality 该用户的上行网络质量，基于发送码率、上行丢包率、平均往返时延和网络抖动计算。 该值代表当前的上行网络质量，帮助判断是否可以支持当前设置的视频编码属性。
 * @param rxQuality 该用户的下行网络质量，基于下行网络的丢包率、平均往返延时和网络抖动计算。
 * @brief 通话中每个用户的网络上下行 last mile 质量报告回调
 */
-(void)onNetworkQuality:(NSString*) uid  txQuality:(AgoraNetworkQuality)txQuality rxQuality:(AgoraNetworkQuality) rxQuality;

/**
 *@param code 原因 -1，404，尝试重试，其他非0，结束会议
 * @param joinMeetingParams 上个会议的参数
 * @brief 当前用户因为网络原因离开会议
 */
-(void)onMeetingLeaveByNetwork:(NSInteger)code joinMeetingParams:(AgoraMeetingJoinMeetingParams*)joinMeetingParams;
 

/**
@brief 是用户的额外会议的权限被修改
@param value  on:允许 off:不允许
*/
-(void) onMeetingExtattrPermissionChange:(NSString*)key value:(NSString*)value beforeValue:(NSString*)beforeValue;

/**
 @brief rtc发生错误
 @param errorCode   错误类型
 */
-(void)onRTCdidOccurError:(AgoraErrorCode)errorCode;

/**
 @brief rtc连接超时
 */
-(void)onJoinChannelTimeout;

/**
 @brief 视频订阅状态发生改变回调
 @param oldState 1: 订阅失败。 2: 正在订阅。 3: 收到了远端流，订阅成功。
 @param newState 1: 订阅失败。 2: 正在订阅。 3: 收到了远端流，订阅成功。
 */
-(void)onDidVideoSubscribeStateChang:(NSString*)uid oldState:(AgoraStreamSubscribeState)oldState newState:(AgoraStreamSubscribeState)newState;


/**
 @brief rtc第一帧的解码
 */
-(void)onFirstVideoDecoded:(NSString*) uid;

/**
 @brief rtc共享第一帧的解码
 */
-(void)onShareFirstVideoDecoded:(NSString*) uid;


@end

/**
 @brief 会中的服务
 */
@interface AMInMeetingService : NSObject

/**
 @brief 会中的服务的事件回调
 */
@property (weak, nonatomic) id<AgoraMeetingInMeetingDelegate> delegate;

/**
 @brief 把视图和用户ID进行绑定，用以播放视频
 @param view 视图
 @param uid 用户ID
 */
- (int) bindView:(AM_VIEW_CLASS*)view withUid:(NSString*)uid;

/**
 @brief 把视图和用户ID进行绑定，用以播放视频
 @param view 视图
 @param uid 用户ID
 @param renderMode RENDER_MODE_HIDDEN (1)：优先保证视窗被填满。视频尺寸等比缩放，直至整个视窗被视频填满。如果视频长宽与显示窗口不同，多出的视频将被截掉。
 RENDER_MODE_FIT (2)：优先保证视频内容全部显示。视频尺寸等比缩放，直至视频窗口的一边与视窗边框对齐。如果视频长宽与显示窗口不同，视窗上未被填满的区域将被涂黑
 @param mirrorMode
 AgoraVideoMirrorModeAuto
 0:（默认）由 SDK 决定镜像模式。
 AgoraVideoMirrorModeEnabled
 1: 启用镜像模式。
 AgoraVideoMirrorModeDisabled
 2: 关闭镜像模式。
 */
- (int) bindView:(AM_VIEW_CLASS*)view withUid:(NSString*)uid withRenderMode:(AgoraVideoRenderMode)renderMode
   withMirrorMode:(AgoraVideoMirrorMode)mirrorMode;

/**
 @brief 把视图和用户ID进行解绑
 @param view 视图
 */
- (int)removeView:(AM_VIEW_CLASS*)view;

/**
 @brief 连接会议
 */
- (void) connect;

/**
 @brief 获取会中的音频控制器
 @return 音频控制器
 */
-(InMeetingAudioController*) getInMeetingAudioController;

/**
 @brief 获取会中的视频控制器
 @return 视频控制器
 */
-(InMeetingVideoController*) getInMeetingVideoController;

/**
 @brief 取会中的OT数据控制器
 @return OT数据控制器
 */
-(InMeetingOTDataController*) getInMeetingOTDataController;

/**
 @brief 取会中的云录制控制器
 @return 云录制控制器
 */
-(IInMeetingRecordingController*) getInMeetingRecordingController;

/**
 @brief 取会中的聊天控制器
 @return 聊天控制器
 */
-(InMeetingChatController*) getInMeetingChatController;

/**
 @brief 取会中的分享控制器
 @return 分享控制器
 */
-(InMeetingShareController*) getInMeetingShareController;
//
//-(InMeetingChatController*) getInMeetingChatController;



/**
 @brief 全体静音
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)muteAll;

/**
 @brief 取消全体静音
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)unMuteAll;

/**
 @brief 根据ID获取用户数据
 @param uid 用户ID
 @return 用户数据
 */
-(InMeetingUserInfo*)getUserInfoById:(NSString*)uid;
 
/**
 @brief 根据ID获取用户数据
 @param agoraUserId 用户AgoraID
 @return 用户数据
 */
-(InMeetingUserInfo*)getUserInfoByAgoraUserId:(NSInteger)agoraUserId;
/**
 @brief 得到当前的在线用户个数
 @return 用户个数
 */
-(NSUInteger)getInMeetingUserCount;
    
/**
 @brief 得到当前的在线用户编号
 @return 用户编号数组
 */
-(NSArray*)getInMeetingUserList;

/**
 @brief 强制踢人
 @param uid 用户ID
 @param isBlack 是否拉黑用户
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)forceLeaveUser:(NSString*)uid isBlack:(BOOL)isBlack;

/**
 @brief 得到会议编号
 @return 会议编号
 */
-(NSString*)getCurrentMeetingId;

/**
 @brief 得到会议频道号
 @return 会议频道号
 */
-(NSString*)getCurrentChannelId;
 
/**
 @brief 得到用户编号
 @return 用户编号
 */
-(NSString*)getMyUserID;
   
/**
 @brief 允许普通用户修改昵称
 @return 是/否
 */
-(BOOL)allowChangeName;

/**
 @brief 设置允许普通用户修改昵称
 @param allow  是/否
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setAllowChangeName:(BOOL)allow;

/**
 @brief 当前会议是否锁定
 */
-(BOOL)isLockMeeting;

/**
 @brief 设置是否锁定会议
 @param locked    锁定/解锁
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setLockMeeting:(BOOL)locked;
 
/**
 @brief 允许普通用户举手
 @return 是/否
 */
-(BOOL) allowRaiseHand;

/**
 @brief 设置允许普通用户举手
 @param allow    是/否
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode) setAllowRaiseHand:(BOOL)allow;

/**
 @brief 允许普通用户使用摄像机
 @return 是/否
 */
-(BOOL) allowCamera;

/**
 @brief 设置允许普通用户使用摄像机
 @param allow    是/否
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode) setAllowCamera:(BOOL)allow;
 
/**
 @brief 允许普通用户使用麦克风
 @return 是/否
 */
-(BOOL) allowMicrophone;

/**
 @brief 设置允许普通用户使用麦克风
 @param allow    是/否
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode) setAllowMicrophone:(BOOL)allow;

/**
 @brief 用户入会时是否静音
 @return YES:静音 NO：不静音
 */
-(BOOL) isMuteAttendeesUponEntry;

/**
 @brief 设置允许普通用户屏幕共享
 @param mute    YES:静音 NO：不静音
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode) setMuteAttendeesUponEntry:(BOOL)mute;

/**
 @brief 当前会议的标题
 */
-(NSString*)getMeetingTitle;
 
/**
 @brief 得到当前联席主持人列表
 */
-(NSArray*)getInMeetingCoHostList;
     
/**
 @brief 申请打开摄像头
 */
-(void)applyOpenCamera;

/**
 @brief 申请打开麦克风
 */
-(void)applyOpenMicrophone;

/**
 @brief 撤回打开摄像头申请
 */
-(void)recallOpenCamera;

/**
 @brief 撤回打开麦克风申请
 */
-(void)recallOpenMicrophone;
 
/**
 @brief  是否已经申请打开摄像头
 */
-(BOOL)isApplyOpenCamera;

/**
 @brief 是否已经申请打开麦克风
 */
-(BOOL)isApplyOpenMicrophone;

/**
 @brief 得到申请打开麦克风用户的列表
 @return 申请打开麦克风用户的列表
 */
-(NSArray*)getApplyOpenMicrophoneList;

/**
 @brief 得到申请打开摄像头用户的列表
 @return 申请打开摄像头用户的列表
 */
-(NSArray*)getApplyOpenCameraList;
   
/**
 @brief 主持人同意打开摄像头
 @param uid 用户编号
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)agreeApplyOpenCamera:(NSString*)uid;
    
/**
 @brief 主持人同意打开麦克风
 @param uid 用户编号
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)agreeApplyOpenMicrophone:(NSString*)uid;
    
/**
 @brief 主持人拒绝打开麦克风
 @param uid 用户编号
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)refuseApplyOpenMicrophone:(NSString*)uid;
    
/**
 @brief 主持人拒绝打开摄像头
 @param uid 用户编号
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)refuseApplyOpenCamera:(NSString*)uid;
    
/**
 @brief 得到当前用户的信息
 @return 用户的信息
 */
-(InMeetingUserInfo*)getCurrentUserInfo;

/**
 @brief 举手
 @param isRaise    举起/放下
 @return 0:表示操作通过，-3:表示用户无权限
 */
-(AMErrorCode)raiseHand:(BOOL)isRaise;

/**
 @brief  用户修改自己的扩展字段
 @param reserved    扩展字段
 */
-(void)changeReserved:(NSString*)reserved;

/**
 @brief 用户修改自己的昵称
 @param nickName    昵称
 @return 0:表示操作通过，-3:表示用户无权限
 */
-(AMErrorCode)changeNickName:(NSString*)nickName;

/**
 @brief 用户修改自己的像
 @param avatar    头像
 @return 0:表示操作通过，-3:表示用户无权限
 */
-(AMErrorCode)changeAvatar:(NSString*)avatar;

/**
 @brief 主持人修改用户昵称
 @param nickName    昵称
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)changeNickNameByHost:(NSString*)nickName setUid:(NSString*)uid;

/**
 @brief 主持人放下用户举手
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)offRaiseHandByHost:(NSString*)uid;
     
/**
 @brief 主持人操作用户麦克风
 @param uid    用户iD
 @param isOpen    是否打开
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setOpenMicrophoneByHost:(NSString*)uid setOpen:(BOOL)isOpen;

/**
 @brief 主持人操作用户摄像头
 @param uid    用户iD
 @param isOpen    是否打开
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setOpenCameraByHost:(NSString*)uid setOpen:(BOOL)isOpen;

/**
 @brief 设置主持人
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setActingHostByHost:(NSString*)uid;

/**
 @brief 原始主持人撤回主持人权限
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非原始主持人无权限
 */
-(AMErrorCode)unActingHostByHost:(NSString*)uid;

/**
 @brief 设置联席主持人
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setCoHostByHost:(NSString*)uid;

/**
 @brief 撤回联席主持人
 @param uid    用户iD
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)unCoHostByHost:(NSString*)uid;

/**
 @brief 是否是主持人
 */
-(BOOL)isHost;

/**
 @brief 是否是主持人
 */
-(BOOL)isActingHost;

/**
 @brief 是否是联席主持人
 */
-(BOOL)isCoHost;

/**
 @brief 是否是原始主持人
 */
-(BOOL)isOriginHost;
  
/**
 @brief 清除会议
 */
-(void)cleanMeeting;

 

/**
 @brief 设置会议的额外值
 @param key 关键字
 @param value 值
 @return 0:表示操作通过，-4:表示非主持人无权限
 */
-(AMErrorCode)setMeetingExtattrInfoValue:(NSString*)key value:(NSString*) value;

/**
 @brief 得到会议的额外值
 @param key 关键字
 @return on | off 开启、关闭
 */
-(NSString*)getValueFromMeetingExtattrInfo:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
