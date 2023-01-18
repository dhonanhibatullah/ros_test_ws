/* ROS libraries */
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"


/* callback functions */
void subscriber_callback_string(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("String received : %s", msg->data.c_str());
}

void subscriber_callback_float(const std_msgs::Float64::ConstPtr& msg) {
    ROS_INFO("Float received : %lf", msg->data);
}


/* main function */
int main(int argc, char **argv) {
    /* initialize ROS node */
    ros::init(argc, argv, "cpp_subscriber_node");
    ros::NodeHandle nh;

    /* declare subscribers */
    ros::Subscriber py_sub_str  = nh.subscribe("python_string_msg", 1000, subscriber_callback_string);
    ros::Subscriber py_sub_flt  = nh.subscribe("python_float_msg", 1000, subscriber_callback_float);
    ros::Subscriber cpp_sub_str = nh.subscribe("cpp_string_msg", 1000, subscriber_callback_string);
    ros::Subscriber cpp_sub_flt = nh.subscribe("cpp_float_msg", 1000, subscriber_callback_float);

    /* spin callback */
    ros::spin();

    return 0;
}