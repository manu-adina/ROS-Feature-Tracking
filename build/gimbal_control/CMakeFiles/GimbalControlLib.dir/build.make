# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/ROS-Feature-Tracking/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/ROS-Feature-Tracking/build

# Include any dependencies generated for this target.
include gimbal_control/CMakeFiles/GimbalControlLib.dir/depend.make

# Include the progress variables for this target.
include gimbal_control/CMakeFiles/GimbalControlLib.dir/progress.make

# Include the compile flags for this target's objects.
include gimbal_control/CMakeFiles/GimbalControlLib.dir/flags.make

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o: gimbal_control/CMakeFiles/GimbalControlLib.dir/flags.make
gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o: /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/gimbal_control.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/ROS-Feature-Tracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o -c /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/gimbal_control.cpp

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.i"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/gimbal_control.cpp > CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.i

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.s"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/gimbal_control.cpp -o CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.s

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o: gimbal_control/CMakeFiles/GimbalControlLib.dir/flags.make
gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o: /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/i2c_bus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/ROS-Feature-Tracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o -c /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/i2c_bus.cpp

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.i"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/i2c_bus.cpp > CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.i

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.s"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/i2c_bus.cpp -o CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.s

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o: gimbal_control/CMakeFiles/GimbalControlLib.dir/flags.make
gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o: /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/PID.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/ROS-Feature-Tracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o -c /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/PID.cpp

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GimbalControlLib.dir/src/PID.cpp.i"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/PID.cpp > CMakeFiles/GimbalControlLib.dir/src/PID.cpp.i

gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GimbalControlLib.dir/src/PID.cpp.s"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/ROS-Feature-Tracking/src/gimbal_control/src/PID.cpp -o CMakeFiles/GimbalControlLib.dir/src/PID.cpp.s

# Object files for target GimbalControlLib
GimbalControlLib_OBJECTS = \
"CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o" \
"CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o" \
"CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o"

# External object files for target GimbalControlLib
GimbalControlLib_EXTERNAL_OBJECTS =

/home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so: gimbal_control/CMakeFiles/GimbalControlLib.dir/src/gimbal_control.cpp.o
/home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so: gimbal_control/CMakeFiles/GimbalControlLib.dir/src/i2c_bus.cpp.o
/home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so: gimbal_control/CMakeFiles/GimbalControlLib.dir/src/PID.cpp.o
/home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so: gimbal_control/CMakeFiles/GimbalControlLib.dir/build.make
/home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so: gimbal_control/CMakeFiles/GimbalControlLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/ROS-Feature-Tracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library /home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so"
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GimbalControlLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gimbal_control/CMakeFiles/GimbalControlLib.dir/build: /home/pi/ROS-Feature-Tracking/devel/lib/libGimbalControlLib.so

.PHONY : gimbal_control/CMakeFiles/GimbalControlLib.dir/build

gimbal_control/CMakeFiles/GimbalControlLib.dir/clean:
	cd /home/pi/ROS-Feature-Tracking/build/gimbal_control && $(CMAKE_COMMAND) -P CMakeFiles/GimbalControlLib.dir/cmake_clean.cmake
.PHONY : gimbal_control/CMakeFiles/GimbalControlLib.dir/clean

gimbal_control/CMakeFiles/GimbalControlLib.dir/depend:
	cd /home/pi/ROS-Feature-Tracking/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/ROS-Feature-Tracking/src /home/pi/ROS-Feature-Tracking/src/gimbal_control /home/pi/ROS-Feature-Tracking/build /home/pi/ROS-Feature-Tracking/build/gimbal_control /home/pi/ROS-Feature-Tracking/build/gimbal_control/CMakeFiles/GimbalControlLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gimbal_control/CMakeFiles/GimbalControlLib.dir/depend

