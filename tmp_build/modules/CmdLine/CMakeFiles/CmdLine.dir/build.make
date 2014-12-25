# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/xanadu/rsync_data/Programming/OpenCV/Machine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build

# Include any dependencies generated for this target.
include modules/CmdLine/CMakeFiles/CmdLine.dir/depend.make

# Include the progress variables for this target.
include modules/CmdLine/CMakeFiles/CmdLine.dir/progress.make

# Include the compile flags for this target's objects.
include modules/CmdLine/CMakeFiles/CmdLine.dir/flags.make

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o: modules/CmdLine/CMakeFiles/CmdLine.dir/flags.make
modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o: ../modules/CmdLine/src/CmdLine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o -c /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CmdLine/src/CmdLine.cpp

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CmdLine.dir/src/CmdLine.cpp.i"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CmdLine/src/CmdLine.cpp > CMakeFiles/CmdLine.dir/src/CmdLine.cpp.i

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CmdLine.dir/src/CmdLine.cpp.s"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CmdLine/src/CmdLine.cpp -o CMakeFiles/CmdLine.dir/src/CmdLine.cpp.s

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.requires:
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.requires

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.provides: modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.requires
	$(MAKE) -f modules/CmdLine/CMakeFiles/CmdLine.dir/build.make modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.provides.build
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.provides

modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.provides.build: modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o

# Object files for target CmdLine
CmdLine_OBJECTS = \
"CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o"

# External object files for target CmdLine
CmdLine_EXTERNAL_OBJECTS =

../lib/libCmdLine.so: modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o
../lib/libCmdLine.so: modules/CmdLine/CMakeFiles/CmdLine.dir/build.make
../lib/libCmdLine.so: modules/CmdLine/CMakeFiles/CmdLine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../lib/libCmdLine.so"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CmdLine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/CmdLine/CMakeFiles/CmdLine.dir/build: ../lib/libCmdLine.so
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/build

modules/CmdLine/CMakeFiles/CmdLine.dir/requires: modules/CmdLine/CMakeFiles/CmdLine.dir/src/CmdLine.cpp.o.requires
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/requires

modules/CmdLine/CMakeFiles/CmdLine.dir/clean:
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine && $(CMAKE_COMMAND) -P CMakeFiles/CmdLine.dir/cmake_clean.cmake
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/clean

modules/CmdLine/CMakeFiles/CmdLine.dir/depend:
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xanadu/rsync_data/Programming/OpenCV/Machine /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CmdLine /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CmdLine/CMakeFiles/CmdLine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/CmdLine/CMakeFiles/CmdLine.dir/depend

