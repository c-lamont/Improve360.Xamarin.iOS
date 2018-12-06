//  ImproveDigitalModalViewController.h
//  ImproveDigitalAdView


#import <UIKit/UIKit.h>

@class ImproveDigitalModalViewController;

@protocol ImproveDigitalModalViewControllerDelegate <NSObject>

- (void)ImproveDigitalModalViewControllerWillRotate:(ImproveDigitalModalViewController *)modalViewController;
- (void)ImproveDigitalModalViewControllerDidRotate:(ImproveDigitalModalViewController *)modalViewController;

@end

@interface ImproveDigitalModalViewController : UIViewController

@property(nonatomic, assign) id <ImproveDigitalModalViewControllerDelegate> delegate;
/**
 Specifies whether rotation is allowed or not. Default value is NO.
 */
@property(nonatomic, assign) BOOL allowRotation;

- (void)forceRotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end
