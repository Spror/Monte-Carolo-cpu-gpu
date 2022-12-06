cmake_minimum_required(VERSION 3.5)

project(MonteCarlo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}  COMPONENTS PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}  COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}  REQUIRED COMPONENTS Gui)


set(SOURCES
        src/main.cpp
        src/mainwindow.cpp
        ui/mainwindow.ui
        src/qcustomplot.cpp
        src/MonteCarlo.cpp
        
)

set(HEADERS
	inc/qcustomplot.h
	inc/mainwindow.h
	inc/MonteCarlo.hpp
)

set(UIS
    ui/mainwindow.ui
)



add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIS})


target_link_libraries(MonteCarlo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MonteCarlo PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(MonteCarlo PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(MonteCarlo PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
