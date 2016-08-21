cmake_minimum_required(VERSION 3.3)
project(tbe-qml-toolbox-spike)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt5 COMPONENTS Quick Core Svg Widgets Xml)

set(SRC_LIST main.cpp ImageProvider.cpp)
qt5_add_resources(RESOURCES views.qrc)
add_executable(tbe-qml-toolbox-spike ${SRC_LIST} ${RESOURCES})

qt5_use_modules(tbe-qml-toolbox-spike Quick Core Svg Xml Widgets)
