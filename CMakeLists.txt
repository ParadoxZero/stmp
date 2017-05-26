cmake_minimum_required(VERSION 3.6)
project(macro_prossesor)

set(CMAKE_C_STANDARD 99)

add_subdirectory (stmp/src)

enable_testing()

add_subdirectory (Test)

add_test(test_utility_get_word Test/test_utility_get_word)
add_test(test_utility_get_all_lines Test/test_utility_get_all_lines)
add_test(test_get_output_filename Test/test_get_output_file_name)