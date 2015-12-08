//
//  TWMError.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

/** The Twilio IP Messaging error domain. */
FOUNDATION_EXPORT NSString * const TWMErrorDomain;

/** The generic error errorCode. */
FOUNDATION_EXPORT NSInteger const TWMErrorGeneric;

/** The userInfo key for the error message, if any. */
FOUNDATION_EXPORT NSString * const TWMErrorMsgKey;

/** The userInfo key for the error code, if any. */
FOUNDATION_EXPORT NSString* const TWMErrorCodeKey;

/** Twilio IP Messaging error object */
@interface TWMError : NSError

@end
