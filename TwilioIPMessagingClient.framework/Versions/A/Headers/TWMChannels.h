//
//  TWMChannels.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TWMConstants.h"

/** Representation of an IP Messaging channel list. */
@interface TWMChannels : NSObject

/** Requesting loading of all channels from server to be delivered via delegate callbacks.

 @param completion Completion block that will specify the result.
 */
- (void)loadChannelsWithCompletion:(TWMCompletion)completion;

/** Request a list of all channels loaded so far.  Will be an incomplete list until loading completes.
 
 @return The channels loaded so far.
 */
- (NSArray<TWMChannel *> *)allObjects;

/** Create a new channel with the specified friendly name.
 
 @param friendlyName Friendly name of the new channel.
 @param channelType Indicates whether or not a channel is public (TWMChannelTypePublic) or private (TWMChannelTypePrivate). Cannot be changed after channel creation.
 @param completion Completion block that will specify the result of the operation and a reference to the new channel.
 @deprecated Please use createChannelWithOptions:completion: instead.
 */
- (void)createChannelWithFriendlyName:(NSString *)friendlyName
                                 type:(TWMChannelType)channelType
                           completion:(TWMChannelCompletion)completion;

/** Create a new channel with the specified options.
 
 @param options Channel options for new channel whose keys are TWMChannelOption* constants. (optional - may be empty or nil)
 @param completion Completion block that will specify the result of the operation and a reference to the new channel.
 @discussion TWMChannelOptionFriendlyName - String friendly name (optional)
 @discussion TWMChannelOptionUniqueName - String unique name (optional)
 @discussion TWMChannelOptionType - Expected values are @(TWMChannelTypePublic) or @(TWMChannelTypePrivate) (optional)
 @discussion TWMChannelOptionAttributes - Expected value is an NSDictionary<NSString*,id> *, see also TWMChannel setAttributes:completion: (optional)
 */
- (void)createChannelWithOptions:(NSDictionary *)options
                      completion:(TWMChannelCompletion)completion;

/** Loads a channel with the specified id.
 
 @param channelId Identifier for the channel.
 @return The channel.
 */
- (TWMChannel *)channelWithId:(NSString *)channelId;

/** Loads a channel with the unique name.
 
 @param uniqueName Unique name for the channel.
 @return The channel.
 */
- (TWMChannel *)channelWithUniqueName:(NSString *)uniqueName;

@end
