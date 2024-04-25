#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "DM_PhoneDefine.h"
#import "DM_PhoneInfo.h"
#import "DM_Reachability.h"
#import "UIDevice+DM_DeviceInfo.h"

FOUNDATION_EXPORT double SLAdVersionNumber;
FOUNDATION_EXPORT const unsigned char SLAdVersionString[];

