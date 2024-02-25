add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run StackTesting.cpp)
# linking Google_Tests_run with DateConverter_lib which will be tested

target_link_libraries(Google_Tests_run PRIVATE StackLibrary)

target_link_libraries(Google_Tests_run PRIVATE gtest gtest_main)

target_include_directories(Google_Tests_run PRIVATE "${PROJECT_SOURCE_DIR}/StackLib")