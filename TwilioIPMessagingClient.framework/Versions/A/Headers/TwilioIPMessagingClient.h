//
//  TwilioIPMessagingClient.h
//  Twilio IP Messaging Client
//
//  Copyright © 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <TwilioCommon/TwilioCommon.h>

#import "TWMConstants.h"
#import "TWMError.h"
#import "TWMChannels.h"
#import "TWMChannel.h"
#import "TWMMessages.h"
#import "TWMMessage.h"
#import "TWMMember.h"

@protocol TwilioIPMessagingClientDelegate;

/** Represents an IP Messaging client connection to Twilio. */
@interface TwilioIPMessagingClient : NSObject

/** Access manager to use with this client. */
@property (nonatomic, strong) TwilioAccessManager *accessManager;

/** Messaging client delegate */
@property (nonatomic, weak) id<TwilioIPMessagingClientDelegate> delegate;

/** The unique identity identifier of this user in the IP Messaging system. */
@property (nonatomic, copy, readonly) NSString *identity;

/** Initialize a new IP Messaging client instance with a token.
 
 @param token The authentication token for the user.
 @param delegate Delegate conforming to TwilioIPMessagingClientDelegate for IP Messaging client lifecycle notifications.
 @return New IP Messaging client instance.
 @deprecated Please use ipMessagingClientWithAccessManager:delegate: instead.
 */
+ (TwilioIPMessagingClient *)ipMessagingClientWithToken:(NSString *)token
                                               delegate:(id<TwilioIPMessagingClientDelegate>)delegate;

/** Initialize a new IP Messaging client instance with a token manager.
 
 @param accessManager Instance of TwilioAccessManager.
 @param delegate Delegate conforming to TwilioIPMessagingClientDelegate for IP Messaging client lifecycle notifications.
 @return New IP Messaging client instance.
 */
+ (TwilioIPMessagingClient *)ipMessagingClientWithAccessManager:(TwilioAccessManager *)accessManager
                                                       delegate:(id<TwilioIPMessagingClientDelegate>)delegate;

/** Returns the version of the SDK
 
 @return The IP Messaging client version.
 */
- (NSString *)version;

/** List of channels available to the current user.
 
 @param completion Completion block that will specify the result of the operation and a list of channels visible to the current user.
 */
- (void)channelsListWithCompletion:(TWMChannelListCompletion)completion;

/** Register APNS token for push notification updates.
 
 @param token The APNS token which usually comes from 'didRegisterForRemoteNotificationsWithDeviceToken'.
 */
- (void)registerWithToken:(NSData *)token;

/** De-register from push notification updates.
 
 @param token The APNS token which usually comes from 'didRegisterForRemoteNotificationsWithDeviceToken'.
 */
- (void)deregisterWithToken:(NSData *)token;

/** Queue the incoming notification with the messaging library for processing - notifications usually arrive from 'didReceiveRemoteNotification'.
 
 @param notification The incomming notification.
 */
- (void)handleNotification:(NSDictionary *)notification;

/** Cleanly shut down the messaging subsystem when you are done with it. */
- (void)shutdown;

@end

#pragma mark -

/** This protocol declares the IP Messaging client delegate methods. */
@protocol TwilioIPMessagingClientDelegate <NSObject>
@optional

/** Called when the current user has a channel added to their channel list.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelAdded:(TWMChannel *)channel;

/** Called when one of the current users channels is changed.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelChanged:(TWMChannel *)channel;

/** Called when one of the current users channels is deleted.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelDeleted:(TWMChannel *)channel;

/** Called when one of the current users channels has fully loaded historical messages.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelHistoryLoaded:(TWMChannel *)channel;

/** Called when a channel the current user is subscribed to has a new member join.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberJoined:(TWMMember *)member;

/** Called when a channel the current user is subscribed to has a member modified.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberChanged:(TWMMember *)member;

/** Called when a channel the current user is subscribed to has a member leave.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberLeft:(TWMMember *)member;

/** Called when a channel the current user is subscribed to receives a new message.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param message The message.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel messageAdded:(TWMMessage *)message;

/** Called when a message on a channel the current user is subscribed to is modified.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param message The message.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel messageChanged:(TWMMessage *)message;

/** Called when a message on a channel the current user is subscribed to is deleted.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param message The message.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel messageDeleted:(TWMMessage *)message;

/** Called when an error occurs.
 
 @param client The IP Messaging client.
 @param error The error.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client errorReceived:(TWMError *)error;

/** Called when a member of a channel starts typing.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client typingStartedOnChannel:(TWMChannel *)channel member:(TWMMember *)member;

/** Called when a member of a channel ends typing.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client typingEndedOnChannel:(TWMChannel *)channel member:(TWMMember *)member;

/** Called when you are successfully registered for push notifications. 
 
 @param client The IP Messaging client.
 */
- (void)ipMessagingClientToastSubscribed:(TwilioIPMessagingClient *)client;

/** Called when you are successfully registered for push notifications.
 
 @param client The IP Messaging client.
 @param channel The channel for the push notification.
 @param message The message for the push notification.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client toastReceivedOnChannel:(TWMChannel *)channel message:(TWMMessage *)message;

/** Called when registering for push notifications fails.
 
 @param client The IP Messaging client.
 @param error An error indicating the failure.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client toastRegistrationFailedWithError:(TWMError *)error;

@end
