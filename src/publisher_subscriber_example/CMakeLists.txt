cmake_minimum_required(VERSION 3.0.2)
project(publisher_subscriber_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

add_message_files(
  FILES
  RobotInfo.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(CATKIN_DEPENDS message_runtime)
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

# src/simple
add_executable(pub_cpp_simple src/simple/pub_cpp_simple.cpp)
target_link_libraries(pub_cpp_simple ${catkin_LIBRARIES})

add_executable(sub_cpp_simple src/simple/sub_cpp_simple.cpp)
target_link_libraries(sub_cpp_simple ${catkin_LIBRARIES})

# src/custom_message
add_executable(robot_A src/custom_message/robot_A.cpp)
add_dependencies(robot_A ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_A ${catkin_LIBRARIES})