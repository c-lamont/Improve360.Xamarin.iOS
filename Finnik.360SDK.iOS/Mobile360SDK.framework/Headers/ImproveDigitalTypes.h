//
//  ImproveDigitalTypes.h
//  Mobile360SDK
//
//  Created by Vladimir Pavlovic on 11/20/17.
//  Copyright © 2017 Levi9. All rights reserved.
//

#ifndef ImproveDigitalTypes_h
#define ImproveDigitalTypes_h

typedef enum {
    /// Ad is placed in application content.
    ImproveDigitalAdViewPlacementTypeInline = 0,
    
    /// Ad is placed over and in the way of application content.
    /// Generally used to place an ad between transtions in an application
    /// and consumes the entire screen.
    ImproveDigitalAdViewPlacementTypeInterstitial
    
} ImproveDigitalAdViewPlacementType;

typedef NS_ENUM(NSInteger, ImproveDigitalError) {
    ImproveDigitalNoError = 0,
    ImproveDigitalRequestError = 100, //Ad request error ocurred
    ImproveDigitalNoFill = 200, //No ad to show
    ImproveDigitalResponseError = 300, //Something is wrong with response
    ImproveDigitalContentLoadError = 400, //Error ocurred while loading ad content in webview
};

typedef enum {
    ImproveDigitalAdViewAnimationTypeNone = 0,
    ImproveDigitalAdViewAnimationTypeFromLeft,
    ImproveDigitalAdViewAnimationTypeFromRight,
    ImproveDigitalAdViewAnimationTypeFromBottom,
    ImproveDigitalAdViewAnimationTypeFromTop,
    ImproveDigitalAdViewAnimationTypeFadeIn
    
} ImproveDigitalAdViewAnimationType;

typedef NS_ENUM(NSInteger, ImproveDigitalGender) {
    ImproveDigitalGenderNone = 0,
    ImproveDigitalGenderMale,
    ImproveDigitalGenderFemale
};

typedef struct {
    BOOL fillOptionalValues;
    BOOL targetContentForChildren;
} ImproveDigitalMraidEnvironment;

ImproveDigitalMraidEnvironment ImproveDigitalMraidEnvironmentMake(BOOL fillOptionalValues, BOOL targetContentForChildren);

#endif /* ImproveDigitalTypes_h */
