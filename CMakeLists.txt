cmake_minimum_required(VERSION 3.21)
project(compositorstatus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(KF5Notifications REQUIRED)
find_package(KF5ConfigWidgets REQUIRED)
find_package(KF5Config REQUIRED)
find_package(KF5Completion REQUIRED)
find_package(KF5IconThemes REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        DBus
        REQUIRED)

add_executable(compositorstatus main.cpp CompositorNotifier.cpp CompositorNotifier.h CompositorPrefs.h settings.cpp settings.h settings.ui CompositorPrefs.cpp)
target_link_libraries(compositorstatus
        Qt5::Core
        Qt5::Widgets
        Qt5::DBus
        KF5::Notifications
        KF5::ConfigGui
        KF5::Completion
        KF5::IconThemes
        )

