# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenCLTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenCLTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenCLTest.dir/flags.make

CMakeFiles/OpenCLTest.dir/main.cpp.o: CMakeFiles/OpenCLTest.dir/flags.make
CMakeFiles/OpenCLTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenCLTest.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenCLTest.dir/main.cpp.o -c /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/main.cpp

CMakeFiles/OpenCLTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCLTest.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/main.cpp > CMakeFiles/OpenCLTest.dir/main.cpp.i

CMakeFiles/OpenCLTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCLTest.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/main.cpp -o CMakeFiles/OpenCLTest.dir/main.cpp.s

CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o: CMakeFiles/OpenCLTest.dir/flags.make
CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o: ../LinearSample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o -c /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/LinearSample.cpp

CMakeFiles/OpenCLTest.dir/LinearSample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCLTest.dir/LinearSample.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/LinearSample.cpp > CMakeFiles/OpenCLTest.dir/LinearSample.cpp.i

CMakeFiles/OpenCLTest.dir/LinearSample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCLTest.dir/LinearSample.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/LinearSample.cpp -o CMakeFiles/OpenCLTest.dir/LinearSample.cpp.s

CMakeFiles/OpenCLTest.dir/CLSample.cpp.o: CMakeFiles/OpenCLTest.dir/flags.make
CMakeFiles/OpenCLTest.dir/CLSample.cpp.o: ../CLSample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenCLTest.dir/CLSample.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenCLTest.dir/CLSample.cpp.o -c /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/CLSample.cpp

CMakeFiles/OpenCLTest.dir/CLSample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCLTest.dir/CLSample.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/CLSample.cpp > CMakeFiles/OpenCLTest.dir/CLSample.cpp.i

CMakeFiles/OpenCLTest.dir/CLSample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCLTest.dir/CLSample.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/CLSample.cpp -o CMakeFiles/OpenCLTest.dir/CLSample.cpp.s

# Object files for target OpenCLTest
OpenCLTest_OBJECTS = \
"CMakeFiles/OpenCLTest.dir/main.cpp.o" \
"CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o" \
"CMakeFiles/OpenCLTest.dir/CLSample.cpp.o"

# External object files for target OpenCLTest
OpenCLTest_EXTERNAL_OBJECTS =

OpenCLTest: CMakeFiles/OpenCLTest.dir/main.cpp.o
OpenCLTest: CMakeFiles/OpenCLTest.dir/LinearSample.cpp.o
OpenCLTest: CMakeFiles/OpenCLTest.dir/CLSample.cpp.o
OpenCLTest: CMakeFiles/OpenCLTest.dir/build.make
OpenCLTest: CMakeFiles/OpenCLTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OpenCLTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenCLTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenCLTest.dir/build: OpenCLTest

.PHONY : CMakeFiles/OpenCLTest.dir/build

CMakeFiles/OpenCLTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenCLTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenCLTest.dir/clean

CMakeFiles/OpenCLTest.dir/depend:
	cd /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug /Users/hoshinohitoshi/develop/Clion_Workspace/OpenCLTest/cmake-build-debug/CMakeFiles/OpenCLTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenCLTest.dir/depend

