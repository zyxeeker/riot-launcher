cmake_minimum_required(VERSION 3.5)

project(launcher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets WebEngineWidgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        component/input.cpp component/input.h
        component/button.cpp component/button.h
        component/update.cpp component/update.h
        component/smooth_scroll_area.h component/smooth_scroll_area.cpp
        component/nav.cpp component/nav.h
        page/update_page.cpp page/update_page.h
        component/play_button.cpp component/play_button.h component/bk.cpp component/bk.h)

add_executable(launcher ${PROJECT_SOURCES} res.qrc)

target_link_libraries(launcher PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(launcher PRIVATE Qt${QT_VERSION_MAJOR}::WebEngineWidgets)


