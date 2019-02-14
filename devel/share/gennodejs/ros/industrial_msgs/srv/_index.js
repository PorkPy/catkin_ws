
"use strict";

let StopMotion = require('./StopMotion.js')
let GetRobotInfo = require('./GetRobotInfo.js')
let SetRemoteLoggerLevel = require('./SetRemoteLoggerLevel.js')
let CmdJointTrajectory = require('./CmdJointTrajectory.js')
let SetDrivePower = require('./SetDrivePower.js')
let StartMotion = require('./StartMotion.js')

module.exports = {
  StopMotion: StopMotion,
  GetRobotInfo: GetRobotInfo,
  SetRemoteLoggerLevel: SetRemoteLoggerLevel,
  CmdJointTrajectory: CmdJointTrajectory,
  SetDrivePower: SetDrivePower,
  StartMotion: StartMotion,
};
