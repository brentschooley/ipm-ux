//
//  ViewController.swift
//  IPMQuickstart
//
//  Created by Brent Schooley on 12/8/15.
//  Copyright © 2015 Twilio. All rights reserved.
//

import UIKit
import Alamofire
import SlackTextViewController

class ViewController: SLKTextViewController {
  // IP Messaging client instance - will create on initialization
  var client: TwilioIPMessagingClient? = nil
  // Handle to the default general channel
  var generalChannel: TWMChannel? = nil
  // Identity that was assigned to us by the server
  var identity = ""
  // A list of all the messages displayed in the UI
  var messages: [TWMMessage] = []
  
  // MARK: View Lifecycle
  override func viewDidLoad() {
    super.viewDidLoad()
    
    // Fetch Access Token form the server and initialize IPM Client - this assumes you are running
    // the PHP starter app on your local machine, as instructed in the quick start guide
    let url = "http://localhost:8000/token.php"
    let deviceId = UIDevice.currentDevice().identifierForVendor!.UUIDString
    let defaultChannel = "general"
    
    Alamofire.request(.GET, url, parameters: [
      "device": deviceId
      ]).responseJSON { response in
        if (response.result.isSuccess) {
          // Get token and identity assigned to us from server
          let json = JSON(response.result.value!)
          let token = json["token"].stringValue
          
          // Initialize view controller with new IP Messaging client and identity value
          self.identity = json["identity"].stringValue
          self.navigationItem.prompt = "Logged in as \"\(self.identity)\""
          self.navigationItem.title = "#general"
          self.client = TwilioIPMessagingClient.ipMessagingClientWithToken(token, delegate: self);
          
          // Auto-join the general channel
          self.client?.channelsListWithCompletion { result, channels in
            if (result == .Success) {
              if let channel = channels.channelWithUniqueName(defaultChannel) {
                // Join the general channel if it already exists
                self.generalChannel = channel
                self.joinChannel()
              } else {
                // Create the general channel (for public use) if it hasn't been created yet
                channels.createChannelWithFriendlyName("General Channel", type: .Public) {
                  (channelResult, channel) -> Void in
                  if result == .Success {
                    self.generalChannel = channel
                    self.joinChannelAndSetUniqueName(defaultChannel)
                  }
                }
              }
            }
          }
        } else {
          print("Error fetching Access Token from server - check the URL configuration above.")
        }
    }
    
    // Set up UI controls
    self.tableView.rowHeight = UITableViewAutomaticDimension
    self.tableView.estimatedRowHeight = 66.0
    self.tableView.separatorStyle = .None
  }
  
  // MARK: Setup IP Messaging Channel
  func joinChannel() {
    self.generalChannel?.joinWithCompletion() {
      (result) -> Void in
      if result == .Success {
        //self.channel?.delegate = self
        //self.loadMessages()
      }
    }
  }
  
  func joinChannelAndSetUniqueName(name: String) {
    self.generalChannel?.joinWithCompletion() { result in
      if result == .Success {
        self.generalChannel?.setUniqueName(name) { result in
          //self.channel?.delegate = self
          //self.loadMessages()
        }
      }
    }
  }
  
  func loadMessages() {
    self.messages.removeAll()
    let messages = self.generalChannel?.messages.allObjects()
    self.addMessages(messages!)
  }
  
  func addMessages(messages: [TWMMessage]) {
    self.messages.appendContentsOf(messages)
    self.messages.sortInPlace { $1.timestamp > $0.timestamp }
    
    dispatch_async(dispatch_get_main_queue()) {
      () -> Void in
      self.tableView.reloadData()
      if self.messages.count > 0 {
        self.scrollToBottomMessage()
      }
    }
  }
  
  // MARK: UI Logic
  // Scroll to bottom of table view for messages
  func scrollToBottomMessage() {
    if self.messages.count == 0 {
      return
    }
    let bottomMessageIndex = NSIndexPath(forRow: self.tableView.numberOfRowsInSection(0) - 1,
      inSection: 0)
    self.tableView.scrollToRowAtIndexPath(bottomMessageIndex, atScrollPosition: .Bottom,
      animated: true)
  }
  
  // MARK: UITableView Delegate
  // Return number of rows in the table
  override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    return self.messages.count
  }
  
  // Create table view rows
  override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath)
    -> UITableViewCell {
      let cell = tableView.dequeueReusableCellWithIdentifier("MessageCell", forIndexPath: indexPath)
      let message = self.messages[indexPath.row]
      
      // Set table cell values
      cell.detailTextLabel?.text = message.author
      cell.textLabel?.text = message.body
      cell.selectionStyle = .None
      return cell
  }
  
  // MARK: UITableViewDataSource Delegate
  override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
    return 1
  }
}

// MARK: Twilio IP Messaging Delegate
extension ViewController: TwilioIPMessagingClientDelegate {
  // Called whenever a channel we've joined receives a new message
  func ipMessagingClient(client: TwilioIPMessagingClient!, channel: TWMChannel!,
    messageAdded message: TWMMessage!) {
      self.addMessages([message])
  }
  
  func ipMessagingClient(client: TwilioIPMessagingClient!, channelHistoryLoaded channel: TWMChannel!) {
    self.loadMessages()
  }
}