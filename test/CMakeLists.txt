cmake_minimum_required(VERSION 3.16)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(test test.cc)
target_link_libraries(test httplib OpenSSL::SSL OpenSSL::Crypto GTest::gtest_main)
gtest_discover_tests(test)