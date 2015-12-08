//
//  TWMMessage.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TWMConstants.h"

/** Representation of a Message on an IP Messaging channel. */
@interface TWMMessage : NSObject

/** The unique identifier for this message. */
@property (nonatomic, copy, readonly) NSString *sid;

/** The identity of the author of the message. */
@property (nonatomic, copy, readonly) NSString *author;

/** The body of the message. */
@property (nonatomic, copy, readonly) NSString *body;

/** The timestamp of the message. */
@property (nonatomic, copy, readonly) NSString *timestamp;

/** The timestamp the message was last updated. */
@property (nonatomic, copy, readonly) NSString *dateUpdated;

/** Who the the message was last updated by. */
@property (nonatomic, copy, readonly) NSString *lastUpdatedBy;

/** Update the body of this message
 
 @param body The new body for this message.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)updateBody:(NSString *)body completion:(TWMCompletion)completion;

@end
