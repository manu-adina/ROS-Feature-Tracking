cmake_minimum_required(VERSION 2.8.3)
project(gimbal_control)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs vision_tracking)
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp
)
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(
    GimbalControlNode
    src/gimbal_communication_node.cpp
    src/i2c_bus.cpp
    src/PID.cpp
    src/gimbal_control.cpp
)

add_library(
    GimbalControlLib
    src/i2c_bus.cpp
    src/PID.cpp
    src/gimbal_control.cpp
)
target_link_libraries(GimbalControlNode GimbalControlLib ${catkin_LIBRARIES})

