cmake_minimum_required(VERSION 3.10)
project(StringCalculator)

set(CMAKE_CXX_STANDARD 17)

# Add the GoogleTest repository if it's a submodule
add_subdirectory(external/googletest)

# Define the main library
add_library(StringCalculator src/StringCalculator.cpp)
target_include_directories(StringCalculator PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Define the test executable
add_executable(StringCalculatorTest test/StringCalculatorTest.cpp)

# Link the test executable with GoogleTest and the main library
target_link_libraries(StringCalculatorTest gtest gtest_main StringCalculator)

# Add test to CTest
enable_testing()
add_test(NAME StringCalculatorTests COMMAND StringCalculatorTest)