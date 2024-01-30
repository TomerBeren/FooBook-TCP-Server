cmake_minimum_required(VERSION 3.14)

project("AdvancedProgProject") # Replace “MyCalc” with your repo name

  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)

  include(FetchContent)
    FetchContent_Declare(
      googletest URL
      https://github.com/google/googletest/archive/03597a01ee50ed
      33e9dfd640b249b4be3799d395.zip
  )
  enable_testing()
  
  set(SOURCE_FILES
    src/BlackListChecker.cpp
    src/AddUrlCommand.cpp
    src/BloomFilter.cpp
    src/CommandFactory.cpp
    src/ConsoleMenu.cpp
    src/InputValidator.cpp
     # this is where the code we want to test
  )
  set(TEST_FILES
    tests/FalsePositiveCheckerTest.cpp
    tests/BlackListCheckerTests.cpp
    tests/AddUrlCommandTest.cpp
    tests/BloomFilterTest.cpp
    tests/CommandFactoryTest.cpp
    tests/ConsoleMenuTest.cpp
    tests/InputValidatorTest.cpp
    tests/test_main.cpp # this is the main for tests tests/calc_test.cpp # this file contain the tests
  )
  add_executable(AdvancedTests ${TEST_FILES})
# Link Google Test to the test executable
  target_link_libraries(AdvancedTests PRIVATE gtest gtest_main)
  # Include the source directory for tests
  target_include_directories(AdvancedTests PRIVATE src)
  include(GoogleTest)
  add_test(NAME AdvancedTests COMMAND AdvancedTests)
