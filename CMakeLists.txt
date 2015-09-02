cmake_minimum_required(VERSION 2.8)

project(connect4 C CXX)

# Executable name
set(exe_name connect4)

# Set the source directory
set(CONNECT4_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Set the include directory
set(CONNECT4_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# append "d" after libraries that are generated
set(CMAKE_DEBUG_POSTFIX d)

# set the directories in which exe's and libraries (shared and static) are generated
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/${PLATFORM})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/${PLATFORM})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${PLATFORM})

# unix only options (ie mac and linux but not windows)
# These options will make it so that there are no optimizations when compiling for debug
# That way your debugger wont weirdly skip lines or anything like that
if (UNIX)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -fms-extensions")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -fms-extensions")
endif()

# Use c++ 11
add_definitions(-std=c++11)

# Set the src files for the project
file(GLOB SRC_FILES "${CONNECT4_SRC_DIR}/*.c*")
file(GLOB HEADER_FILES "${CONNECT4_INCLUDE_DIR}/*.h*")

# Set project includes dir
include_directories("${CONNECT4_INCLUDE_DIR}")

# Adding executable
add_executable(${exe_name} ${SRC_FILES} ${HEADER_FILES})

# Append "d" after exe names with debug info
set_target_properties(${exe_name} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
