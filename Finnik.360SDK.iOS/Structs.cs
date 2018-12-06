using System;
using System;
using System.Runtime.InteropServices;
//using Mobile360SDK;
using ObjCRuntime;


namespace MyTest
{
    [Native]
    public enum ImproveDigitalLogEvent : ulong
    {
        None = 0,
        Error = 1,
        Info = 2
    }

    public enum ImproveDigitalAdViewPlacementType : uint
    {
        line = 0,
        terstitial
    }

    [Native]
    public enum ImproveDigitalError : ulong
    {
        NoError = 0,
        RequestError = 100,
        NoFill = 200,
        ResponseError = 300,
        ContentLoadError = 400
    }

    public enum ImproveDigitalAdViewAnimationType : uint
    {
        None = 0,
        FromLeft,
        FromRight,
        FromBottom,
        FromTop,
        FadeIn
    }

    [Native]
    public enum ImproveDigitalGender : ulong
    {
        None = 0,
        Male,
        Female
    }

    [StructLayout (LayoutKind.Sequential)]
    public struct ImproveDigitalMraidEnvironment
    {
        public bool fillOptionalValues;

        public bool targetContentForChildren;
    }

    static class CFunctions
    {
        // extern ImproveDigitalMraidEnvironment ImproveDigitalMraidEnvironmentMake (BOOL fillOptionalValues, BOOL targetContentForChildren);
        [DllImport ("__Internal")]
        //[Verify (PlatformInvoke)]
        static extern ImproveDigitalMraidEnvironment ImproveDigitalMraidEnvironmentMake (bool fillOptionalValues, bool targetContentForChildren);
    }

    [Native]
    public enum ImproveDigitalVastError : ulong
    {
        NoError = 0,
        AdVideoError = 100,
        ContentVideoError = 200,
        Unknown = 9999
    }

    [Native]
    public enum NetworkStatus : ulong
    {
        NotReachable = 0,
        ReachableViaWiFi,
        ReachableViaWWAN
    }
}