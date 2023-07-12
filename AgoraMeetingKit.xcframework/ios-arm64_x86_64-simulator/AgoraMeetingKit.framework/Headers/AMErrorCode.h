//
//  AMErrorCode.h
//  AgoraMeetingKit
//
//  Created by caizehua on 2022/7/11.
//

#ifndef AMErrorCode_h
#define AMErrorCode_h
typedef enum {
    
    /**
     @brief 成功
     */
    AMErrorCode_SUCCESS = 0,
    
    /**
     @brief 没有用户权限
     */
    AMErrorCode_ERROR_USER_PERMISSION = -3,
    
    /**
     @brief 没有主持人权限
     */
    AMErrorCode_ERROR_HOST_PERMISSION =-4,
    
  
    
    /**
     @brief 当前权限没有进行设备授权
     */
    AMErrorCode_StatusNotDetermined= -6,
    
    /**
     @brief 当前权限被设备拒绝
     */
    AMErrorCode_StatusDenied= -7,
    
    /**
     * @brief 当前分享人没有权限结束分享
     */
    AMErrorCode_SHARE_USER_PERMISSION= -10,
    
    /**
     * @brief 错误的设置时间
     */
    AMErrorCode_SETTING_TIME = -12,
    
    /**
     * @brief 正在加入会议
     */
    AMErrorCode_MEETING_JOINING  = -13,
    

    /**
     * @brief 想要结束的结束分享不存在
     */
    AMErrorCode_SHARE_NOT_EXIST = -9,
    

    /**
     * @brief 分享已经存在
     */
    AMErrorCode_SHARE_EXIST = -8,
    
    /**
     * @brief 摄像头正在启动中
     */
    AMErrorCode_CAMERA_STARTING= -11,


    /**
     @brief SOCKET未连接
     */
    AMErrorCode_ERROR_SOCKET_NOT_CONNECT =10,
    
    
    /**
     @brief 网络错误
     */
    AMErrorCode_BAD_NETWORK = 404,
    
    /**
     @brief 会议已经存在
     */
    AMErrorCode_MEETING_EXIST = 3008,
    
    /**
     @brief 会议正在被分享
     */
    AMErrorCode_SCREEN_SHARING = 3015,
    
    /**
     @brief sdk已经被初始化
     */
    AMErrorCode_ERROR_ALREADY_INIT = 2,
    
    /**
     @brief sdk已经被登录
     */
    AMErrorCode_ERROR_ALREADY_LOGIN = 3,
    
    /**
     @brief sdk参数不能为空
     */
    AMErrorCode_ERROR_PARAM_EMPTY = 4,
    
    /**
     @brief sdk没有被初始化
     */
    AMErrorCode_ERROR_NONE_INIT = 5,
    
    /**
     @brief 账号已经被登录在别的设备
     */
    AMErrorCode_ERROR_NET_ALREADY_LOGIN = 10005,
    
    /**
     @brief 会议已经被锁定
     */
    AMErrorCode_MEETING_LOCKED =  3026,
    
    /**
     @brief 会议已经被结束
     */
    AMErrorCode_MEETING_FINISHED =  20007,
    
    AMErrorCode_MEETING_SHARING_TIMEOUT =  3016
    
} AMErrorCode;

#endif /* AMErrorCode_h */
