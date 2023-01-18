#!/usr/bin/env python3
# the above comment is mandatory


# modules
import rospy
import numpy as np
import std_msgs.msg as msg


# declare ROS node
rospy.init_node('python_publisher_node', anonymous=False)


# define "main" function
def main():
    # declare the publisher object
    pub_str = rospy.Publisher('python_string_msg', msg.String, queue_size=1)
    pub_flt = rospy.Publisher('python_float_msg', msg.Float64, queue_size=1)
    
    # rate of loop, in this particular case 10 Hz
    rate = rospy.Rate(10)

    # loop
    while not rospy.is_shutdown():
        # send a string
        msg_str = "Hello, this is python_publisher_node"
        pub_str.publish(msg_str)

        # send a float
        msg_flt = np.pi
        pub_flt.publish(msg_flt)

        # give information through the console
        rospy.loginfo("Data have sent")
        
        # loop
        rate.sleep()


# main process
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException: 
        pass