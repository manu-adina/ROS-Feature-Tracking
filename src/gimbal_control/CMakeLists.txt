cmake_minimum_required(VERSION 2.8.3)
project(gimbal_control)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs vision_tracking)
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp
)
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(GimbalControlNode src/gimbal_communication_node.cpp src/i2c_bus.cpp)
add_library(i2c_bus src/i2c_bus.cpp)
target_link_libraries(GimbalControlNode i2c_bus ${catkin_LIBRARIES})

