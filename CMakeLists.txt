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

find_path(QCUSTOMPLOT_INCLUDE_DIR qcustomplot.h)
find_library(QCUSTOMPLOT_DEBUG_LIB qcustomplotd)
find_library(QCUSTOMPLOT_LIB qcustomplot)
 


include_directories(plot_test ${QCUSTOMPLOT_INCLUDE_DIR})
target_link_libraries(plot_test PUBLIC debug ${QCUSTOMPLOT_DEBUG_LIB} )
target_link_libraries(plot_test PUBLIC optimized ${QCUSTOMPLOT_LIB} )

find_path(LIB_NOISE_INCLUDE noise)
find_library(LIB_NOISE_LIB noise-static)
target_link_libraries(plot_test PUBLIC ${LIB_NOISE_LIB} )


target_link_libraries(plot_test PUBLIC Qt5::Widgets)
target_link_libraries(plot_test PUBLIC Qt5::PrintSupport)

target_include_directories(plot_test PUBLIC ${Boost_INCLUDE_DIRS})

find_package(cxxopts CONFIG REQUIRED)
target_link_libraries(plot_test PRIVATE cxxopts::cxxopts)


# Add include directory
target_include_directories(plot_test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/getopt"
                          ) 
