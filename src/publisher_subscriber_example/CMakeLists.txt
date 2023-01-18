cmake_minimum_required(VERSION 3.0.2)
project(publisher_subscriber_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pub_cpp_simple src/pub_cpp_simple.cpp)
target_link_libraries(pub_cpp_simple ${catkin_LIBRARIES})

add_executable(sub_cpp_simple src/sub_cpp_simple.cpp)
target_link_libraries(sub_cpp_simple ${catkin_LIBRARIES})