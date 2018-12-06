//
//  ImproveDigitalAdView.h
//  Mobile360SDK
//


#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>
#import <AdSupport/AdSupport.h>
#import "ImproveDigitalAdViewDelegate.h"
#import "LogData.h"
#import "ImproveDigitalTypes.h"

@interface ImproveDigitalAdView : UIView <UIGestureRecognizerDelegate>

- (id)initWithCoder:(NSCoder *)aDecoder;

- (id)initWithFrame:(CGRect)frame;


/** Sets the ImproveDigitalAdViewDelegate delegate receiever for the ad view.
 
 @warning Proper reference management practices should be observed when using delegates.
 @warning Ensure that the delegate is set to nil prior to releasing the ad view's instance.
 */
@property(nonatomic, weak) id <ImproveDigitalAdViewDelegate> delegate;

///---------------------------------------------------------------------------------------
/// @name Required configuration ( except for interstital ads)
///---------------------------------------------------------------------------------------

/** Specifies the placementId for the ad network.
 */
@property(nonatomic, strong) NSString *placementId;
/** Specifies the height for the ad ONLY if needed to receive this particular ad size.
 */
@property(nonatomic, strong) NSString *adHeight;
/** Specifies the width for the ad ONLY if needed to receive this particular ad size.
 */
@property(nonatomic, strong) NSString *adWidth;

/**
    Use secure connection(https).
    By default ad requests will be made via http
 */
@property(nonatomic, assign) BOOL useSecureConnection;

/**
    Allow scrolling inside adView. Default value is NO.
 */
@property(nonatomic, assign) BOOL allowAdScrolling;

/** Returns the placement type for the instance.
 
 This is set based on how the instance was setup.
 
 @see setInterstitial:
 */
@property(nonatomic, readonly) ImproveDigitalAdViewPlacementType placementType;

///---------------------------------------------------------------------------------------
/// @name Location detection support
///---------------------------------------------------------------------------------------

/** Returns the enablement status of location detection.
 
 May return `NO` even if one of the setLocationDetectionEnabled methods was used
 to enable it.  This can happen if the device doesn't support location enablement
 or if the user has denied location permissions to the application.  Note however
 that this property should not be used to determine either of those cases for the
 application.
 */
@property(nonatomic, readonly) BOOL locationDetectionEnabled;

/** Returns the enablement status of using custom location for user tracking.
 
 By default value is 'NO', which means that sdk tracks user location and use geo-data for targeting.
 If host application wants to track user location, this property should be set to 'YES'.
 Setting this property to 'YES' sdk will stop tracking user location.
 Please, use 'setCustomLocation' method to set user's location from the host application
 
 */
@property(nonatomic, assign) BOOL useCustomLocation;

/** Specifies the log level.  All logging is via NSLog().
 
 @see [ImproveDigitalAdViewDelegate ImproveDigitalAdView:shouldLogData:ofType:]
 */
@property(nonatomic, assign) ImproveDigitalLogEvent logLevel;

/**
 Settings for MRAID_ENV object generation.
 If set on adView level, overrides SDK settings on instance level.
 */
@property (nonatomic, assign) ImproveDigitalMraidEnvironment mraidEnv;

/**
 Set user age used for ad targeting
 */
@property(nonatomic, retain) NSNumber *userAge;

/**
 Set user gender for ad targeting
 */
@property(nonatomic, assign) ImproveDigitalGender userGender;
/**
    Use this method to set custom user's location.
    If property 'useCustomLocation' isn't set to 'YES' these method will not have any effect.
 
 */
- (void)setCustomLocationWithLatitude:(double)latitude andLongitude:(double)longitude;

/**
    Set ad response to load into AdView
 */
- (void)setAdResponse:(NSData *)response;

/**
    Send ad request and load ad response into AdView
 */
- (void)loadAd;
/**
 public method for handling orientation changes
 */
//-(void) orientationChangedHandler;
//-(void)resizeAdView:(CGRect)rect;
//-(void)closeAd;

/**
 interstital initialization
 */
- (void)setInterstitial;

///---------------------------------------------------------------------------------------
/// @name Close button support
///---------------------------------------------------------------------------------------

/** Shows a close button after the specified delay after the ad is rendered.
 
 For most cases this should not be required since banner ads don't usually have a need for a close
 button and richmedia ads that expand or resize will offer their own close button.
 
 This SHOULD be used for interstitial ads that are known to not be richmedia as they
 will not have a built in close button.
 
 The setting applies for all subsequent updates.  The button can be customized using the
 ImproveDigitalAdViewCustomCloseButton: delegate method.
 
 @warning Ensure [ImproveDigitalAdView reset] is invoked when the instance will no longer be used or
 is being removed from the view stack.  This will prevent the main NSRunLoop from retaining
 the ImproveDigitalAdView instance after its intended release.
 
 @see reset
 
 @param delay The time to delay showing the close button after rendering the ad.  A
 value of 0 will show the button immediately.
 */
- (void)showCloseButtonAfterDelay:(NSTimeInterval)delay;

/** Restates the instance to its default state.
 
 -Stops updates and cancels the update interval.
 -Stops location detection.
 -Collapses any expanded or resized richmedia ads.
 -Closes interstitial.
 -Closes internal ad browser.
 
 Should be sent before releasing the instance if another object may be retaining it
 such as a superview or list.  This allows the application to suspend ad updating
 and interaction activities to allow other application activitis to occur.  After
 responding to other activities update or updateWithTimeInterval: can be sent again
 to resume ad updates.
 
 @warning If the project is using ARC (automatic reference counting) this MUST be called
 to cancel internal timers.  If not the main NSRunLoop will retain a reference to the
 ImproveDigitalAdView instance and continue invoking its timers.
 @warning Does not reset the delegate.
 */


- (void)reset;

///---------------------------------------------------------------------------------------
/// @name Controlling interstitial presentation
///---------------------------------------------------------------------------------------

/** Shows and closes the interstitial view.
 
 Can only be used if the instance was initialized with initInterstitial.
 */
- (void)showInterstitial;


/** Shows the interstitial and automatically closes after the specified duration.
 
 Can only be used if the instance was initialized with initInterstitial.
 
 @param duration The amount of time to display the interstitial before closing it.
 */
- (void)showInterstitialWithDuration:(NSTimeInterval)duration;


/** Closes the interstitial.
 
 */
- (void)closeInterstitial;

///---------------------------------------------------------------------------------------
/// @name Internal browser
///---------------------------------------------------------------------------------------
/**
    If set to 'NO', link will be opened with UIApplication's openURL
    If set to 'YES' link will be opened with internal browser
    
    Property is ignored if the iOS version is less than 9.0
    by default is set to YES
 */
@property(nonatomic, assign) BOOL useInternalBrowser;


///---------------------------------------------------------------------------------------
/// @name Animation
///---------------------------------------------------------------------------------------
/**
 This property should be set if animation should be applied
 @see  ImproveDigitalAdViewAnimationType
 
 Default value is: ImproveDigitalAdViewAnimationTypeNone
 */
@property(nonatomic, assign) ImproveDigitalAdViewAnimationType animationType;


/**
 This property defines duration of the animation
 Default value is: 1 second
 Maximum value is: 3 seconds
 
 */
@property(nonatomic, assign) double animationDuration;

@end

