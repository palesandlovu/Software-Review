cmake_minimum_required(VERSION 3.14)

project(Question_1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


add_executable(Question_1
  main.cpp
  mainwindow.h mainwindow.cpp
  softwarelist.h softwarelist.cpp
  softwarereview.h softwarereview.cpp

)
target_link_libraries(Question_1 Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Question_1 Qt${QT_VERSION_MAJOR}::Widgets)


include(GNUInstallDirs)
install(TARGETS Question_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
