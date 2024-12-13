cmake_minimum_required(VERSION 3.5)

project(Dictionary VERSION 1 LANGUAGES CXX)

#--------------------------------- Set Flags

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17 )

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")

#--------------------------------- End Set Flags

#--------------------------------- Find Packages

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#--------------------------------- End Find Packages

include_directories(

#"/home/goshagaina/Qwt/qwt-6.3.0/classincludes" #Замените на свой путь!
#"/home/goshagaina/Qwt/qwt-6.3.0/src"

"${PROJECT_SOURCE_DIR}/Declaration/Sequence"
"${PROJECT_SOURCE_DIR}/Declaration/Dictionary"
"${PROJECT_SOURCE_DIR}/Declaration/GetHashCodes"
"${PROJECT_SOURCE_DIR}/Tests"
"${PROJECT_SOURCE_DIR}/Tests/LoadTests/Declaration"
)
#------------------------------------Create Libraries

#--------Library    TypesOfData 
file(GLOB
                CPP_TYPES_OF_DATA "${PROJECT_SOURCE_DIR}/Definition/TypesOfData/*.cpp")

add_library(${PROJECT_NAME}_TypesOfData_lib   SHARED
                                    ${CPP_TYPES_OF_DATA})
include_directories(
    "${PROJECT_SOURCE_DIR}/Declaration/TypesOfData"
)
#-------End Library Types Of Data

#--------Library    Functions 
file(GLOB
                CPP_FUNCTONS "${PROJECT_SOURCE_DIR}/Definition/Functions/*.cpp")

add_library(${PROJECT_NAME}_Functions_lib   SHARED
                                    ${CPP_FUNCTONS})
include_directories(
    "${PROJECT_SOURCE_DIR}/Declaration/Functions"
)

#-------End Library Functions

#--------Library    GetHashCodes 
file(GLOB
                CPP_GetHashCodes "${PROJECT_SOURCE_DIR}/Definition/GetHashCodes/*.cpp")

add_library(${PROJECT_NAME}_GetHashCodes_lib   SHARED
                                    ${CPP_GetHashCodes})
include_directories(
    "${PROJECT_SOURCE_DIR}/Declaration/GetHashCodes"
)

#-------End Library GetHashCodes

#--------Library    UnitTests 
file(GLOB
                CPP_UnitTests "${PROJECT_SOURCE_DIR}/Tests/UnitTests/Definition/*.cpp")

add_library(${PROJECT_NAME}_UnitTests_lib   SHARED
                                    ${CPP_UnitTests})
include_directories(
    "${PROJECT_SOURCE_DIR}/Tests/UnitTests/Declaration"
)

#-------End Library UnitTests

#----------------------------------------- End Create Libraries

file(GLOB CPP_SOURCES "${PROJECT_SOURCE_DIR}/Definition/*.cpp")

add_executable(${PROJECT_NAME}  ${CPP_SOURCES})


#----------------------------------------------Link Libraries
target_link_libraries(${PROJECT_NAME}
                                        ${PROJECT_NAME}_TypesOfData_lib

)  

#target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)


#target_link_libraries(${PROJECT_NAME}
#                                        "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0") #Замените на свой путь

                                         
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_Functions_lib)


target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_GetHashCodes_lib )


target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_UnitTests_lib )

target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/Tests/LoadTests/build/libloadTests.so")