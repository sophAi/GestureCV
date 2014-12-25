cmake_minimum_required(VERSION 2.8)

# ======================================================= #
#        <<Custom Information. Modify here>>

# Search for the cpp files in src/. Use the primary names only (without path and suffix, ex: use main for src/main.cpp).
set(exec_list ROI HandGesture tran send_uinput receive_uinput)  

set(module_list CmdLine CvRGBCamera VirtualInput ScreenTool Distribution Draw XMLTool)

set(usr_lib_list OpenCV OpenGL OpenCL OpenMP X11 GSL LibXml2 LibXslt)

# ======================================================= #
#              <<Basic Parameters>>

set(make_exec true)

# Set the compiler to gcc, mpich, intel, cuda...etc
set(compiler gcc)

# Custom variable: source directory for compiling executable files
set(src_path "${CMAKE_SOURCE_DIR}/src") 

# Custom variable: source directory of modules for libraries
set(module_path "${CMAKE_SOURCE_DIR}/modules") 

# CMake variable: directory of binary libraries
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib") 

# CMake variable: directory of executable files
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin") 

# Cmake variable: directory of cmake file for finding package or system libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/find.cmake") 

# Custom system libraries and headers translation
# set (lib{Name in usr_lib_list} {Name defined in {Name in usr_lib_list}.cmake})

# Define OpenCV_FOUND, OpenCV_LIBRARIES, and OpenCV_INCLUDE_DIRS.
set(libOpenCV OpenCV)   # Add "OpenCV" in usr_lib_list.

# Define OPENCL_FOUND and OPENCL_LIBRARIES. Add "OpenCL" in usr_lib_list.
set(libOpenCL OPENCL)    

# Define OPENGL_FOUND, OPENGL_LIBRARIES, and OPENGL_INCLUDE_DIR.
set(libOpenGL OPENGL)   # Add "OpenGL" in usr_lib_list.

# Define OPENMP_FOUND.
set(libOpenMP OPENMP)   # Add "OpenMP" in usr_lib_list. Note that it defines OpenMP_C_FLAGS and OpenMP_CXX_FLAGS

# Define CUDA_FOUND, CUDA_LIBRARIES, CUDA_INCLUDE_DIRS.
set(libCUDA CUDA)  # Add "CUDA" in usr_lib_list.

# Define X11_FOUND, X11_LIBRARIES, and X11_INCLUDE_DIR.
set(libX11 X11)    # Add "X11" in usr_lib_list.

# Define GSL_FOUND, GSL_LIBRARIES, and GSL_INCLUDE_DIR.
set(libGSL GSL)    # Add "GSL" in usr_lib_list.

# Define LIBXML2_FOUND, LIBXML2_LIBRARIES, and LIBXML2_INCLUDE_DIR.
set(libLibXml2 LIBXML2)  # Add "LibXml2" in usr_lib_list.

# Define LIBXSLT_FOUND, LIBXSLT_LIBRARIES, and LIBXSLT_INCLUDE_DIR.
set(libLibXslt LIBXSLT)  # Add "LibXslt" in usr_lib_list.

set(BUILD_SHARED_LIBS ON)

# ======================================================= #
#              <<Automatic Parameters>>

# ${PROJECT_NAME} = current_folder_name
get_filename_component(current_folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" current_folder_name ${current_folder_name})
project(${current_folder_name})
message("======== Start Building ========")
message(STATUS "Project: ${PROJECT_NAME}")
file(STRINGS "ChangeLog" ChangeLog LIMIT_INPUT 15)
message(STATUS "Version: ${ChangeLog}")
message(STATUS "Current directory: ${CMAKE_CURRENT_SOURCE_DIR}")

# Look for package (<Find<package>.cmake) in CMAKE_MODULE_PATH or in /usr/share/cmake-2.x/Modules/
message(" ")
message("======== Checking System Libraries ========")
foreach (usr_lib ${usr_lib_list})
# Find package in the system
	message("${usr_lib}:")
    find_package(${usr_lib} REQUIRED)
    if (${lib${usr_lib}}_FOUND)
# Add system libraries
		if (NOT "${${lib${usr_lib}}_LIBRARIES}" STREQUAL "")
			message(STATUS "LIBRARIES: ${${lib${usr_lib}}_LIBRARIES}")
		    set(global_link_list "${global_link_list};${${lib${usr_lib}}_LIBRARIES}")
		elseif (NOT "${${lib${usr_lib}}_LIBRARY}" STREQUAL "")
			message(STATUS "LIBRARY: ${${lib${usr_lib}}_LIBRARY}")
		    set(global_link_list "${global_link_list};${${lib${usr_lib}}_LIBRARY}")
		else ()
			message(STATUS "LIBRARIES or LIBRARY not defined!")
		endif ()
# Include system header file
		if (NOT "${${lib${usr_lib}}_INCLUDE_DIR}" STREQUAL "")
			message(STATUS "INCLUDE_DIR: ${${lib${usr_lib}}_INCLUDE_DIR}")
	        include_directories(SYSTEM ${${lib${usr_lib}}_INCLUDE_DIR})
		elseif (NOT "${${lib${usr_lib}}_INCLUDE_DIRS}" STREQUAL "")
			message(STATUS "INCLUDE_DIRS: ${${lib${usr_lib}}_INCLUDE_DIRS}")
	        include_directories(SYSTEM ${${lib${usr_lib}}_INCLUDE_DIRS})
		else ()
			message(STATUS "INCLUDE_DIRS or INCLUDE_DIR not defined!")
		endif ()
    else (${lib${usr_lib}}_FOUND)
        message("${usr_lib} not found!")
    endif (${lib${usr_lib}}_FOUND)
endforeach (usr_lib)

# Look for modules in module_path
message(" ")
message("======== Building modules ========")
foreach (module ${module_list})
# Project include dirs
	message("lib${module}:")
    include_directories("${module_path}/${module}/include")
# CMakeList.txt under subdirectories
    add_subdirectory("${module_path}/${module}")
endforeach (module)


# Compiler parameters
message(" ")
message("======== Setting Compiling Flags ========")
# Compiler flags for gcc
if (${compiler} STREQUAL "gcc")
    message(STATUS "Setting gcc parameter")
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
    message(STATUS "Setting mpich parameter")
	set(CMAKE_C_COMPILER mpicc)
	set(CMAKE_CXX_COMPILER mpicxx)
endif (${compiler} STREQUAL "mpich")

# Compiler flags for cuda
if (${compiler} STREQUAL "cuda")
    message(STATUS "Setting nvcc parameter")
	set(CMAKE_C_COMPILER nvcc)
	set(CMAKE_CXX_COMPILER nvcc)
endif (${compiler} STREQUAL "cuda")

# Compiler flags for intel
if (${compiler} STREQUAL "intel")
    message(STATUS "Setting icc parameter")
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
	message(" ")
	message("======== Making Executable Targets ========")
	message(STATUS "Searching for the main src in " ${src_path})
	foreach (exec ${exec_list})
# Make executable targets
        message(STATUS "Making executable " ${exec})
        add_executable(${exec} "${src_path}/${exec}.cpp")
        target_link_libraries(${exec} ${global_link_list} ${module_list} ${OpenCV_LIB})
	endforeach (exec)
endif (make_exec)

message(STATUS "Executable file is in " ${EXECUTABLE_OUTPUT_PATH})
message(STATUS "Shared libraries are in " ${LIBRARY_OUTPUT_PATH})

message(" ")
message("======== Build Summaries ========")
