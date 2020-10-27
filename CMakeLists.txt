cmake_minimum_required(VERSION 3.10)

# set the project name
project(plot_test_prj)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets Gui PrintSupport REQUIRED)
find_package(Boost 1.73.0)

# add the executable
add_executable(plot_test
	main.cc
    mainwindow.cpp
	mainwindow.ui
	resources.qrc
)

# Link getopt  ... attention dll is needed

find_path(GETOPT_INCLUDE_DIR getopt.h)
find_library(GETOPT_LIB getopt)
find_program(GETOPT_DLL getopt.dll)
include_directories(plot_test ${GETOPT_INCLUDE_DIR})
target_link_libraries(plot_test PUBLIC ${GETOPT_LIB} )

find_path(QCUSTOMPLOT_INCLUDE_DIR qcustomplot.h)

find_library(QCUSTOMPLOT_DEBUG_LIB qcustomplotd2.lib)
find_program(QCUSTOMPLOT_DEBUG_DLL qcustomplotd2.dll)
find_library(QCUSTOMPLOT_LIB qcustomplot2.lib)
find_program(QCUSTOMPLOT_DLL qcustomplot2.dll)
 

include_directories(plot_test ${QCUSTOMPLOT_INCLUDE_DIR})


target_link_libraries(plot_test PUBLIC debug ${QCUSTOMPLOT_DEBUG_LIB} )
target_link_libraries(plot_test PUBLIC optimized ${QCUSTOMPLOT_LIB} )


target_link_libraries(plot_test PUBLIC Qt5::Widgets)
target_link_libraries(plot_test PUBLIC Qt5::PrintSupport)

target_include_directories(plot_test PUBLIC ${Boost_INCLUDE_DIRS})

# Add include directory
target_include_directories(plot_test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/getopt"
                          ) 
