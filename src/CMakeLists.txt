# cmakeのバージョン
cmake_minimum_required(VERSION 3.13)

# プロジェクト名指定
project(greetings CXX)

#set(default_build_type "Release")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if(NOT CMAKE_BUILD_TYPE)
#  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
#  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
#      STRING "Choose the type of build." FORCE)
#endif()

if(CMAKE_BUILD_TYPE)
    message(STATUS "Start === '${CMAKE_BUILD_TYPE}' in src ===.")
endif()

#if(MSVC)
#    add_definitions(/MP)
#endif()

## If you want to build the Release version, type the following command
##set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# srcフォルダー以下のcppファイル一覧をcppfilesという変数に格納
file(GLOB_RECURSE cppfiles RELATIVE ${PROJECT_SOURCE_DIR} ./*.cpp)

# dllでビルドすると指定
add_library(greetings SHARED ${cppfiles})

# c++11
#target_compile_features(greetings PRIVATE cxx_std_11)

# include ディレクトリ指定
##target_include_directories(greetings INTERFACE ../include)
target_include_directories(greetings PUBLIC ../include)
