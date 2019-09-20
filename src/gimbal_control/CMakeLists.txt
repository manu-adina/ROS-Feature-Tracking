cmake_minimum_required(VERSION 2.8.3)
project(gimbal_control)
find_package(catkin REQUIRED COMPONENTS roscpp vision_tracking)
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_MAME}
    CATKIN_DEPENDS roscpp
)
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(gimbal_control_node src/gimbal_control_node.cpp)

add_library(gimbal_control_lib src/gimbal_control.cpp src/i2c_bus.cpp src/pid.cpp)

target_link_libraries(
    gimbal_control_node
    gimbal_control_lib
    ${catkin_LIBRARIES}
)

