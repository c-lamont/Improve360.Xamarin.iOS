//
//  ImproveDigitalAdViewDelegate.h
//  Mobile360SDK
//
//  Created by Zeljko Turbic on 2/10/16.
//  Copyright © 2016 Levi9. All rights reserved.
//

#ifndef ImproveDigitalAdViewDelegate_h
#define ImproveDigitalAdViewDelegate_h

#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>
#import "LogData.h"

@class ImproveDigitalAdView;


/** Protocol for interaction with the ImproveDigitalAdView.
 
 The entire protocol is optional.  Some messages override default behavior and some are required
 to get full support for MRAID 2 ad content (saving calendar entries or pictures).
 
 All messages are guaranteed to occur on the main thread.  If any long running tasks are needed
 in reponse to any of the sent messages then they should be executed in a background thread to
 prevent and UI delays for the user.
 */




@protocol ImproveDigitalAdViewDelegate <NSObject>
@optional

- (UIViewController *)improveDigitalAdViewPresentationController:(ImproveDigitalAdView *)adView;

/** Sent when the close button is pressed by the user.
 
 This only occurs for the close button enabled with setCloseButton:afterDelay: or in the case of a
 interstitial richmedia ad that closes itself.  It will not be sent for richmedia close buttons that
 collapse expanded or resized ads.
 
 The common use case is for interstitial ads so the developer will know when to call closeInterstitial.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewCloseButtonPressed:(ImproveDigitalAdView *)adView;


/** Implement to return a custom close button.
 
 This button will be used for richmedia ads if the richmedia ad does not indicate it has its own
 custom close button.  It is also used if showCloseButton:afterDelay: enables the close button.
 
 @warning Do not return the same UIButton instance to different adView instances.
 
 @warning Developers should take care of adding action handlers to the button as it will
 be reused and may persist beyond the handlers lifetime.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return UIButton instance.
 */
- (UIButton *)improveDigitalAdViewCustomCloseButton:(ImproveDigitalAdView *)adView;

/** Sent when the ad will navigate to a clicked link.
 
 Not implementing this method behaves as if `YES` was returned.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param url The URL to open.
 @return `YES` Allow the SDK to open the link with UIApplication's openURL: or the internal browser.
 @return `NO` Ignore the request
 */
- (BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldOpenURL:(NSURL *)url;

/** Sent before the ad content is resized in response to a richmedia resize event.
 
 The ad view itself is not resized, instead a new window is displayed with the
 resized ad content.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param frame The frame relative to the window where the resized content is displayed.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView willResizeToFrame:(CGRect)frame;


/** Sent after the ad content is resized in response to a richmedia resize event.
 
 The ad view itself is not resized, instead a new window is displayed with the
 resized ad content.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param frame The frame relative to the window where the resized content is displayed.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView didResizeToFrame:(CGRect)frame;

/** Sent after the SDK process a richmedia event.
 
 Applications can use this to react to various events if necessary but the SDK will have
 already processed them as necessary (expanded in result of an expand request).
 
 @warning Developers should not attempt to implement the specified event.  The SDK will
 have already processed the event with the SDK implementation.
 
 See the IAB MRAID 2 specification on the event types.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param event The NSURLRequest containing the event request.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView didProcessRichmediaRequest:(NSURLRequest *)event;


/** Sent after an ad has been downloaded without errors.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewDidReceieveAd:(ImproveDigitalAdView *)adView;


/** Sent if an error was encoutered while donloading or rendering an ad.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param error The error encountered while attempting to receive or render the ad.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView didFailToReceiveAdWithError:(NSError *)error;


/** Sent after an ad has been loaded.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewDidLoadAd:(ImproveDigitalAdView *)adView;


/** Sent before the ad content is expanded in response to a richmedia expand event.
 
 The ad view itself is not expanded, instead a new window is displayed with the
 expanded ad content.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewWillExpand:(ImproveDigitalAdView *)adView;


/** Sent after the ad content is expanded in response to a richmedia expand event.
 
 The ad view itself is not expanded, instead a new window is displayed with the
 expanded ad content.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewDidExpand:(ImproveDigitalAdView *)adView;


/** Sent when the ad view is about to log an event.
 
 Logging in the SDK is done with NSLog().  Implement and return `NO` to log to application specific
 log files.  This message will only be sent if the event type is equal to or higher than the ImproveDigitalADView
 instance logLevel property.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param logData The LogData to log.
 @param type The event type.
 @return `YES` Log the event to NSLog().
 @return `NO` Omit logging the event to NSLog().
 */
- (BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldLogData:(LogData *)logData ofType:(ImproveDigitalLogEvent)type;

/** Sent to allow developers to override SMS support.
 
 If the device supports SMS this message will be sent to allow the developer to override support.
 The default behavior is to allow SMS usage.
 
 This message is not sent of the device does not support SMS.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return `NO` Informs richmedia ads that SMS is not supported.
 @return `YES` Informs richmedia ads that SMS is supported.
 */
- (BOOL)improveDigitalAdViewSupportsSMS:(ImproveDigitalAdView *)adView;


/** Sent to allow developers to override phone support.
 
 If the device supports phone dialling this message will be sent to allow the developer to override support.
 The default behavior is to allow phone dialing.
 
 This message is not sent of the device does not support phone dialing.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return `NO` Informs richmedia ads that phone calls is not supported.
 @return `YES` Informs richmedia ads that phone calls is supported.
 */
- (BOOL)improveDigitalAdViewSupportsPhone:(ImproveDigitalAdView *)adView;


/** Sent to allow developers to override calendar support.
 
 Implement to indicate if calendar events can be created.
 The default behavior is to NOT allow calendar access.
 
 On iOS 6 and later user permission is required to access the calendar.  If this message is
 implemented and returns YES then the SDK will ask the user for permission during [ImproveDigitalAdView update]
 or [ImproveDigitalAdView updateWithTimeInterval:]. Refer to iOS EKEventStore documentation for more information.
 
 @see [ImproveDigitalAdViewDelegate ImproveDigitalAdView:shouldSaveCalendarEvent:inEventStore:]
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return `NO` Informs richmedia ads that calendar access is not supported.
 @return `YES` Informs richmedia ads that calendar access is supported.
 */
- (BOOL)improveDigitalAdViewSupportsCalendar:(ImproveDigitalAdView *)adView;


/** Sent to allow developers to override picture storing support.
 
 Implement to indicate if storing pictures is supported. The default behavior is to NOT allow storing
 of pictures.
 
 @see [ImproveDigitalAdViewDelegate ImproveDigitalAdView:shouldSavePhotoToCameraRoll:]
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return `NO` Informs richmedia ads that storing pictures is not supported.
 @return `YES` Informs richmedia ads that storing pictures is supported.
 */
- (BOOL)improveDigitalAdViewSupportsStorePicture:(ImproveDigitalAdView *)adView;

/** Sent to allow developers to override location support.
 
 If the device supports location and if user grant access this message will be sent
 to allow the developer to override support. The default behavior is to allow location.
 
 This message is not sent of the device does not support location or location is forbidden by the user.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @return `NO` Informs richmedia ads that location is not supported.
 @return `YES` Informs richmedia ads that location is supported.
 */
- (BOOL)improveDigitalAdViewSupportsLocation:(ImproveDigitalAdView *)adView;

/** Sent when an ad desires to play a video in an external player.
 
 The default is to open the URL and play the video.
 
 Developers can use an application player and return NO to play the video directly.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param videoURL The URL string of the video to play.
 @return `NO` Do not open the URL and play the video.
 @return `YES` Invoke UIApplication openURL: to play the video.
 */
- (BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldPlayVideo:(NSString *)videoURL;


/** Sent when a richmedia ad attempts to create a new calendar entry.
 
 Application developers can implement the dialog directly if desired by capturing the event
 and eventStore and returning `nil`.  If not implemented the SDK will ignore the request.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param event The event to save.
 @param eventStore the store to save the event too.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldSDKHandleCalendarEvent:(EKEvent *)event inEventStore:(EKEventStore *)eventStore;


/** Sent when a richmedia ad attempts to save a picture to the camera roll.
 
 Application developers should implement this by prompting the user to save the image and then saving
 it directly and returning NO from this delegate method.  If not implemented the image will NOT be
 saved to the camera roll.
 
 Note: iOS 6 added privacy options for applications saving to the camera roll.  The user will be
 prompted by iOS on the first attempt at accessing the camera roll.  If the user selects No then
 pictures will not be saved to the camera roll even if this method is implemented and returns `YES`.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 @param image The image to save.
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldSDKHandlePictureStore:(UIImage *)image;


/** Sent after image is stored to photo album.
 
 Application developers should implement this if they want to do something with image stored in
 camera roll.
 
 @param image Image stored in camera roll
 @param error Error occured during image saving
 */
- (void)improveDigitalAdViewDidSavePhotoToCameraRoll:(UIImage *)image withError:(NSError *)error;

/** Sent before ad content is collaped if expanded or resized.improveDigitalAdViewDidClicked
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewWillCollapse:(ImproveDigitalAdView *)adView;


/** Sent after ad content is collaped if expanded or resized.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewDidCollapse:(ImproveDigitalAdView *)adView;

/**
    Sent after user clicked(touched) on adView
 */
- (void)improveDigitalAdViewDidClicked:(ImproveDigitalAdView *)adView;

/** Sent before the ad opens a URL that invokes another application (ex: Safari or App Store).
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewWillLeaveApplication:(ImproveDigitalAdView *)adView;


/** Sent after if ad content is bigger than ad View.
 
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdContentIsBigger:(ImproveDigitalAdView *)adView;

/**
 Sent after size of the adView is changed.
 @param adView The ImproveDigitalAdView instance sending the message.
 @param size New size of the adView
 */
- (void)improveDigitalAdView:(ImproveDigitalAdView *)adView didSizeChanged:(CGSize)size;

/**
 This method will be invoked once creative "decide" to perform ad view unload. It might be related to many reasons,
 ad encounter communication error with the ad server or it is not able to load all required assets.
 It may happen during pre-load, initialization and also during later stages. It is on app developer to decide
 if the application should reload existing ad view, load new placement, remove ad view or replace with new ad view.
 @param adView The ImproveDigitalAdView instance sending the message.
 */
- (void)improveDigitalAdViewUnload:(ImproveDigitalAdView *)adView;

@end

#endif
