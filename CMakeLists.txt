cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
cmake_policy(SET CMP0097 NEW)

project(alfaresult VERSION 1.4.1 LANGUAGES C CXX)

add_library(alfaresult INTERFACE)

target_compile_features(alfaresult INTERFACE cxx_std_20)

target_include_directories(alfaresult INTERFACE
    incl
)

option(ALFARESULT_BUILD_TESTS "Build tests" OFF)

if(ALFARESULT_BUILD_TESTS)
    enable_testing()
    add_executable(alfaresult_test tests/main.cpp)
    target_link_libraries(alfaresult_test PRIVATE alfaresult)
    add_test(NAME alfaresult_test COMMAND alfaresult_test)
endif()
