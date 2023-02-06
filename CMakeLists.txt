cmake_minimum_required(VERSION 3.11)
project(aisidi_2_tomczykowski_sekula_pon_8)

set(CMAKE_CXX_STANDARD 14)

include_directories(AVLTreeLib)
include_directories(benchmark)
include_directories(BinarySearchTreeLib)


add_library(AVLTreeLib AVLTreeLib/AVLTreeLib.h benchmark/benchmark.h)
add_library(BSTreeLib BinarySearchTreeLib/BinarySearchTree.h benchmark/benchmark.h)
set_target_properties(AVLTreeLib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(BSTreeLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(AVLTreeApp AVLTreeApp/AVLTreeApp.cpp)
target_link_libraries(AVLTreeApp AVLTreeLib)

add_executable(BinarySearchTreeApp  BinarySearchTreeApp/BinarySearchTreeApp.cpp)
target_link_libraries(BinarySearchTreeApp BSTreeLib)
#testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(BinarySearchTreeUnitTest BinarySearchTreeUnitTest/BinarySearchTreeUnitTest.cpp )
target_link_libraries(BinarySearchTreeUnitTest PUBLIC gtest_main BSTreeLib)

add_executable(AVLTreeUnitTest AVLTreeUnitTest/AVLTreeUnitTest.cpp )
target_link_libraries(AVLTreeUnitTest PUBLIC gtest_main AVLTreeLib)

include(GoogleTest)
gtest_discover_tests(AVLTreeUnitTest)
gtest_discover_tests(BinarySearchTreeUnitTest)