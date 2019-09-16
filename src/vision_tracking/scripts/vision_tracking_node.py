#! /usr/bin/env python

import rospy
from vision_tracking.msg import Position

def vision_tracking_node():
    pub = rospy.Publisher('vision_position', Position)
    rospy.init_node('vision_tracking_node', anonymous=True)
    rate = rospy.Rate(10) #  10 Hz

    msg = Position()
    msg.position_x = 500
    msg.position_y = 500

    while not rospy.is_shutdown():
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        vision_tracking_node()
    except rospy.ROSInterruptException: pass
