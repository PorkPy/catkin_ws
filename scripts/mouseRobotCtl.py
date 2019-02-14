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


_robot_cmd_= rospy.Publisher('/irb120_node/move_cmd',Pose,, queue_size=10)
#_robotState_=rospy.Publisher('/irb120_node/InMotion',Bool,, queue_size=10)
rospy.init_node('manipulator')
r = rospy.Rate(100) # 10hz
init_pose=np.array([0.41, -0.031, 0.481079, -0.63913, -0.000138344988, -0.00046901650,0.768946])
while not rospy.is_shutdown():
    a=Pose()
    a.position.x=init_pose[0]-2*1.3*1e-2#0.402712920007
    a.position.y=init_pose[1]-5.5*1e-2#0.0578272999832
    a.position.z=init_pose[2]#0.426780083575
    a.orientation.x=init_pose[3]#-0.635316088497
    a.orientation.y=init_pose[4]#0.00213182690848
    a.orientation.z=init_pose[5]#-0.0041159243829
    a.orientation.w=init_pose[6]#0.772238293649
    _robot_cmd_.publish(a)
    r.sleep()
