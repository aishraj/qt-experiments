project(headerViewer)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${QT_MODULES} ${QT_INCLUDE_DIR})

set(headerViewer_SRCS headerViewer.cpp main.cpp)
qt4_automoc(${headerViewer_SRCS})
add_executable(headerViewer ${headerViewer_SRCS})
target_link_libraries(headerViewer ${QT_QTCORE_LIBRARY} ${QT_QT_LIBRARY} ${QT_QTNETWORK_LIBRARY})
