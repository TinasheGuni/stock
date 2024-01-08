cmake_minimum_required(VERSION 3.14)

project(question_03_stock_xml LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_executable(question_03_stock_xml
  main.cpp
  abstractstockfactory.h abstractstockfactory.cpp
  confectionery.h confectionery.cpp
  filewriter.h filewriter.cpp
  readingmaterial.h readingmaterial.cpp
  stock.h stock.cpp
  stockfactory.h stockfactory.cpp
  stocklist.h stocklist.cpp
  stockwindow.h stockwindow.cpp
)
target_link_libraries(question_03_stock_xml PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

install(TARGETS question_03_stock_xml
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
