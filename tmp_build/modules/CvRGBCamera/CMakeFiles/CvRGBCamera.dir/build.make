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
include modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/depend.make

# Include the progress variables for this target.
include modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/progress.make

# Include the compile flags for this target's objects.
include modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/flags.make

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/flags.make
modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o: ../modules/CvRGBCamera/src/CvRGBCamera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o -c /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CvRGBCamera/src/CvRGBCamera.cpp

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.i"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CvRGBCamera/src/CvRGBCamera.cpp > CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.i

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.s"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CvRGBCamera/src/CvRGBCamera.cpp -o CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.s

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.requires:
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.requires

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.provides: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.requires
	$(MAKE) -f modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/build.make modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.provides.build
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.provides

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.provides.build: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o

# Object files for target CvRGBCamera
CvRGBCamera_OBJECTS = \
"CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o"

# External object files for target CvRGBCamera
CvRGBCamera_EXTERNAL_OBJECTS =

../lib/libCvRGBCamera.so: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o
../lib/libCvRGBCamera.so: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/build.make
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_videostab.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_videoio.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_video.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_ts.a
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_superres.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_stitching.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_shape.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_photo.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_objdetect.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_ml.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_imgproc.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_highgui.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_flann.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_features2d.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_core.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_calib3d.so.3.0.0
../lib/libCvRGBCamera.so: /usr/lib/libOpenCL.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libGLU.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libGL.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libSM.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libICE.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libX11.so
../lib/libCvRGBCamera.so: /usr/lib/x86_64-linux-gnu/libXext.so
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_features2d.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_ml.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_highgui.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_videoio.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_flann.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_video.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_imgproc.so.3.0.0
../lib/libCvRGBCamera.so: /usr/local/lib/libopencv_core.so.3.0.0
../lib/libCvRGBCamera.so: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../lib/libCvRGBCamera.so"
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CvRGBCamera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/build: ../lib/libCvRGBCamera.so
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/build

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/requires: modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/src/CvRGBCamera.cpp.o.requires
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/requires

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/clean:
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera && $(CMAKE_COMMAND) -P CMakeFiles/CvRGBCamera.dir/cmake_clean.cmake
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/clean

modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/depend:
	cd /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xanadu/rsync_data/Programming/OpenCV/Machine /home/xanadu/rsync_data/Programming/OpenCV/Machine/modules/CvRGBCamera /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera /home/xanadu/rsync_data/Programming/OpenCV/Machine/tmp_build/modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/CvRGBCamera/CMakeFiles/CvRGBCamera.dir/depend

