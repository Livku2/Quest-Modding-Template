cmake_minimum_required(VERSION 3.22.1)

project("questmoddingtemplate")

add_subdirectory(BNM-Android EXCLUDE_FROM_ALL)
get_property(BNM_INCLUDE_DIRECTORIES TARGET BNM PROPERTY BNM_INCLUDE_DIRECTORIES)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(kNO_KEYSTONE)
file(GLOB_RECURSE KITTY_MEMORY_SOURCES KittyMemory/KittyMemory/*.cpp)

macro(SET_OPTION option value)
    set(${option} ${value} CACHE INTERNAL "" FORCE)
endmacro()

SET_OPTION(DOBBY_GENERATE_SHARED OFF)
SET_OPTION(Plugin.SymbolResolver OFF)
add_subdirectory(Dobby)

add_library(${CMAKE_PROJECT_NAME} SHARED
        native-lib.cpp
        Utils/input.cpp
        ${KITTY_MEMORY_SOURCES})

link_libraries(${KEYSTONE_LIB})

target_include_directories(
        ${CMAKE_PROJECT_NAME}
        PUBLIC
        ${BNM_INCLUDE_DIRECTORIES}
        KittyMemory
        Dobby/include
        Utils
        BNMResolve)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        BNM
        log
        dobby)