cmake_minimum_required(VERSION 3.5)

project(GUI_Third_Laboratory VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LABA_PATH "../")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        StartUI.cpp 
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

include_directories(
"/home/goshagaina/Qwt/qwt-6.3.0/classincludes"
"/home/goshagaina/Qwt/qwt-6.3.0/src"
"${LABA_PATH}/Declaration/Dictionary"
"${LABA_PATH}/Declaration/Sequence"
"${LABA_PATH}/Declaration/Dictionary"
"${LABA_PATH}/Declaration/TypesOfData"
"${LABA_PATH}/Plot/Declaration"

)

#--------Library    TypesOfData
file(GLOB
                CPP_TYPES_OF_DATA "${LABA_PATH}/Definition/TypesOfData/*.cpp")

add_library(${PROJECT_NAME}_TypesOfData_lib   SHARED
                                    ${CPP_TYPES_OF_DATA})
include_directories(
    "${PROJECT_SOURCE_DIR}/Declaration/TypesOfData"
)
#-------End Library Types Of Data

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUI_Third_Laboratory APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

        add_library(GUI_Third_Laboratory SHARED
            ${PROJECT_SOURCES}
            enumclass.h enumclass.cpp
            uiclass.h uiclass.cpp syntaxhighlighter.h syntaxhighlighter.cpp directorytablemodel.h directorytablemodel.cpp ScrollZoomer.h ScrollZoomer.cpp mainwindow.ui mainwindow.h mainwindow.cpp StartUI.cpp enumclass.h enumclass.cpp CMakeLists.txt.user CMakeLists.txt
            memberofmodel.h memberofmodel.cpp
            getqstringfromnewwidget.h getqstringfromnewwidget.cpp
            ScrollZoomer.h ScrollZoomer.cpp ScrollBar.h ScrollBar.cpp
            gethashqstring.cpp
            gethashqstring.h
            checkqstring.cpp
            checkqstring.h
            checkqstringkey.h
            checkqstringkey.cpp
            ${LABA_PATH}/Plot/Declaration/realtimeplot.h

        )

target_link_libraries(GUI_Third_Laboratory PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GUI_Third_Laboratory)
endif()
set_target_properties(GUI_Third_Laboratory PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GUI_Third_Laboratory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI_Third_Laboratory)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
${PROJECT_NAME}_TypesOfData_lib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
                        #"${LABA_PATH}/Plot/build/libplot_lib.so"
                    "${PROJECT_SOURCE_DIR}/${LABA_PATH}/Plot/build/libplot_lib.so")

target_link_libraries(${PROJECT_NAME} PRIVATE
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0")
