//
//  LogData.h
//  Mobile360SDK
//
//  Created by Ognjen Manevski on 4/7/16.
//  Copyright © 2016 Levi9. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef LogDataTypes
#define LogDataTypes

/** Event log types.
 */
typedef NS_ENUM(NSUInteger, ImproveDigitalLogEvent) {
    ImproveDigitalLogEventNone = 0,
    ImproveDigitalLogEventError = 1,
    ImproveDigitalLogEventInfo = 2
};
#endif


@interface LogData : NSObject

/**
 Specifies one of the predefined types of logging levels
 */
@property(nonatomic, assign) ImproveDigitalLogEvent logType;
/** 
 Specifies the message to be shown in log
 */
@property(nonatomic, copy) NSString *message;
/** 
 Specifies the function in which error occured
 */
@property(nonatomic, assign) const char *func;
/** 
 Specifies the line number in function where error occured
 */
@property(nonatomic, assign) int line;
/** 
 Specifies the error which will be logged out
 */
@property(nonatomic, strong) NSError *error;
/**
 Specifies the time of event occurrences
 */
@property(nonatomic, readonly) NSDate *date;

/**
 Method returns the string associated with certain log type
 */
- (NSString *)getLogTypeString;

/**
 Method initializes instance of LogData class.
 @param logType - Type of logging level
 @param message - Message to be shown in log
 @param err - Error which will be logged out
 @param func - Function in which error occured
 @param line - Line number in function where error occured
 */
- (id)initWithLogType:(ImproveDigitalLogEvent)logType message:(NSString *)message
                error:(NSError *)err function:(const char *)func andLine:(int)line;

-(NSString *)description;
@end
