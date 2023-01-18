/* ROS libraries */
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"


/* main function */
int main(int argc, char **argv) {
    /* initialize ROS node */
    ros::init(argc, argv, "cpp_publisher_node");
    ros::NodeHandle nh;

    /* initialize publisher objects */
    // we use queue_size = 10
    ros::Publisher pub_str = nh.advertise<std_msgs::String>("cpp_string_msg", 10);
    ros::Publisher pub_flt = nh.advertise<std_msgs::Float64>("cpp_float_msg", 10);

    /* message objects */
    std_msgs::String msg_str;
    std_msgs::Float64 msg_flt;

    /* declare loop rate */
    ros::Rate loop_rate(10);

    /* loop */
    while (ros::ok())
    {
        /* publish string */
        std::string str = "Hello, this is cpp_publisher_node";
        msg_str.data = str;
        pub_str.publish(msg_str);

        /* publish float */
        double flt = 2.71828182845905;
        msg_flt.data = flt;
        pub_flt.publish(msg_flt);

        /* give information through the terminal */
        ROS_INFO("Data have sent");

        /* repeat loop */
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}