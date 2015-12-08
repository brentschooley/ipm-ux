//
//  TWMChannel.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TWMConstants.h"

#import "TWMMessages.h"
#import "TWMMembers.h"

@class TwilioIPMessagingClient;
@protocol TWMChannelDelegate;

/** Representation of an IP Messaging channel. */
@interface TWMChannel : NSObject

/** Optional channel delegate */
@property (nonatomic, weak) id<TWMChannelDelegate> delegate;

/** The unique identifier for this channel. */
@property (nonatomic, copy, readonly) NSString *sid;

/** The friendly name for this channel. */
@property (nonatomic, copy, readonly) NSString *friendlyName;

/** The unique name for this channel. */
@property (nonatomic, copy, readonly) NSString *uniqueName;

/** The messages list object for this channel. */
@property (nonatomic, strong, readonly) TWMMessages *messages;

/** The members list object for this channel. */
@property (nonatomic, strong, readonly) TWMMembers *members;

/** The current user's status on this channel. */
@property (nonatomic, assign, readonly) TWMChannelStatus status;

/** The channel's visibility type. */
@property (nonatomic, assign, readonly) TWMChannelType type;

/** Return this channel's attributes.
 
 @return The developer-defined extensible attributes for this channel.
 */
- (NSDictionary<NSString *, id> *)attributes;

/** Set this channel's attributes.
 
 @param attributes The new developer-defined extensible attributes for this channel. (Supported types are NSString, NSNumber, NSArray, NSDictionary and NSNull)
 @param completion Completion block that will specify the result of the operation.
 */
- (void)setAttributes:(NSDictionary<NSString *, id> *)attributes
           completion:(TWMCompletion)completion;

/** Set this channel's friendly name.
 
 @param friendlyName The new friendly name for this channel.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)setFriendlyName:(NSString *)friendlyName
             completion:(TWMCompletion)completion;

/** Set this channel's unique name.
 
 @param uniqueName The new unique name for this channel.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)setUniqueName:(NSString *)uniqueName
           completion:(TWMCompletion)completion;

/** Join the current user to this channel.
 
 @param completion Completion block that will specify the result of the operation.
 */
- (void)joinWithCompletion:(TWMCompletion)completion;

/** Decline an invitation to this channel.
 
 @param completion Completion block that will specify the result of the operation.
 */
- (void)declineInvitationWithCompletion:(TWMCompletion)completion;

/** Leave the current channel.
 
 @param completion Completion block that will specify the result of the operation.
 */
- (void)leaveWithCompletion:(TWMCompletion)completion;

/** Destroy the current channel, removing all of its members.
 
 @param completion Completion block that will specify the result of the operation.
 */
- (void)destroyWithCompletion:(TWMCompletion)completion;

/** Indicates to other users and the backend that the user is typing a message to this channel. */
- (void)typing;

@end

/** This protocol declares the IP Messaging client delegate methods. */
@protocol TWMChannelDelegate <NSObject>
@optional
/** Called when this channel is changed.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelChanged:(TWMChannel *)channel;

/** Called when this channel is deleted.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelDeleted:(TWMChannel *)channel;

/** Called when one of the current users channels has fully loaded historical messages.
 
 @param client The IP Messaging client.
 @param channel The channel.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channelHistoryLoaded:(TWMChannel *)channel;

/** Called when this channel has a new member join.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberJoined:(TWMMember *)member;

/** Called when this channel has a member modified.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberChanged:(TWMMember *)member;

/** Called when this channel has a member leave.
 
 @param client The IP Messaging client.
 @param channel The channel.
 @param member The member.
 */
- (void)ipMessagingClient:(TwilioIPMessagingClient *)client channel:(TWMChannel *)channel memberLeft:(TWMMember *)member;

/** Called when this channel receives a new message.
 
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

@end
