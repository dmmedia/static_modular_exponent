cmake_minimum_required(VERSION 3.10)
project (StaticModExp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Tests that compile
add_executable(test_ok src/test_ok.cpp)
# Tests that fail to compile
add_executable(test_base_nok src/test_base_nok.cpp)
add_executable(test_power_nok src/test_power_nok.cpp)
add_executable(test_modulus_nok src/test_modulus_nok.cpp)

# Avoid building these targets normally
set_target_properties(test_ok test_base_nok test_power_nok test_modulus_nok PROPERTIES
                      EXCLUDE_FROM_ALL TRUE
                      EXCLUDE_FROM_DEFAULT_BUILD TRUE)

# Add C++ flags
target_include_directories(test_ok PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(test_ok PRIVATE -Wall -Werror -Wextra -pedantic -std=c++17)
#target_compile_features(test_ok PRIVATE cxx_std_17)
target_include_directories(test_base_nok PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(test_base_nok PRIVATE -Wall -Werror -Wextra -pedantic -std=c++17)
#target_compile_features(test_ok PRIVATE cxx_std_17)
target_include_directories(test_power_nok PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(test_power_nok PRIVATE -Wall -Werror -Wextra -pedantic -std=c++17)
#target_compile_features(test_ok PRIVATE cxx_std_17)
target_include_directories(test_modulus_nok PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(test_modulus_nok PRIVATE -Wall -Werror -Wextra -pedantic -std=c++17)
#target_compile_features(test_ok PRIVATE cxx_std_17)

# Add the tests.  These invoke "cmake --build ..." which is a
# cross-platform way of building the given target.
add_test(NAME Test1
         COMMAND ${CMAKE_COMMAND} --build . --target test_ok --config $<CONFIGURATION>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
add_test(NAME Test2
         COMMAND ${CMAKE_COMMAND} --build . --target test_base_nok --config $<CONFIGURATION>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
add_test(NAME Test3
         COMMAND ${CMAKE_COMMAND} --build . --target test_power_nok --config $<CONFIGURATION>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
add_test(NAME Test4
         COMMAND ${CMAKE_COMMAND} --build . --target test_modulus_nok --config $<CONFIGURATION>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# Expect these tests to fail (i.e. cmake --build should return
# a non-zero value)
set_tests_properties(Test2 Test3 Test4 PROPERTIES WILL_FAIL TRUE)
