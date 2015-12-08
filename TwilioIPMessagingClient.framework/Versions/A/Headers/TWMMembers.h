//
//  TWMMembers.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TWMConstants.h"
#import "TWMMember.h"

/** Representation of an IP Messaging channel's membership list. */
@interface TWMMembers : NSObject

/** Obtain an array of members of this channel.
 
 @return An array of TWMMember objects representing the membership of the channel.
 */
- (NSArray<TWMMember *> *)allObjects;

/** Add specified username to this channel without inviting.
 
 @param identity The username to add to this channel.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)addByIdentity:(NSString *)identity
           completion:(TWMCompletion)completion;

/** Invite specified username to this channel.
 
 @param identity The username to invite to this channel.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)inviteByIdentity:(NSString *)identity
              completion:(TWMCompletion)completion;

/** Remove specified username from this channel.
 
 @param member The member to remove from this channel.
 @param completion Completion block that will specify the result of the operation.
 */
- (void)removeMember:(TWMMember *)member
          completion:(TWMCompletion)completion;

@end
