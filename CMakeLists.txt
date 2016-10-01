cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME matlab_from_cpp)

project(${PROJECT_NAME})

# List COMMAND
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")

set(MATLABROOT /Applications/MATLAB_R2016a.app/)

include_directories(/Applications/MATLAB_R2016a.app/extern/include/)
LINK_DIRECTORIES(/Applications/MATLAB_R2016a.app/bin/maci64/)

set(SRCS
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} libeng.dylib)
target_link_libraries(${PROJECT_NAME} libmx.dylib)
target_link_libraries(${PROJECT_NAME} libmat.dylib)