cmake_minimum_required(VERSION 3.5)

project(QUARTO_GAME LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QUARTO_GAME main.cpp
    mainwindow.h
    quartowidget.h
    mainwindow.cpp
    quartowidget.cpp)

include(GNUInstallDirs)
install(TARGETS QUARTO_GAME
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
