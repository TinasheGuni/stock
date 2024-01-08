cmake_minimum_required(VERSION 3.14)

project(question02_stock LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(question02_stock
  main.cpp
  stock.h stock.cpp
  confectionery.h confectionery.cpp
  readingmaterial.h readingmaterial.cpp
  stockfactory.h stockfactory.cpp
  stockwindow.h stockwindow.cpp
  abstractstockfactory.h abstractstockfactory.cpp
  stocklist.h stocklist.cpp
)
target_link_libraries(question02_stock PRIVATE
    Qt6::Core
    Qt6::Widgets
)

install(TARGETS question02_stock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
