cmake_minimum_required(VERSION 2.8.3)
project(gimbal_control)
find_package(catkin REQUIRED roscpp std_msgs vision_tracking)
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES i2c_bus
    CATKIN_DEPENDS roscpp
)
include_directories(include ${catkin_INCLUDE_DIRS})
add_library(i2c_bus src/i2c_bus.cpp)
target_link_libraries(i2c_bus &{catkin_LIBRARIES})
file(GLOB SOURCES "src/*.cpp")

add_executable(GimbalControlNode ${SOURCES})
