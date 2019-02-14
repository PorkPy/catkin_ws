#!/usr/bin/env python
import numpy as np
import rospy
import math
import sys
import copy
import moveit_commander
import moveit_msgs
import scipy
from scipy.integrate import odeint
from scipy import signal
from sensor_msgs.msg import JointState
import moveit_msgs.msg
from geometry_msgs.msg import Pose
from rospy.numpy_msg import numpy_msg
#from std_msgs.msg import Floats
from std_msgs.msg import Float32
from std_msgs.msg import Bool
import std_msgs
import sys, time
import jsonlib
import message_filters
from std_msgs.msg import Int8
old_pose_np=np.zeros(7)

class RobotState:

    def __init__(self):
        global old_pose_np
        print 'initialisation!'
        rospy.init_node('irb120_node', anonymous=True)
        self._group_= moveit_commander.MoveGroupCommander("manipulator")
        self._robot_cmd_=  rospy.Subscriber('/irb120_node/move_cmd',Pose,self.callback)
        self._InMotion_=rospy.Publisher('/Robot/InMotion',Bool,queue_size=100)

        moveit_commander.roscpp_initialize(sys.argv)
        self._robot_= moveit_commander.RobotCommander()
        curPose=self._group_.get_current_pose()
        rate = rospy.Rate(100)

    def callback(self,_robot_cmd_):
        global old_pose_np
        #print 'In callback!'

        curPose=self._group_.get_current_pose()
        curPose_np=(np.array([curPose.pose.position.x,curPose.pose.position.y,curPose.pose.position.z,
        curPose.pose.orientation.x,curPose.pose.orientation.y,curPose.pose.orientation.z,
        curPose.pose.orientation.w]))

        if  not(np.all(np.isclose(curPose_np,old_pose_np,atol=1e-3))):
            old_pose_np=curPose_np

        poseCmd_np = np.array([_robot_cmd_.position.x,_robot_cmd_.position.y,_robot_cmd_.position.z,
                    _robot_cmd_.orientation.x,_robot_cmd_.orientation.y,_robot_cmd_.orientation.z,
                    _robot_cmd_.orientation.w])

        # print 'curPose: ',poseCmd_np
        # print 'oldCmd: ',old_pose_np
        robot_state = np.all(np.isclose(poseCmd_np,old_pose_np,atol=1e-3))
        # rospy.loginfo(hello_str)
        InMotionBool = Bool()
        InMotionBool.data = robot_state
        self._InMotion_.publish(InMotionBool)

        goalPose=_robot_cmd_
        print robot_state
        if not(robot_state):
            rospy.loginfo('Robot will move!')
            pose_target=_robot_cmd_
            self._group_.set_pose_target(pose_target)
            plan1 = self._group_.plan()
            self._group_.go(wait=True)
            old_pose_np = poseCmd_np
            #robot_state = np.all(np.isclose(curPose_np,old_pose_np,atol=1e-3))
            # rospy.loginfo(hello_str)
            InMotionBool = Bool()
            InMotionBool.data = robot_state
            self._InMotion_.publish(InMotionBool)




def main(args):
        #rospy.init_node('Robot_State', anonymous=True)
        #goal_pose=np.array([0.41, -0.031,s 0.4811, -0.65639, -0.000255309, 0.0002315,0.75442])
        #robotSpeed=10
        state=RobotState()
        try:
            rospy.spin()
        except rospy.ROSInterruptException:
            pass
if __name__ == '__main__':
    main(sys.argv)
