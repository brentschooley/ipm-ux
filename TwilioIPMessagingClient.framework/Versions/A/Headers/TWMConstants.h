//
//  TWMConstants.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

@class TWMChannels;
@class TWMChannel;

/** Enumeration indicating the success or failure of the operation. */
typedef NS_ENUM(NSInteger, TWMResult) {
    TWMResultSuccess = 0,        ///< Operation succeeded.
    TWMResultFailure             ///< Operation failed.
};

/** Enumeration indicating the user's current status on a given channel. */
typedef NS_ENUM(NSInteger, TWMChannelStatus) {
    TWMChannelStatusInvited = 0,        ///< User is invited to the channel but not joined.
    TWMChannelStatusJoined,             ///< User is joined to the channel.
    TWMChannelStatusNotParticipating    ///< User is not participating on this channel.
};

/** Enumeration indicating the channel's visibility. */
typedef NS_ENUM(NSInteger, TWMChannelType) {
    TWMChannelTypePublic = 0,        ///< Channel is publicly visible
    TWMChannelTypePrivate            ///< Channel is private and only visible to invited members.
};

/** Completion block which will indicate the TWMResult of the operation. */
typedef void (^TWMCompletion)(TWMResult result);

/** Completion block which will indicate the TWMResult of the operation and a channels object. */
typedef void (^TWMChannelListCompletion)(TWMResult result, TWMChannels *channelsList);

/** Completion block which will indicate the TWMResult of the operation and a channel. */
typedef void (^TWMChannelCompletion)(TWMResult result, TWMChannel *channel);

/** Channel creation options key for setting friendly name. */
FOUNDATION_EXPORT NSString *const TWMChannelOptionFriendlyName;

/** Channel creation options key for setting unqiue name. */
FOUNDATION_EXPORT NSString *const TWMChannelOptionUniqueName;

/** Channel creation options key for setting type.  Expected values are @(TWMChannelTypePublic) or @(TWMChannelTypePrivate) */
FOUNDATION_EXPORT NSString *const TWMChannelOptionType;

/** Channel creation options key for setting attributes.  Expected value is an NSDictionary* */
FOUNDATION_EXPORT NSString *const TWMChannelOptionAttributes;
