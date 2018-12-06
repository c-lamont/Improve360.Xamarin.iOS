//
//  PlayerLayout.h
//  Mobile360SDK
//
//  Created by Ognjen Manevski on 7/6/16.
//  Copyright © 2016 Levi9. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

/** This class is used to customize ImproveDigitalVideoPlayer
 */
@interface PlayerLayout : NSObject
/** UIImage for the play button
 */
@property(nonatomic, retain) UIImage *imagePlay;
/** UIImage for the pause button
 */
@property(nonatomic, retain) UIImage *imagePause;
/** UIColor for the container for the controls
 */
@property(nonatomic, retain) UIColor *overlayColor;
/** UIImage for the fast forward button
 */
@property(nonatomic, retain) UIImage *imageFastForward;
/** UIImage for the rewind button
 */
@property(nonatomic, retain) UIImage *imageRewind;
/** UIImage for the slider indicator (thumb)
 */
@property(nonatomic, retain) UIImage *imagePlaybackSliderIndicator;
/** UIImage for the volume slider indicator (thumb)
 */
@property(nonatomic, retain) UIImage *imageVolumeSliderIndicator;
/** UIImage for the fullscreen button
 */
@property(nonatomic, retain) UIImage *imageFullScreen;

/** Text for Done buttton (button to exit full screen)
 */
@property(nonatomic, copy) NSString *doneButtonText;

/** Background color for the player (initial is black)
 */
@property(nonatomic, retain) UIColor *backgroundColor;

/** UIImage for the collapse button
 */
@property(nonatomic, retain) UIImage *imageCollapse;

/** Controls display duration in seconds. 
 If property is set to zero or negative value, controls will not be shown.
 If the property is not set, default value of 3 seconds will be used
 */
@property int controlsVisibilityDuration;

@end
