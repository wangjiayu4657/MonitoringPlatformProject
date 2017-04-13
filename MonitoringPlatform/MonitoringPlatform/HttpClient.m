//
//  HttpClient.m
//  Pets
//
//  Created by dengqiang on 3/31/15.
//  Copyright (c) 2015 XuShi Technology Co.,Ltd. All rights reserved.
//

#import "HttpClient.h"
#import "AFNetworking.h"

static id sharedClient = nil;

NSString * const kDevelopmentAPIBaseURL = @"DevelopmentAPIBaseURLKey";
NSString * const kAPIBaseURLDevelopment = @"http://192.168.20.111:8080";
NSString * const kAPIBaseURLProduction  = @"http://app.m3w4.com";
NSString * const kBeauticianErrorDomain = @"com.m3w4.beautician.httperror";

@interface HttpClient ()

@end

@implementation HttpClient

+ (void)startWithBaseURL:(NSURL *)baseURL
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedClient = [[self alloc] initWithBaseURL:baseURL];
    });
}

+ (instancetype)sharedClient
{
    static dispatch_once_t oneceToken;
    dispatch_once(&oneceToken, ^{
        sharedClient = [[self alloc] initWithBaseURL:nil];
    });
    return sharedClient;
}

- (instancetype)initWithBaseURL:(NSURL *)url
{
    if (self = [super initWithBaseURL:url])
    {
        self.requestSerializer = [AFJSONRequestSerializer serializer];
        [self.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Accept"];
        self.responseSerializer = [AFJSONResponseSerializer serializer];
        self.securityPolicy = [AFSecurityPolicy policyWithPinningMode:AFSSLPinningModeNone];
    }
    return self;
}


#pragma mark - Private

- (NSURLSessionDataTask *)dataTaskWithHTTPMethod:(NSString *)method
                                       URLString:(NSString *)URLString
                                      parameters:(id)parameters
                                     resultBlock:(ResultBlock)resultBlock {
    if ([URLString hasPrefix:@"/"]) {
        URLString = [URLString substringFromIndex:1];
    }
    
    NSMutableDictionary *mutableParams = [NSMutableDictionary dictionaryWithDictionary:parameters];
    //    [mutableParams setObject:VALID_STRING([AppManager sharedManager].uuid) forKey:@"deviceId"];
    //    [mutableParams setObject:VALID_STRING([AppManager sharedManager].device) forKey:@"device"];
    //    [mutableParams setObject:VALID_STRING([AppManager sharedManager].system) forKey:@"system"];
    //    [mutableParams setObject:VALID_STRING([AppManager sharedManager].appVersion) forKey:@"appVersion"];
    //    [mutableParams setObject:@([AppManager sharedManager].latitude) forKey:@"latitude"];
    //    [mutableParams setObject:@([AppManager sharedManager].longitude) forKey:@"longitude"];
    
    //    NSLog(@"%@ %@\n%@", method, URLString, mutableParams);
    
    NSURLSessionDataTask *dataTask = [self dataTaskWithHTTPMethod:method
                                                        URLString:URLString
                                                       parameters:mutableParams
                                                          success:^(NSURLSessionDataTask *task, id responseObject) {
//          NSLog(@"Request URL: %@", [task.originalRequest.URL absoluteString]);
//          NSLog(@"Response Object:\n%@", responseObject);
//          NSLog(@"Response Headers:\n%@", ((NSHTTPURLResponse *)(task.response)).allHeaderFields);
          
          //              if ([responseObject isKindOfClass:[NSDictionary class]] == NO) {
          //                  responseObject = nil;
          //              }
          
          if (resultBlock) {
              dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),^{
                  resultBlock(responseObject, nil);
              });
          }
          
          /*
           BOOL isSuccess = [responseObject[@"success"] toBool];
           if (isSuccess) {
           if (resultBlock) {
           dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),^{
           resultBlock(responseObject, nil);
           });
           }
           } else {
           NSInteger errorCode = [responseObject[@"code"] toInt];
           NSString *errorMessage = [responseObject[@"message"] toString];
           
           NSError *error = [NSError errorWithDomain:kBeauticianErrorDomain code:errorCode userInfo:@{NSLocalizedDescriptionKey : VALID_STRING(errorMessage)}];
           if (resultBlock) {
           dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
           resultBlock(nil, error);
           });
           }
           }
           */
      }

      failure:^(NSURLSessionDataTask *task, NSError *error) {
          NSLog(@"Request Failed:\n%@", error);
          NSLog(@"Request URL:\n%@", [task.originalRequest.URL absoluteString]);
          
          NSString *errorMessage = @"网络好像不太通畅，请稍候再试哦";
    #ifdef DEBUG
          errorMessage = [NSString stringWithFormat:@"%@\nHTTP状态码%ld, 错误码%ld", errorMessage, (long)(((NSHTTPURLResponse *)(task.response)).statusCode), (long)(error.code)];
    #endif
          
          error = [NSError errorWithDomain:kBeauticianErrorDomain code:error.code userInfo:@{NSLocalizedDescriptionKey : errorMessage}];
          
          if (resultBlock) {
              dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                  resultBlock(nil, error);
              });
          }
      }];
    
    [dataTask resume];
    
    return dataTask;
}

#pragma mark - Public

- (NSURLSessionDataTask *)getPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock
{
    return [self dataTaskWithHTTPMethod:@"GET" URLString:path parameters:params resultBlock:resultBlock];
}

- (NSURLSessionDataTask *)postPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock
{
    return [self dataTaskWithHTTPMethod:@"POST" URLString:path parameters:params resultBlock:resultBlock];
}

- (NSURLSessionDataTask *)putPath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock
{
    return [self dataTaskWithHTTPMethod:@"PUT" URLString:path parameters:params resultBlock:resultBlock];
}

- (NSURLSessionDataTask *)deletePath:(NSString *)path params:(NSDictionary *)params resultBlock:(ResultBlock)resultBlock
{
    return [self dataTaskWithHTTPMethod:@"DELETE" URLString:path parameters:params resultBlock:resultBlock];
}

@end






































