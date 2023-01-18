#!/usr/bin/env python3
# the above comment is mandatory


# modules
import rospy
import numpy as np
from publisher_subscriber_example.msg import RobotInfo


# callback
def info_callback(data):
    rospy.loginfo(
        "\nenemy name:\n\t%s \nenemy IP:\n\t%s \nenemy status:\n\t%d \nenemy pose:\n\tx = %lf \n\ty = %lf \n\ttheta = %lf\n",
        data.name.data,
        data.IP.data,
        data.status.data,
        data.pos.x,
        data.pos.y,
        data.pos.theta
    )


# robot object
class Robot:

    def __init__(self, name, IP) -> None:
        # robot information
        self.msg             = RobotInfo()
        self.msg.name.data   = name
        self.msg.IP.data     = IP
        self.msg.status.data = 0

        # robot message
        self.info_publisher = rospy.Publisher(self.msg.name.data+'_info', RobotInfo, queue_size=10)

    def jump(self) -> None:
        self.msg.pos.x       = np.random.rand()*10
        self.msg.pos.y       = np.random.rand()*10
        self.msg.pos.theta   = np.random.rand()*2*np.pi
        self.msg.status.data = np.random.randint(low=0, high=5)
        self.info_publisher.publish(self.msg)


# initialize object
robot_b = Robot("OPTIMUS", "192.168.0.69")
rospy.init_node(robot_b.msg.name.data+'_node', anonymous=False)


# main function
def main(robot):
    rospy.Subscriber("MEGATRON_info", RobotInfo, info_callback)
    rate = rospy.Rate(30)
    while not rospy.is_shutdown():
        robot.jump()
        rate.sleep()


# main process
if __name__ == '__main__':
    try:
        main(robot_b)
    except rospy.ROSInterruptException: 
        pass