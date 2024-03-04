cmake_minimum_required(VERSION 3.14)

project(ShopApplication LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Xml Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml Network)

add_executable(ShopApplication
    main.cpp
    mainwindow.cpp
    mainwindow.h
    treeitem.h treeitem.cpp
    treemodel.h treemodel.cpp
    item.h item.cpp
    transaction.h transaction.cpp
    customer.h customer.cpp
    customerlist.h customerlist.cpp
    itemlist.h itemlist.cpp
    additemdialog.h additemdialog.cpp
    addtransactiondialog.h addtransactiondialog.cpp
    itemlistbackup.h itemlistbackup.cpp
    xmlwriter.h xmlwriter.cpp
    udpsender.h udpsender.cpp
)
target_link_libraries(ShopApplication Qt${QT_VERSION_MAJOR}::Widgets Qt6::Xml Qt6::Network)

install(TARGETS ShopApplication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
