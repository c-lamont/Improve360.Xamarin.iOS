//
//  Mobile360SDK.h
//  Mobile360SDK
//
//  Created by Zeljko Turbic on 9/14/15.
//  Copyright (c) 2015 Levi9. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ImproveDigitalAd.
FOUNDATION_EXPORT double ImproveDigitalAdVersionNumber;

//! Project version string for ImproveDigitalAd.
FOUNDATION_EXPORT const unsigned char ImproveDigitalAdVersionString[];

#import <Mobile360SDK/ImproveDigitalAdViewDelegate.h>
#import <Mobile360SDK/ImproveDigitalAdView.h>
#import <Mobile360SDK/ImproveDigitalModalViewController.h>
#import <Mobile360SDK/LogData.h>
#import <Mobile360SDK/ImproveDigitalVideoDelegate.h>
#import <Mobile360SDK/ImproveDigitalVideoPlayer.h>
#import <Mobile360SDK/PlayerLayout.h>
#import <Mobile360SDK/Reachability.h>

@interface Mobile360SDK : NSObject
/**
 Settings for MRAID_ENV object generation
 */
@property (class, nonatomic, assign) ImproveDigitalMraidEnvironment mraidEnv;

+ (void)forCountry:(NSString *)value;

+ (NSString *)hostApplicationId;
+ (NSString *)sdkVersion;
+ (NSString *)sdkName;
+ (NSString *)mraidVersion;

@end
