# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/hhoshino/develop/CLion_workspace/OpenMPTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenMPTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenMPTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenMPTest.dir/flags.make

CMakeFiles/OpenMPTest.dir/main.cpp.o: CMakeFiles/OpenMPTest.dir/flags.make
CMakeFiles/OpenMPTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenMPTest.dir/main.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenMPTest.dir/main.cpp.o -c /Users/hhoshino/develop/CLion_workspace/OpenMPTest/main.cpp

CMakeFiles/OpenMPTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenMPTest.dir/main.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhoshino/develop/CLion_workspace/OpenMPTest/main.cpp > CMakeFiles/OpenMPTest.dir/main.cpp.i

CMakeFiles/OpenMPTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenMPTest.dir/main.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhoshino/develop/CLion_workspace/OpenMPTest/main.cpp -o CMakeFiles/OpenMPTest.dir/main.cpp.s

CMakeFiles/OpenMPTest.dir/normal.cpp.o: CMakeFiles/OpenMPTest.dir/flags.make
CMakeFiles/OpenMPTest.dir/normal.cpp.o: ../normal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenMPTest.dir/normal.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenMPTest.dir/normal.cpp.o -c /Users/hhoshino/develop/CLion_workspace/OpenMPTest/normal.cpp

CMakeFiles/OpenMPTest.dir/normal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenMPTest.dir/normal.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhoshino/develop/CLion_workspace/OpenMPTest/normal.cpp > CMakeFiles/OpenMPTest.dir/normal.cpp.i

CMakeFiles/OpenMPTest.dir/normal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenMPTest.dir/normal.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhoshino/develop/CLion_workspace/OpenMPTest/normal.cpp -o CMakeFiles/OpenMPTest.dir/normal.cpp.s

CMakeFiles/OpenMPTest.dir/sorted.cpp.o: CMakeFiles/OpenMPTest.dir/flags.make
CMakeFiles/OpenMPTest.dir/sorted.cpp.o: ../sorted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenMPTest.dir/sorted.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenMPTest.dir/sorted.cpp.o -c /Users/hhoshino/develop/CLion_workspace/OpenMPTest/sorted.cpp

CMakeFiles/OpenMPTest.dir/sorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenMPTest.dir/sorted.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hhoshino/develop/CLion_workspace/OpenMPTest/sorted.cpp > CMakeFiles/OpenMPTest.dir/sorted.cpp.i

CMakeFiles/OpenMPTest.dir/sorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenMPTest.dir/sorted.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hhoshino/develop/CLion_workspace/OpenMPTest/sorted.cpp -o CMakeFiles/OpenMPTest.dir/sorted.cpp.s

# Object files for target OpenMPTest
OpenMPTest_OBJECTS = \
"CMakeFiles/OpenMPTest.dir/main.cpp.o" \
"CMakeFiles/OpenMPTest.dir/normal.cpp.o" \
"CMakeFiles/OpenMPTest.dir/sorted.cpp.o"

# External object files for target OpenMPTest
OpenMPTest_EXTERNAL_OBJECTS =

OpenMPTest: CMakeFiles/OpenMPTest.dir/main.cpp.o
OpenMPTest: CMakeFiles/OpenMPTest.dir/normal.cpp.o
OpenMPTest: CMakeFiles/OpenMPTest.dir/sorted.cpp.o
OpenMPTest: CMakeFiles/OpenMPTest.dir/build.make
OpenMPTest: CMakeFiles/OpenMPTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OpenMPTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenMPTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenMPTest.dir/build: OpenMPTest

.PHONY : CMakeFiles/OpenMPTest.dir/build

CMakeFiles/OpenMPTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenMPTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenMPTest.dir/clean

CMakeFiles/OpenMPTest.dir/depend:
	cd /Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hhoshino/develop/CLion_workspace/OpenMPTest /Users/hhoshino/develop/CLion_workspace/OpenMPTest /Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug /Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug /Users/hhoshino/develop/CLion_workspace/OpenMPTest/cmake-build-debug/CMakeFiles/OpenMPTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenMPTest.dir/depend

