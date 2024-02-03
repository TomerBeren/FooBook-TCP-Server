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
    src/App.cpp
    src/CommandInitializer.cpp
    src/FalsePositiveChecker.cpp
    src/BlackListChecker.cpp
    src/AddUrlCommand.cpp
    src/BloomFilter.cpp
    src/CommandFactory.cpp
    src/ConsoleMenu.cpp
    src/InputValidator.cpp
     # this is where the code we want to test
  )
  set(TEST_FILES
    tests/AppTest.cpp
    tests/CommandInitTest.cpp
    tests/FalsePositiveCheckerTest.cpp
    tests/BlackListCheckerTests.cpp
    tests/AddUrlCommandTest.cpp
    tests/BloomFilterTest.cpp
    tests/CommandFactoryTest.cpp
    tests/ConsoleMenuTest.cpp
    tests/InputValidatorTest.cpp
    tests/test_main.cpp # this is the main for tests tests/calc_test.cpp # this file contain the tests
  )
  include_directories(${CMAKE_SOURCE_DIR}/include)
  add_executable(AdvancedTests ${TEST_FILES} ${SOURCE_FILES})
  target_link_libraries(AdvancedTests gtest gtest_main)
  target_include_directories(AdvancedTests PRIVATE src)

  include(GoogleTest)
  add_test(NAME AdvancedTests COMMAND AdvancedTests)
