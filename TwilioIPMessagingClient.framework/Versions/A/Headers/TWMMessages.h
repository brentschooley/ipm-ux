//
//  TWMMessages.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TWMConstants.h"
#import "TWMMessage.h"

/** Representation of an IP Messaging channel's message list. */
@interface TWMMessages : NSObject

/** Creates a place-holder message which can be populated and sent with sendMessage:completion:

 @param body Body for new message.
 @return Place-holder TWMMessage instance
 */
- (TWMMessage *)createMessageWithBody:(NSString *)body;

/** Sends a message to the channel.
 
 @param message The message to send.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)sendMessage:(TWMMessage *)message
         completion:(TWMCompletion)completion;

/** Removes the specified message from the channel.
 
 @param message The message to remove.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)removeMessage:(TWMMessage *)message
           completion:(TWMCompletion)completion;

/** Returns messages received so far from backend, messages are loaded asynchronously so this may not fully represent all history available for channel.
 
 @return Messages received by IP Messaging Client so far for the given channel.
 */
- (NSArray<TWMMessage *> *)allObjects;

@end
