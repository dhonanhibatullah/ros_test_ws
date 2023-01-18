/* ROS libraries */
#include "ros/ros.h"
#include "publisher_subscriber_example/RobotInfo.h"


/* C++ STL */
#include <cstdlib>


/* callback */
void info_callback(const publisher_subscriber_example::RobotInfo::ConstPtr& msg) {
    ROS_INFO(
        "\nenemy name:\n\t%s \nenemy IP:\n\t%s \nenemy status:\n\t%d \nenemy pose:\n\tx = %lf \n\ty = %lf \n\ttheta = %lf\n",
        msg->name.data.c_str(),
        msg->IP.data.c_str(),
        msg->status.data,
        msg->pos.x,
        msg->pos.y,
        msg->pos.theta
    );
}


/* robot class */
class Robot {

private:
    /* take nodehandler */
    ros::NodeHandle* nh;

    /* custom message */
    publisher_subscriber_example::RobotInfo msg;
    ros::Publisher info_publisher;
    ros::Subscriber info_subscriber;

public:
    /* constructor */
    Robot(ros::NodeHandle* nh_, std::string name, std::string IP) {
        // fill msg data
        msg.name.data   = name;
        msg.IP.data     = IP;
        msg.status.data = 0;
        msg.pos.x       = 0.0;
        msg.pos.y       = 0.0;
        msg.pos.theta   = 0.0;

        // take nodehandler address
        nh = nh_;
        info_publisher = nh->advertise<publisher_subscriber_example::RobotInfo>(name+"_info", 10);
        info_subscriber = nh->subscribe("OPTIMUS_info", 1000, info_callback);
    }

    /* method */
    void jump() {
        msg.pos.x       = ((double)rand())/((double)RAND_MAX)*10.0;
        msg.pos.y       = ((double)rand())/((double)RAND_MAX)*10.0;
        msg.pos.theta   = ((double)rand())/((double)RAND_MAX)*2.0*3.1415;
        msg.status.data = rand() % 5;
        info_publisher.publish(msg);
    }
};


/* main function */
int main(int argc, char **argv) {
    /* initialize ROS node */
    ros::init(argc, argv, "MEGATRON_node");
    ros::NodeHandle nh;
    Robot robot_a = Robot(&nh, "MEGATRON", "192.168.42.0");

    /* declare loop rate */
    ros::Rate loop_rate(30);

    /* loop */
    while (ros::ok()) {
        robot_a.jump();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}