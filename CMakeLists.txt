cmake_minimum_required(VERSION 2.8)

# ======================================================= #
#        <<Custom Information. Modify here>>

# Search for the cpp files in src/. Use the primary names only (without path and suffix, ex: use main for src/main.cpp).
set(exec_list HandGesture send_uinput receive_uinput test_main)  

set(module_list CmdLine CvRGBCamera VirtualInput ScreenTool Distribution Draw XMLTool)

set(usr_lib_list OpenCV OpenGL OpenMP X11)

# ======================================================= #
#              <<Basic Parameters>>

set(make_exec true)

# Set the compiler to gcc, mpich, intel, cuda...etc
set(compiler gcc)

# Custom variable: source directory for compiling executable files
set(main_src_path "${CMAKE_SOURCE_DIR}/src") 

# Custom variable: source directory of modules for libraries
set(module_path "${CMAKE_SOURCE_DIR}/modules") 

# CMake variable: directory of binary libraries
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib") 

# CMake variable: directory of executable files
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin") 

# Cmake variable: directory of cmake file for finding package or system libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/find.cmake") 

# Define OpenCV_LIBRARIES
set(libOpenCV OpenCV) 

# Define OPENCL_LIBRARIES
set(libOpenCL OPENCL) 

# Define OPENGL_LIBRARIES
set(libOpenGL OPENGL) 

# Define OPENMP_LIBRARIES
set(libOpenMP OPENMP) 

# Define CUDA_LIBRARIES
set(libCUDA CUDA)

# Define X11_LIBRARY
set(libX11 X11)

set(BUILD_SHARED_LIBS ON)

# ======================================================= #
#              <<Automatic Parameters>>

# ${PROJECT_NAME} = current_folder_name
get_filename_component(current_folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" current_folder_name ${current_folder_name})
project(${current_folder_name})

# Look for package (<Find<package>.cmake) in CMAKE_MODULE_PATH or in /usr/share/cmake-2.x/Modules/
foreach (usr_lib ${usr_lib_list})
# Find package in the system
    find_package(${usr_lib} REQUIRED)
    if (${lib${usr_lib}}_FOUND)
	    message(STATUS "Found ${usr_lib}: ${${lib${usr_lib}}_LIBRARIES}")
# Include system header file
        include_directories(SYSTEM ${${usr_lib}_INCLUDE_DIRS})
        set(global_link_list "${global_link_list};${${lib${usr_lib}}_LIBRARIES}")
    else (${lib${usr_lib}}_FOUND)
        message("${usr_lib} not found!")
    endif (${lib${usr_lib}}_FOUND)
endforeach (usr_lib)

# Look for modules in module_path
foreach (module ${module_list})
# Project include dirs
    include_directories("${module_path}/${module}/include")
# CMakeList.txt under subdirectories
    add_subdirectory("${module_path}/${module}")
endforeach (module)

# Compiler flags for gcc
if (${compiler} STREQUAL "gcc")
	set(CMAKE_C_COMPILER gcc)
	set(CMAKE_CXX_COMPILER g++)
	set(WARNINGS "-Wall -Wextra -Wunreachable-code -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wswitch-default -Wunused-parameter -Wreturn-type")
	set(NOWARNINGS "-Wno-parentheses -Wno-unused-function -Wno-unused-label -Wno-unused-result")
	set(CMAKE_CXX_FLAGS "-pipe ${WARNINGS} ${NOWARNINGS}")
	set(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif (${compiler} STREQUAL "gcc")

# Compiler flags for mpich
if (${compiler} STREQUAL "mpich")
	set(CMAKE_C_COMPILER mpicc)
	set(CMAKE_CXX_COMPILER mpicxx)
endif (${compiler} STREQUAL "mpich")

# Compiler flags for cuda
if (${compiler} STREQUAL "cuda")
	set(CMAKE_C_COMPILER nvcc)
	set(CMAKE_CXX_COMPILER nvcc)
endif (${compiler} STREQUAL "cuda")

# Compiler flags for intel
if (${compiler} STREQUAL "intel")
	set(CMAKE_C_COMPILER icc)
	set(CMAKE_CXX_COMPILER icc)
	set(CMAKE_CXX_FLAGS_RELEASE "-O3 -w")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif (${compiler} STREQUAL "intel")

# Set additional parameters if using OpenMP
if (${libOpenMP}_FOUND)
    message(STATUS "Setting OpenMP parameter")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif (${libOpenMP}_FOUND)

# Set additional parameters if using CUDA
if (${libCUDA}_FOUND)
	set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode arch=compute_20,code=sm_20)
#	cuda_compile(HELPER_O helper.cu)
#	cuda_compile(DRIVER_O driver.cu OPTIONS -G)
#	cuda_add_executable(driver ${HELPER_O} ${DRIVER_O})
endif (${libCUDA}_FOUND)

# ======================================================= #
#           <<Build executable program>>

if (make_exec)
	message(STATUS "Searching for the main src in " ${main_src_path})
	foreach (exec ${exec_list})
# Make executable targets
        message(STATUS "Making executable " ${exec})
        add_executable(${exec} "${main_src_path}/${exec}.cpp")
        target_link_libraries(${exec} ${global_link_list} ${module_list} ${OpenCV_LIB})
	endforeach (exec)
endif (make_exec)

message(STATUS "Executable file is in " ${EXECUTABLE_OUTPUT_PATH})
message(STATUS "Shared libraries are in " ${LIBRARY_OUTPUT_PATH})
