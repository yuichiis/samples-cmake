cmake_minimum_required(VERSION 3.14)

project(test_greetings CXX)

## If you want to build the Release version, type the following command
## cmake -B build -DCMAKE_BUILD_TYPE=Release
#set(CMAKE_CONFIGURATION_TYPES Debug Release)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

if(CMAKE_BUILD_TYPE)
    message(STATUS "Start === '${CMAKE_BUILD_TYPE}' in tests ===.")
endif()

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_main
  test_main.cpp
)
target_link_libraries(
  test_main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# a.outという実行ファイルをmain.cppから作成
add_executable(a.out main.cpp)

# a.outを作成する際にlibgreetings.aをリンク
target_link_libraries(a.out greetings)
