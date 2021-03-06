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
include CMakeFiles/HandGesture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HandGesture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HandGesture.dir/flags.make

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o: CMakeFiles/HandGesture.dir/flags.make
CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o: ../src/HandGesture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o -c /home/xanadu/rsync_data/Programming/OpenCV/Machine/src/HandGesture.cpp

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HandGesture.dir/src/HandGesture.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xanadu/rsync_data/Programming/OpenCV/Machine/src/HandGesture.cpp > CMakeFiles/HandGesture.dir/src/HandGesture.cpp.i

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HandGesture.dir/src/HandGesture.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xanadu/rsync_data/Programming/OpenCV/Machine/src/HandGesture.cpp -o CMakeFiles/HandGesture.dir/src/HandGesture.cpp.s

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.requires:
.PHONY : CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.requires

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.provides: CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.requires
	$(MAKE) -f CMakeFiles/HandGesture.dir/build.make CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.provides.build
.PHONY : CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.provides

CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.provides.build: CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o

# Object files for target HandGesture
HandGesture_OBJECTS = \
"CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o"

# External object files for target HandGesture
HandGesture_EXTERNAL_OBJECTS =

../bin/HandGesture: CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o
../bin/HandGesture: CMakeFiles/HandGesture.dir/build.make
../bin/HandGesture: /usr/local/lib/libopencv_videostab.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_videoio.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_video.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_ts.a
../bin/HandGesture: /usr/local/lib/libopencv_superres.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_stitching.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_shape.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_photo.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_objdetect.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_ml.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_imgproc.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_highgui.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_flann.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_features2d.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_core.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_calib3d.so.3.0.0
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libSM.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libICE.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libXext.so
../bin/HandGesture: /usr/lib/libOpenCL.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libSM.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libICE.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libXext.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libxml2.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libxslt.so
../bin/HandGesture: ../lib/libCmdLine.so
../bin/HandGesture: ../lib/libCvRGBCamera.so
../bin/HandGesture: ../lib/libVirtualInput.so
../bin/HandGesture: ../lib/libScreenTool.so
../bin/HandGesture: ../lib/libDistribution.so
../bin/HandGesture: ../lib/libDraw.so
../bin/HandGesture: ../lib/libXMLTool.so
../bin/HandGesture: /usr/local/lib/libopencv_videostab.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_ts.a
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/HandGesture: /usr/local/lib/libopencv_superres.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_stitching.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_shape.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_video.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_photo.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_objdetect.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_calib3d.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_features2d.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_ml.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_highgui.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_videoio.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_imgproc.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_flann.so.3.0.0
../bin/HandGesture: /usr/local/lib/libopencv_core.so.3.0.0
../bin/HandGesture: /usr/lib/libOpenCL.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libSM.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libICE.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libXext.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libxml2.so
../bin/HandGesture: /usr/lib/x86_64-linux-gnu/libxslt.so
../bin/HandGesture: CMakeFiles/HandGesture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/HandGesture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HandGesture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HandGesture.dir/build: ../bin/HandGesture
.PHONY : CMakeFiles/HandGesture.dir/build

CMakeFiles/HandGesture.dir/requires: CMakeFiles/HandGesture.dir/src/HandGesture.cpp.o.requires
.PHONY : CMakeFiles/HandGesture.dir/requires

CMakeFiles/HandGesture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HandGesture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HandGesture.dir/clean

CMakeFiles/HandGesture.dir/depend:
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xanadu/rsync_data/Programming/OpenCV/Machine /home/xanadu/rsync_data/Programming/OpenCV/Machine /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/CMakeFiles/HandGesture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HandGesture.dir/depend

