//
//  TWMMember.h
//  Twilio IP Messaging Client
//
//  Copyright (c) 2015 Twilio. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Representation of a Member on an IP Messaging channel. */
@interface TWMMember : NSObject

/** Returns the username.
 
 @return The username for this member.
 */
- (NSString *)identity;

@end
