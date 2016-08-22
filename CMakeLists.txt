cmake_minimum_required(VERSION 3.3)
project(tbe-qml-toolbox-spike)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt5 COMPONENTS Quick Core Svg Widgets Xml)

# to make the QML files appear in Qt Creator in a nice fashion
FILE(GLOB QML_SRC "*.qml" "gui/*.qml" "gui/*.js" "README.md")

set(SRC_LIST main.cpp ImageProvider.cpp gui/ToolboxGroup.cpp)
qt5_add_resources(RESOURCES main.qrc gui/gui.qrc)
add_executable(tbe-qml-toolbox-spike ${SRC_LIST} ${RESOURCES})
ADD_CUSTOM_TARGET(be-qml-toolbox-spike SOURCES ${QML_SRC})

qt5_use_modules(tbe-qml-toolbox-spike Quick Core Svg Xml Widgets)
