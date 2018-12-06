using System;
using AVFoundation;
using CoreGraphics;
using CoreMedia;
using EventKit;
using Foundation;
using ObjCRuntime;
using UIKit;

namespace MyTest
{
    [Static]
    //[Verify(ConstantsInterfaceAssociation)]
    partial interface Constants
    {
        // extern double ImproveDigitalAdVersionNumber;
        [Field("ImproveDigitalAdVersionNumber", "__Internal")]
        double ImproveDigitalAdVersionNumber { get; }

        // extern const unsigned char [] ImproveDigitalAdVersionString;
        [Field("ImproveDigitalAdVersionString", "__Internal")]
        IntPtr ImproveDigitalAdVersionString { get; }
    }

    // @interface LogData : NSObject
    [BaseType(typeof(NSObject))]
    interface LogData
    {
        // @property (assign, nonatomic) ImproveDigitalLogEvent logType;
        [Export("logType", ArgumentSemantic.Assign)]
        ImproveDigitalLogEvent LogType { get; set; }

        // @property (copy, nonatomic) NSString * message;
        [Export("message")]
        string Message { get; set; }

        // @property (assign, nonatomic) const char * func;
        [Export("func", ArgumentSemantic.Assign)]
        sbyte Func { get; set; }

        // @property (assign, nonatomic) int line;
        [Export("line")]
        int Line { get; set; }

        // @property (nonatomic, strong) NSError * error;
        [Export("error", ArgumentSemantic.Strong)]
        NSError Error { get; set; }

        // @property (readonly, nonatomic) NSDate * date;
        [Export("date")]
        NSDate Date { get; }

        // -(NSString *)getLogTypeString;
        [Export("getLogTypeString")]
        //[Verify(MethodToProperty)]
        string LogTypeString { get; }

        // -(id)initWithLogType:(ImproveDigitalLogEvent)logType message:(NSString *)message error:(NSError *)err function:(const char *)func andLine:(int)line;
        [Export("initWithLogType:message:error:function:andLine:")]
        IntPtr Constructor(ImproveDigitalLogEvent logType, string message, NSError err, sbyte func, int line);

        // -(NSString *)description;
        [Export("description")]
        //[Verify(MethodToProperty)]
        string Description { get; }
    }

    // @protocol ImproveDigitalAdViewDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface ImproveDigitalAdViewDelegate
    {
        // @optional -(UIViewController *)improveDigitalAdViewPresentationController:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewPresentationController:")]
        UIViewController ImproveDigitalAdViewPresentationController(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewCloseButtonPressed:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewCloseButtonPressed:")]
        void ImproveDigitalAdViewCloseButtonPressed(ImproveDigitalAdView adView);

        // @optional -(UIButton *)improveDigitalAdViewCustomCloseButton:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewCustomCloseButton:")]
        UIButton ImproveDigitalAdViewCustomCloseButton(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldOpenURL:(NSURL *)url;
        [Export("improveDigitalAdView:shouldOpenURL:")]
        bool ImproveDigitalAdView(ImproveDigitalAdView adView, NSUrl url);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView willResizeToFrame:(CGRect)frame;
        [Export("improveDigitalAdView:willResizeToFrame:")]
        void ImproveDigitalAdViewWillResizeToFrame(ImproveDigitalAdView adView, CGRect frame);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView didResizeToFrame:(CGRect)frame;
        [Export("improveDigitalAdView:didResizeToFrame:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, CGRect frame);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView didProcessRichmediaRequest:(NSURLRequest *)event;
        [Export("improveDigitalAdView:didProcessRichmediaRequest:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, NSUrlRequest @event);

        // @optional -(void)improveDigitalAdViewDidReceieveAd:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewDidReceieveAd:")]
        void ImproveDigitalAdViewDidReceieveAd(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView didFailToReceiveAdWithError:(NSError *)error;
        [Export("improveDigitalAdView:didFailToReceiveAdWithError:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, NSError error);

        // @optional -(void)improveDigitalAdViewDidLoadAd:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewDidLoadAd:")]
        void ImproveDigitalAdViewDidLoadAd(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewWillExpand:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewWillExpand:")]
        void ImproveDigitalAdViewWillExpand(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewDidExpand:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewDidExpand:")]
        void ImproveDigitalAdViewDidExpand(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldLogData:(LogData *)logData ofType:(ImproveDigitalLogEvent)type;
        [Export("improveDigitalAdView:shouldLogData:ofType:")]
        bool ImproveDigitalAdView(ImproveDigitalAdView adView, LogData logData, ImproveDigitalLogEvent type);

        // @optional -(BOOL)improveDigitalAdViewSupportsSMS:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewSupportsSMS:")]
        bool ImproveDigitalAdViewSupportsSMS(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdViewSupportsPhone:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewSupportsPhone:")]
        bool ImproveDigitalAdViewSupportsPhone(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdViewSupportsCalendar:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewSupportsCalendar:")]
        bool ImproveDigitalAdViewSupportsCalendar(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdViewSupportsStorePicture:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewSupportsStorePicture:")]
        bool ImproveDigitalAdViewSupportsStorePicture(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdViewSupportsLocation:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewSupportsLocation:")]
        bool ImproveDigitalAdViewSupportsLocation(ImproveDigitalAdView adView);

        // @optional -(BOOL)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldPlayVideo:(NSString *)videoURL;
        [Export("improveDigitalAdView:shouldPlayVideo:")]
        bool ImproveDigitalAdView(ImproveDigitalAdView adView, string videoURL);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldSDKHandleCalendarEvent:(EKEvent *)event inEventStore:(EKEventStore *)eventStore;
        [Export("improveDigitalAdView:shouldSDKHandleCalendarEvent:inEventStore:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, EKEvent @event, EKEventStore eventStore);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView shouldSDKHandlePictureStore:(UIImage *)image;
        [Export("improveDigitalAdView:shouldSDKHandlePictureStore:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, UIImage image);

        // @optional -(void)improveDigitalAdViewDidSavePhotoToCameraRoll:(UIImage *)image withError:(NSError *)error;
        [Export("improveDigitalAdViewDidSavePhotoToCameraRoll:withError:")]
        void ImproveDigitalAdViewDidSavePhotoToCameraRoll(UIImage image, NSError error);

        // @optional -(void)improveDigitalAdViewWillCollapse:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewWillCollapse:")]
        void ImproveDigitalAdViewWillCollapse(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewDidCollapse:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewDidCollapse:")]
        void ImproveDigitalAdViewDidCollapse(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewDidClicked:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewDidClicked:")]
        void ImproveDigitalAdViewDidClicked(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdViewWillLeaveApplication:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewWillLeaveApplication:")]
        void ImproveDigitalAdViewWillLeaveApplication(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdContentIsBigger:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdContentIsBigger:")]
        void ImproveDigitalAdContentIsBigger(ImproveDigitalAdView adView);

        // @optional -(void)improveDigitalAdView:(ImproveDigitalAdView *)adView didSizeChanged:(CGSize)size;
        [Export("improveDigitalAdView:didSizeChanged:")]
        void ImproveDigitalAdView(ImproveDigitalAdView adView, CGSize size);

        // @optional -(void)improveDigitalAdViewUnload:(ImproveDigitalAdView *)adView;
        [Export("improveDigitalAdViewUnload:")]
        void ImproveDigitalAdViewUnload(ImproveDigitalAdView adView);
    }

    // @interface ImproveDigitalAdView : UIView <UIGestureRecognizerDelegate>
    [BaseType(typeof(UIView))]
    interface ImproveDigitalAdView : IUIGestureRecognizerDelegate
    {
        // -(id)initWithCoder:(NSCoder *)aDecoder;
        //[Export("initWithCoder:")]
        //IntPtr Constructor(NSCoder aDecoder);

        // -(id)initWithFrame:(CGRect)frame;
        [Export("initWithFrame:")]
        IntPtr Constructor(CGRect frame);

        [Wrap("WeakDelegate")]
        ImproveDigitalAdViewDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<ImproveDigitalAdViewDelegate> delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic, strong) NSString * placementId;
        [Export("placementId", ArgumentSemantic.Strong)]
        string PlacementId { get; set; }

        // @property (nonatomic, strong) NSString * adHeight;
        [Export("adHeight", ArgumentSemantic.Strong)]
        string AdHeight { get; set; }

        // @property (nonatomic, strong) NSString * adWidth;
        [Export("adWidth", ArgumentSemantic.Strong)]
        string AdWidth { get; set; }

        // @property (assign, nonatomic) BOOL useSecureConnection;
        [Export("useSecureConnection")]
        bool UseSecureConnection { get; set; }

        // @property (assign, nonatomic) BOOL allowAdScrolling;
        [Export("allowAdScrolling")]
        bool AllowAdScrolling { get; set; }

        // @property (readonly, nonatomic) ImproveDigitalAdViewPlacementType placementType;
        [Export("placementType")]
        ImproveDigitalAdViewPlacementType PlacementType { get; }

        // @property (readonly, nonatomic) BOOL locationDetectionEnabled;
        [Export("locationDetectionEnabled")]
        bool LocationDetectionEnabled { get; }

        // @property (assign, nonatomic) BOOL useCustomLocation;
        [Export("useCustomLocation")]
        bool UseCustomLocation { get; set; }

        // @property (assign, nonatomic) ImproveDigitalLogEvent logLevel;
        [Export("logLevel", ArgumentSemantic.Assign)]
        ImproveDigitalLogEvent LogLevel { get; set; }

        // @property (assign, nonatomic) ImproveDigitalMraidEnvironment mraidEnv;
        [Export("mraidEnv", ArgumentSemantic.Assign)]
        ImproveDigitalMraidEnvironment MraidEnv { get; set; }

        // @property (retain, nonatomic) NSNumber * userAge;
        [Export("userAge", ArgumentSemantic.Retain)]
        NSNumber UserAge { get; set; }

        // @property (assign, nonatomic) ImproveDigitalGender userGender;
        [Export("userGender", ArgumentSemantic.Assign)]
        ImproveDigitalGender UserGender { get; set; }

        // -(void)setCustomLocationWithLatitude:(double)latitude andLongitude:(double)longitude;
        [Export("setCustomLocationWithLatitude:andLongitude:")]
        void SetCustomLocationWithLatitude(double latitude, double longitude);

        // -(void)setAdResponse:(NSData *)response;
        [Export("setAdResponse:")]
        void SetAdResponse(NSData response);

        // -(void)loadAd;
        [Export("loadAd")]
        void LoadAd();

        // -(void)setInterstitial;
        [Export("setInterstitial")]
        void SetInterstitial();

        // -(void)showCloseButtonAfterDelay:(NSTimeInterval)delay;
        [Export("showCloseButtonAfterDelay:")]
        void ShowCloseButtonAfterDelay(double delay);

        // -(void)reset;
        [Export("reset")]
        void Reset();

        // -(void)showInterstitial;
        [Export("showInterstitial")]
        void ShowInterstitial();

        // -(void)showInterstitialWithDuration:(NSTimeInterval)duration;
        [Export("showInterstitialWithDuration:")]
        void ShowInterstitialWithDuration(double duration);

        // -(void)closeInterstitial;
        [Export("closeInterstitial")]
        void CloseInterstitial();

        // @property (assign, nonatomic) BOOL useInternalBrowser;
        [Export("useInternalBrowser")]
        bool UseInternalBrowser { get; set; }

        // @property (assign, nonatomic) ImproveDigitalAdViewAnimationType animationType;
        [Export("animationType", ArgumentSemantic.Assign)]
        ImproveDigitalAdViewAnimationType AnimationType { get; set; }

        // @property (assign, nonatomic) double animationDuration;
        [Export("animationDuration")]
        double AnimationDuration { get; set; }
    }

    // @protocol ImproveDigitalModalViewControllerDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface ImproveDigitalModalViewControllerDelegate
    {
        // @required -(void)ImproveDigitalModalViewControllerWillRotate:(ImproveDigitalModalViewController *)modalViewController;
        [Abstract]
        [Export("ImproveDigitalModalViewControllerWillRotate:")]
        void ImproveDigitalModalViewControllerWillRotate(ImproveDigitalModalViewController modalViewController);

        // @required -(void)ImproveDigitalModalViewControllerDidRotate:(ImproveDigitalModalViewController *)modalViewController;
        [Abstract]
        [Export("ImproveDigitalModalViewControllerDidRotate:")]
        void ImproveDigitalModalViewControllerDidRotate(ImproveDigitalModalViewController modalViewController);
    }

    // @interface ImproveDigitalModalViewController : UIViewController
    [BaseType(typeof(UIViewController))]
    interface ImproveDigitalModalViewController
    {
        [Wrap("WeakDelegate")]
        ImproveDigitalModalViewControllerDelegate Delegate { get; set; }

        // @property (assign, nonatomic) id<ImproveDigitalModalViewControllerDelegate> delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Assign)]
        NSObject WeakDelegate { get; set; }

        // @property (assign, nonatomic) BOOL allowRotation;
        [Export("allowRotation")]
        bool AllowRotation { get; set; }

        // -(void)forceRotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
        [Export("forceRotateToInterfaceOrientation:")]
        void ForceRotateToInterfaceOrientation(UIInterfaceOrientation interfaceOrientation);
    }

    // @protocol ImproveDigitalVideoDelegate <NSObject>
    [Protocol, Model]
    [BaseType(typeof(NSObject))]
    interface ImproveDigitalVideoDelegate
    {
        // @required -(void)videoPlayerUrlLoaded:(ImproveDigitalVideoPlayer *)view;
        [Abstract]
        [Export("videoPlayerUrlLoaded:")]
        void VideoPlayerUrlLoaded(ImproveDigitalVideoPlayer view);

        // @required -(void)videoPlayerErrorOccurred:(ImproveDigitalVideoPlayer *)view error:(NSError *)error;
        [Abstract]
        [Export("videoPlayerErrorOccurred:error:")]
        void VideoPlayerErrorOccurred(ImproveDigitalVideoPlayer view, NSError error);

        // @optional -(void)videoPlayerFinishedPlayback:(ImproveDigitalVideoPlayer *)view;
        [Export("videoPlayerFinishedPlayback:")]
        void VideoPlayerFinishedPlayback(ImproveDigitalVideoPlayer view);

        // @optional -(void)videoPlayerExpanded:(ImproveDigitalVideoPlayer *)view;
        [Export("videoPlayerExpanded:")]
        void VideoPlayerExpanded(ImproveDigitalVideoPlayer view);

        // @optional -(void)videoPlayerCollapsed:(ImproveDigitalVideoPlayer *)view;
        [Export("videoPlayerCollapsed:")]
        void VideoPlayerCollapsed(ImproveDigitalVideoPlayer view);

        // @optional -(void)videoPlayerDone:(ImproveDigitalVideoPlayer *)view;
        [Export("videoPlayerDone:")]
        void VideoPlayerDone(ImproveDigitalVideoPlayer view);

        // @optional -(BOOL)videoPlayer:(ImproveDigitalVideoPlayer *)view shouldLogData:(LogData *)logData ofType:(ImproveDigitalLogEvent)type;
        [Export("videoPlayer:shouldLogData:ofType:")]
        bool VideoPlayer(ImproveDigitalVideoPlayer view, LogData logData, ImproveDigitalLogEvent type);
    }

    // @interface PlayerLayout : NSObject
    [BaseType(typeof(NSObject))]
    interface PlayerLayout
    {
        // @property (retain, nonatomic) UIImage * imagePlay;
        [Export("imagePlay", ArgumentSemantic.Retain)]
        UIImage ImagePlay { get; set; }

        // @property (retain, nonatomic) UIImage * imagePause;
        [Export("imagePause", ArgumentSemantic.Retain)]
        UIImage ImagePause { get; set; }

        // @property (retain, nonatomic) UIColor * overlayColor;
        [Export("overlayColor", ArgumentSemantic.Retain)]
        UIColor OverlayColor { get; set; }

        // @property (retain, nonatomic) UIImage * imageFastForward;
        [Export("imageFastForward", ArgumentSemantic.Retain)]
        UIImage ImageFastForward { get; set; }

        // @property (retain, nonatomic) UIImage * imageRewind;
        [Export("imageRewind", ArgumentSemantic.Retain)]
        UIImage ImageRewind { get; set; }

        // @property (retain, nonatomic) UIImage * imagePlaybackSliderIndicator;
        [Export("imagePlaybackSliderIndicator", ArgumentSemantic.Retain)]
        UIImage ImagePlaybackSliderIndicator { get; set; }

        // @property (retain, nonatomic) UIImage * imageVolumeSliderIndicator;
        [Export("imageVolumeSliderIndicator", ArgumentSemantic.Retain)]
        UIImage ImageVolumeSliderIndicator { get; set; }

        // @property (retain, nonatomic) UIImage * imageFullScreen;
        [Export("imageFullScreen", ArgumentSemantic.Retain)]
        UIImage ImageFullScreen { get; set; }

        // @property (copy, nonatomic) NSString * doneButtonText;
        [Export("doneButtonText")]
        string DoneButtonText { get; set; }

        // @property (retain, nonatomic) UIColor * backgroundColor;
        [Export("backgroundColor", ArgumentSemantic.Retain)]
        UIColor BackgroundColor { get; set; }

        // @property (retain, nonatomic) UIImage * imageCollapse;
        [Export("imageCollapse", ArgumentSemantic.Retain)]
        UIImage ImageCollapse { get; set; }

        // @property int controlsVisibilityDuration;
        [Export("controlsVisibilityDuration")]
        int ControlsVisibilityDuration { get; set; }
    }

    // @interface ImproveDigitalVideoPlayer : UIView
    [BaseType(typeof(UIView))]
    interface ImproveDigitalVideoPlayer
    {
        [Wrap("WeakDelegate")]
        ImproveDigitalVideoDelegate Delegate { get; set; }

        // @property (nonatomic, weak) id<ImproveDigitalVideoDelegate> delegate;
        [NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
        NSObject WeakDelegate { get; set; }

        // @property (nonatomic, strong) NSString * placementId;
        [Export("placementId", ArgumentSemantic.Strong)]
        string PlacementId { get; set; }

        // @property (assign, nonatomic) ImproveDigitalLogEvent logLevel;
        [Export("logLevel", ArgumentSemantic.Assign)]
        ImproveDigitalLogEvent LogLevel { get; set; }

        // -(id)initWithFrame:(CGRect)frame;
        [Export("initWithFrame:")]
        IntPtr Constructor(CGRect frame);

        // -(id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout;
        [Export("initWithFrame:playerLayout:")]
        IntPtr Constructor(CGRect frame, PlayerLayout playerLayout);

        // -(id)initWithFrame:(CGRect)frame contentURL:(NSURL *)contentURL;
        [Export("initWithFrame:contentURL:")]
        IntPtr Constructor(CGRect frame, NSUrl contentURL);

        // -(id)initWithFrame:(CGRect)frame playerItem:(AVPlayerItem *)playerItem;
        [Export("initWithFrame:playerItem:")]
        IntPtr Constructor(CGRect frame, AVPlayerItem playerItem);

        // -(id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout contentURL:(NSURL *)contentURL;
        [Export("initWithFrame:playerLayout:contentURL:")]
        IntPtr Constructor(CGRect frame, PlayerLayout playerLayout, NSUrl contentURL);

        // -(id)initWithFrame:(CGRect)frame playerLayout:(PlayerLayout *)playerLayout playerItem:(AVPlayerItem *)playerItem;
        [Export("initWithFrame:playerLayout:playerItem:")]
        IntPtr Constructor(CGRect frame, PlayerLayout playerLayout, AVPlayerItem playerItem);

        // -(void)setUrl:(NSURL *)url;
        [Export("setUrl:")]
        void SetUrl(NSUrl url);

        // -(void)setPlayerLayout:(PlayerLayout *)playerLayout;
        [Export("setPlayerLayout:")]
        void SetPlayerLayout(PlayerLayout playerLayout);

        // -(void)load;
        [Export("load")]
        void Load();

        // -(void)play;
        [Export("play")]
        void Play();

        // -(void)pause;
        [Export("pause")]
        void Pause();

        // -(BOOL)isPlaying;
        [Export("isPlaying")]
        //[Verify(MethodToProperty)]
        bool IsPlaying { get; }

        // -(void)fastForward;
        [Export("fastForward")]
        void FastForward();

        // -(void)rewind;
        [Export("rewind")]
        void Rewind();

        // -(void)setVolumeLevel:(float)volume;
        [Export("setVolumeLevel:")]
        void SetVolumeLevel(float volume);

        // -(CMTime)currentTime;
        [Export("currentTime")]
        //[Verify(MethodToProperty)]
        CMTime CurrentTime { get; }

        // -(void)setTime:(CMTime)time;
        [Export("setTime:")]
        void SetTime(CMTime time);
    }

    //[Static]
    //[Verify(ConstantsInterfaceAssociation)]
    partial interface Constants
    {
        // extern NSString * kReachabilityChangedNotification;
        [Field("kReachabilityChangedNotification", "__Internal")]
        NSString kReachabilityChangedNotification { get; }
    }

    // @interface Reachability : NSObject
    [BaseType(typeof(NSObject))]
    interface Reachability
    {
        // +(instancetype)reachabilityWithHostName:(NSString *)hostName;
        [Static]
        [Export("reachabilityWithHostName:")]
        Reachability ReachabilityWithHostName(string hostName);

        // +(instancetype)reachabilityWithAddress:(const struct sockaddr_in *)hostAddress;
        //[Static]
        //[Export("reachabilityWithAddress:")]
        //unsafe Reachability ReachabilityWithAddress(sockaddr_in* hostAddress);

        // +(instancetype)reachabilityForInternetConnection;
        [Static]
        [Export("reachabilityForInternetConnection")]
        Reachability ReachabilityForInternetConnection();

        // +(instancetype)reachabilityForLocalWiFi;
        [Static]
        [Export("reachabilityForLocalWiFi")]
        Reachability ReachabilityForLocalWiFi();

        // -(BOOL)startNotifier;
        [Export("startNotifier")]
        //[Verify(MethodToProperty)]
        bool StartNotifier { get; }

        // -(void)stopNotifier;
        [Export("stopNotifier")]
        void StopNotifier();

        // -(NetworkStatus)currentReachabilityStatus;
        [Export("currentReachabilityStatus")]
        //[Verify(MethodToProperty)]
        NetworkStatus CurrentReachabilityStatus { get; }

        // -(BOOL)connectionRequired;
        [Export("connectionRequired")]
        //[Verify(MethodToProperty)]
        bool ConnectionRequired { get; }
    }

    // @interface Mobile360SDK : NSObject
    [BaseType(typeof(NSObject))]
    interface Mobile360SDK
    {
        // @property (assign, nonatomic, class) ImproveDigitalMraidEnvironment mraidEnv;
        [Static]
        [Export("mraidEnv", ArgumentSemantic.Assign)]
        ImproveDigitalMraidEnvironment MraidEnv { get; set; }

        // +(void)forCountry:(NSString *)value;
        [Static]
        [Export("forCountry:")]
        void ForCountry(string value);

        // +(NSString *)hostApplicationId;
        [Static]
        [Export("hostApplicationId")]
        //[Verify(MethodToProperty)]
        string HostApplicationId { get; }

        // +(NSString *)sdkVersion;
        [Static]
        [Export("sdkVersion")]
        //[Verify(MethodToProperty)]
        string SdkVersion { get; }

        // +(NSString *)sdkName;
        [Static]
        [Export("sdkName")]
        //[Verify(MethodToProperty)]
        string SdkName { get; }

        // +(NSString *)mraidVersion;
        [Static]
        [Export("mraidVersion")]
        //[Verify(MethodToProperty)]
        string MraidVersion { get; }
    }
}
