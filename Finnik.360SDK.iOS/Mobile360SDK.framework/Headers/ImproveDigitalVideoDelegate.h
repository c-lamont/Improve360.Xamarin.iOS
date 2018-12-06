//
//  ImproveDigitalVideoDelegate.h
//  Mobile360SDK
//
//  Created by Manevski Ognjen on 7/2/16.
//  Copyright © 2016 Levi9. All rights reserved.
//

@class ImproveDigitalVideoPlayer;

/** Protocal for interaction with the ImproveDigitalVideoPlayer.
 The entire protocol is optional.
 */
@protocol ImproveDigitalVideoDelegate <NSObject>

/** Sent when the video url is loaded.
 @param view The ImproveDigitalVideoPlayer instance sending the message.
 */
- (void)videoPlayerUrlLoaded:(ImproveDigitalVideoPlayer *)view;

/** Sent when some error occurred.
 @param view The ImproveDigitalVideoPlayer instance sending the message.
 @param error NSError instance which contains error data.
 */
- (void)videoPlayerErrorOccurred:(ImproveDigitalVideoPlayer *)view error:(NSError *)error;

@optional

/** Sent when the ImproveDigitalVideoPlayer finished playback.
 @param view The ImproveDigitalVideoPlayer instance sending the message.
 */
- (void)videoPlayerFinishedPlayback:(ImproveDigitalVideoPlayer *)view;

/** Sent when video player is expanded to fullscreen.
 @param view The ImproveDigitalVideoPlayer instance expanded.
 */
- (void)videoPlayerExpanded:(ImproveDigitalVideoPlayer *)view;

/** Sent when video player is collapsed to origin
 @param view The ImproveDigitalVideoPlayer instance collapsed.
 */
- (void)videoPlayerCollapsed:(ImproveDigitalVideoPlayer *)view;

/** Sent when video player is collapsed to origin (Done button selected).
Video will be stopped
 @param view The ImproveDigitalVideoPlayer instance collapsed.
 */
- (void)videoPlayerDone:(ImproveDigitalVideoPlayer *)view;

/** Sent when video player is about to log an event.
 
 Logging in the SDK is done with NSLog().  Implement and return `NO` to log to application specific
 log files.  This message will only be sent if the event type is equal to or higher than the ImproveDigitalVideoPlayer
 instance logLevel property.
 
 @param view The ImproveDigitalVideoPlayer instance sending the message.
 @param logData The LogData to log.
 @param type The event type.
 @return `YES` Log the event to NSLog().
 @return `NO` Omit logging the event to NSLog().
 */
- (BOOL)videoPlayer:(ImproveDigitalVideoPlayer *)view shouldLogData:(LogData *)logData ofType:(ImproveDigitalLogEvent)type;
@end
