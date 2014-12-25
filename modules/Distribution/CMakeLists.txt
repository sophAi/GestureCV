cmake_minimum_required(VERSION 2.8)

# ======================================================= #
#        <<Custom Information. Modify here>>

# Add the libraries required by this module. Leave it blank will use the global_link_list, which may cause some dependency problem when migraing the programs.
# Options can be empty/none (default), global, or a list of libraries
set(module_usr_lib_list none)

#set(project_src
#"src/main.cpp"
#)

# ======================================================= #

# ${PROJECT_NAME} = current_folder_name
get_filename_component(current_folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" current_folder_name ${current_folder_name})
project(${current_folder_name})

# Search for the module source code in the subdirectory matching cpp or c code
file(GLOB_RECURSE project_src
    "*.cpp"
    "*.c"
)

# Prepare the linked libraries for lib${PROJECT_NAME}
list(GET module_usr_lib_list 0 first_module_lib)
if (${first_module_lib} STREQUAL "global")
	message(STATUS "Use global_link_list for lib${PROJECT_NAME}")
	set(module_link_list ${global_link_list})
elseif (${first_module_lib} STREQUAL "none")
	message(STATUS "Do not use other linked libraries for lib${PROJECT_NAME}")
else ()
	message(STATUS "Use module_link_list for lib${PROJECT_NAME}")
	foreach (module_usr_lib ${module_usr_lib_list})
#		find_package(${module_usr_lib}_REQUIRED)
		if (${lib${module_usr_lib}}_FOUND)
			message(STATUS "Linking ${module_usr_lib} to lib${PROJECT_NAME}")
# Add system libraries to this module
			if (NOT "${${lib${module_usr_lib}}_LIBRARIES}" STREQUAL "")
				message(STATUS "LIBRARIES: ${${lib${module_usr_lib}}_LIBRARIES}")
				set(module_link_list "${module_link_list};${${lib${module_usr_lib}}_LIBRARIES}")
			elseif (NOT "${${lib${module_usr_lib}}_LIBRARY}" STREQUAL "")
				message(STATUS "LIBRARY: ${${lib${module_usr_lib}}_LIBRARY}")
				set(module_link_list "${module_link_list};${${lib${module_usr_lib}}_LIBRARY}")
			else ()
				message(STATUS "LIBRARIES or LIBRARY not defined!")
			endif ()
# Include system header file to this module
			if (NOT "${${lib${module_usr_lib}}_INCLUDE_DIR}" STREQUAL "")
				message(STATUS "INCLUDE_DIR: ${${lib${module_usr_lib}}_INCLUDE_DIR}")
				include_directories(SYSTEM ${${lib${module_usr_lib}}_INCLUDE_DIR})
			elseif (NOT "${${lib${module_usr_lib}}_INCLUDE_DIRS}" STREQUAL "")
				message(STATUS "INCLUDE_DIRS: ${${lib${module_usr_lib}}_INCLUDE_DIRS}")
				include_directories(SYSTEM ${${lib${module_usr_lib}}_INCLUDE_DIRS})
			else ()
				message(STATUS "INCLUDE_DIRS or INCLUDE_DIR not defined!")
			endif ()
		else (${lib${module_usr_lib}}_FOUND)
			message("${module_usr_lib} not found!")
		endif (${lib${module_usr_lib}}_FOUND)
	endforeach (module_usr_lib)
endif ()

# Module include directory
include_directories(SYSTEM "${${PROJECT_NAME}_SOURCE_DIR}/include")

# Build shared library
add_library(${PROJECT_NAME} SHARED ${project_src})

# Build executive program
target_link_libraries(${PROJECT_NAME} ${module_link_list})

message(STATUS "Required libraries for lib${PROJECT_NAME}: ${module_link_list}")
