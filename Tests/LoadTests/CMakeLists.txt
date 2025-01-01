cmake_minimum_required(VERSION 3.8)

project(loadTests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")

include_directories(
"${PROJECT_SOURCE_DIR}/../../Plot/Declaration"
"${PROJECT_SOURCE_DIR}/Declaration"
"${PROJECT_SOURCE_DIR}/../../Declaration/Dictionary"
"${PROJECT_SOURCE_DIR}/../../Declaration/Sequence"
)

include_directories(
    "/home/goshagaina/Qwt/qwt-6.3.0/classincludes"
    "/home/goshagaina/Qwt/qwt-6.3.0/src"
)

#----------------------------------------Create Libraries

#---------------Functions

include_directories(
    "${PROJECT_SOURCE_DIR}/../../Declaration/Functions"
)
file(GLOB Functions_Sources "${PROJECT_SOURCE_DIR}/../../Definition/Functions/*.cpp")
add_library(Functions_lib  SHARED
${Functions_Sources})
#--------------End Functions

#---------------GetHashCodes

include_directories(
    "${PROJECT_SOURCE_DIR}/../../Declaration/GetHashCodes"
)
file(GLOB GetHashCodes_Sources "${PROJECT_SOURCE_DIR}/../../Definition/GetHashCodes/*.cpp")
add_library(GetHashCodes_lib SHARED
${GetHashCodes_Sources})
#--------------End GetHashCodes

#---------------TypesOfData

include_directories(
    "${PROJECT_SOURCE_DIR}/../../Declaration/TypesOfData"
)
file(GLOB TypesOfData_Sources "${PROJECT_SOURCE_DIR}/../../Definition/TypesOfData/*.cpp")
add_library(TypesOfData_lib SHARED
${TypesOfData_Sources})
#--------------End TypesOfData

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/Definition/*.cpp")

find_package(Qt5 REQUIRED COMPONENTS Widgets Core)

add_library(${PROJECT_NAME} SHARED
${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
Qt5::Widgets)

target_link_libraries(${PROJECT_NAME} PRIVATE
"${PROJECT_SOURCE_DIR}/../../Plot/build/libplot_lib.so")

target_link_libraries(${PROJECT_NAME} PRIVATE
GetHashCodes_lib)

target_link_libraries(${PROJECT_NAME} PRIVATE
Functions_lib)

target_link_libraries(${PROJECT_NAME} PRIVATE
TypesOfData_lib)