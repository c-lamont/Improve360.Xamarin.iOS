//
//  ImproveDigitalMediationBase.h
//  Mobile360SDK
//
//  Created by Zolt Varga on 8/18/17.
//  Copyright © 2017 Levi9. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImproveDigitalMediationBaseDelegate.h"
#import "ImproveDigitalMediationData.h"
#import "ImproveDigitalMRAIDLogger.h"
#import "ImproveDigitalMediationTargetingParameters.h"

@class ImproveDigitalAdView;

static NSString * const kImproveDigitalMediaTypeHtml = @"html";
static NSString * const kImproveDigitalMediaTypeImage = @"image";
static NSString * const kImproveDigitalMediaTypeJavascript = @"javascript";

@protocol ImproveDigitalMediationAdapterBase <NSObject>
/**
 Prepare SDK-less request for specific mediator
 @param data - list of mediation parameters
 */
-(void)requestAdWithData:(ImproveDigitalMediationData *)data;

/**
 Request the Ad from a 3rd party API Adapter with an URL
 @param urlName - String value of the Endpoint URL, At this point the API Adapter should prepare the Endpoint with the required parameters.
 */
- (void)requestAdWithURL:(NSString *)urlName;

/**
 Parsing parameters from mediation
 Comma separated key - value objects
 @param params - array of parameters in string
 */
-(NSMutableDictionary *)parseParams:(NSString *)params;

/**
 Expose the readonly view from ImproveDigitalMediationData class
 */
-(void)setAdView:(id)view;

/**
 Expose the readonly content from ImproveDigitalMediationData class
 */
-(void)setAdContent:(NSData *)content;

@optional
-(NSData *)parseMediatedResponse:(NSDictionary *)data;
@end


@interface ImproveDigitalMediationBase : NSObject <ImproveDigitalMediationAdapterBase>

@property (nonatomic, weak) id<ImproveDigitalMediationBaseDelegate> delegate;
@property (nonatomic, weak) id<ImproveDigitalMRAIDLoggerDelegate> logger;

/**
 Additional request parameters, targeting parameters
 */
@property(nonatomic, strong, readonly) ImproveDigitalMediationTargetingParameters *targetingParameters;

/**
 Request Ad based on mediation response parameters
 @param data - mediation data
 @param targetingParameters - contain targeting parameters
 */
-(void)executeMediationAdapterWithData:(ImproveDigitalMediationData *)data andTargetingParameters:(ImproveDigitalMediationTargetingParameters *)targetingParameters;

@end
