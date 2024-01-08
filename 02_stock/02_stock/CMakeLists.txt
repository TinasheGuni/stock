cmake_minimum_required(VERSION 3.14)

project(02_stock LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_executable(02_stock
  main.cpp
  mainwindow.h mainwindow.cpp
  stocklist.h stocklist.cpp
  datadialog.h datadialog.cpp
  stock.h stock.cpp
  confectionery.h confectionery.cpp
  readingmaterial.h readingmaterial.cpp
  stockfactory.h stockfactory.cpp
)
target_link_libraries(02_stock PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS 02_stock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
