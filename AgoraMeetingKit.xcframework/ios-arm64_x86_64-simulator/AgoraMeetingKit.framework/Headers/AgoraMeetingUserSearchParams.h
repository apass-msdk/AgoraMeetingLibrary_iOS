//
//  AgoraMeetingUserSearchParams.h
//  AgoraMeetingKit
//
//  Created by 蔡泽华 on 2022/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AgoraMeetingUserSearchParams : NSObject
/**
 @brief 页码
 */
@property (nonatomic, assign, readwrite) int pageNum;

/**
 @brief 搜索内容
 */
@property (nullable, nonatomic, retain, readwrite) NSString *searchText;

/**
@brief 每页数量
 */
@property (nonatomic, assign, readwrite) int pageSize;
@end

NS_ASSUME_NONNULL_END
