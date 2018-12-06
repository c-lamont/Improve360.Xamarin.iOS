//
//  ImproveDigitalVideoPlayer.h
//  Mobile360SDK
//
//  Created by Manevski Ognjen on 7/2/16.
//  Copyright © 2016 Levi9. All rights reserved.
//


#import <AVFoundation/AVFoundation.h>
#import "PlayerLayout.h"
#import "ImproveDigitalVideoDelegate.h"

@class ImproveDigitalVideoPlayer;

typedef NS_ENUM(NSInteger, ImproveDigitalVastError) {
    ImproveDigitalVastNoError = 0, // Not used
    ImproveDigitalVastAdVideoError = 100,
    ImproveDigitalVastContentVideoError = 200,
    ImproveDigitalVastUnknown = 9999
};

@interface ImproveDigitalVideoPlayer : UIView

/** Sets the ImproveDigitalVideoDelegate delegate receiever for the ImproveDigitalVideoPlayer view.
 
 @warning Proper reference management practices should be observed when using delegates.
 @warning Ensure that the delegate is set to nil prior to releasing the ad view's instance.
 */
@property(nonatomic, weak) id <ImproveDigitalVideoDelegate> delegate;

/** Specifies the placementId for the ad network.
 */
@property(nonatomic, strong) NSString *placementId;

/** Specifies the log level.  All logging is via NSLog().
 
 @see [ImproveDigitalAdViewDelegate videoPlayer:shouldLogData:ofType:]
 */
@property(nonatomic, assign) ImproveDigitalLogEvent logLevel;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 */
- (id)initWithFrame:(CGRect)frame;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 @param playerLayout PlayerLayout instance which contains custom assets for ImproveDigitalVideoPlayer view.
 */
- (id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 @param contentURL NSURL instance which will be played by ImproveDigitalVideoPlayer view's player
 */
- (id)initWithFrame:(CGRect)frame contentURL:(NSURL *)contentURL;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 @param playerItem AVPlayerItem instance
 */
- (id)initWithFrame:(CGRect)frame playerItem:(AVPlayerItem *)playerItem;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 @param playerLayout PlayerLayout instance which contains custom assets for ImproveDigitalVideoPlayer view.
 If it's nil, the default assets will be used for the ImproveDigitalVideoPlayer view.
 @param contentURL NSURL instance which will be played by ImproveDigitalVideoPlayer view's player
 */
- (id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout contentURL:(NSURL *)contentURL;

/** Constructor
 @param frame CGRect for the ImproveDigitalVideoPlayer view
 @param playerLayout PlayerLayout instance which contains custom assets for ImproveDigitalVideoPlayer view.
 If it's nil, the default assets will be used for the ImproveDigitalVideoPlayer view.
 @param playerItem AVPlayerItem instance
 */
- (id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout playerItem:(AVPlayerItem *)playerItem;

///---------------------------------------------------------------------------------------
/// @name Player actions
///---------------------------------------------------------------------------------------

/** set the url to a player 
 * if player is already is in play mode, it will be stopped
 * and @url will be loaded
 */
- (void)setUrl:(NSURL *)url;

/** Set the PlayerLayout
 * must be called before play
 */
- (void)setPlayerLayout:(PlayerLayout *)playerLayout;

/** Initiate and and content video load
 */
- (void)load;

/** Playing the video from contentURL
 */
- (void)play;

/** Pausing the playing video
 */
- (void)pause;

/** Return if video is in play state, no matter if AD or content video is playing
 */
- (BOOL)isPlaying;

/** Fast Forwarding the playing video
 @param seconds
 */
- (void)fastForward;

/** Rewinding the playing video
 @param seconds
 */
- (void)rewind;

/** Setting the volume of the video
 @param volume (float value from 0.0 to 1.0
 */
- (void)setVolumeLevel:(float)volume;

- (CMTime)currentTime;

- (void)setTime:(CMTime)time;

@end
