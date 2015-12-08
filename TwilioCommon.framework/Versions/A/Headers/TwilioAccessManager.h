//
//  TwilioAccessManager.h
//  TwilioAccessManager
//
//  Copyright © 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TwilioAccessManagerDelegate;

/** Shared Access Manager for Twilio clients.  Manages sharing an access token as well as notifications upon token expiry.
 */
@interface TwilioAccessManager : NSObject

/**  Delegate for token expiry and error notifications. */
@property (nonatomic, weak) id<TwilioAccessManagerDelegate> delegate;

/**
 Creates a new Access Manager instance initialized with the specified token.
 
 @param token The client token.
 @param delegate Delegate for token expiry and error notifications.
 */
+ (instancetype)accessManagerWithToken:(NSString *)token delegate:(id<TwilioAccessManagerDelegate>)delegate;

/**
 Updates the client token for consumers of this Access Manager instance.
 
 @param token The updated client token.
 */
- (void)updateToken:(NSString *)token;

/**
 Returns the current client token being used by this Access Manager instance.
 
 @return The current client token.
 */
- (NSString *)token;

/**
 Returns the identity associated with the current client token.
 
 @return The current client token's identity.
 */
- (NSString *)identity;

/**
 Determines whether the current client token is past its expiration time.
 
 @return BOOL indicting whether the current client token is expired.
 */
- (BOOL)isExpired;

/**
 Obtains the expiration date for the current client token.
 
 @return Expiration date for the current client token.
 */
- (NSDate *)expirationDate;

@end

/**
 Delegate to be notified events related to client tokens and this Access Manager.
 */
@protocol TwilioAccessManagerDelegate <NSObject>
/**
 Called when the associated client token has expired.
 
 @param accessManager The Access Manager whose token has expired.
 */
- (void)accessManagerTokenExpired:(TwilioAccessManager *)accessManager;

/**
 Called when the Access Manager encounters an error.
 
 @param accessManager The Access Manager
 @param error The error encountered
 */
- (void)accessManager:(TwilioAccessManager *)accessManager error:(NSError *)error;
@end
