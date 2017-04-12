//
//  HttpClient.h
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import "AFHTTPSessionManager.h"

typedef void (^ResultBlock)(id responseObject, NSError *error);

@interface HttpClient : AFHTTPSessionManager

+ (void)startWithBaseURL:(NSURL *)baseURL;
+ (instancetype)sharedClient;

- (NSURLSessionDataTask *)getPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock;

- (NSURLSessionDataTask *)postPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock;

- (NSURLSessionDataTask *)putPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock;

- (NSURLSessionDataTask *)deletePath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock;

@end
