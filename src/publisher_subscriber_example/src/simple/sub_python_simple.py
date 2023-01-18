#!/usr/bin/env python3
# the above comment is mandatory


# modules
import rospy
import std_msgs.msg as msg


# declare ROS node
rospy.init_node('python_subscriber_node', anonymous=False)


# callback functions
def subscriber_callback_string(data):
    # print on console
    rospy.loginfo("String received : %s", data.data)

def subscriber_callback_float(data):
    # print on console
    rospy.loginfo("Float received : %lf", data.data)


# main function    
def main():
    # declare subscribers
    rospy.Subscriber("python_string_msg", msg.String, subscriber_callback_string)
    rospy.Subscriber("python_float_msg", msg.Float64, subscriber_callback_float)
    rospy.Subscriber("cpp_string_msg", msg.String, subscriber_callback_string)
    rospy.Subscriber("cpp_float_msg", msg.Float64, subscriber_callback_float)

    # spin callback
    rospy.spin()


# main process
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException: 
        pass