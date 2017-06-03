cmake_minimum_required(VERSION 3.0)
project(stmp)

set(CMAKE_C_STANDARD 99)

add_subdirectory (stmp/src)
configure_file(sample/simple_macro.asm sample/simple_macro.asm COPYONLY)
enable_testing()

add_subdirectory (Test)

#add_test(test_utility_get_word Test/test_utility_get_word)
add_test(test_utility_get_all_lines Test/test_utility_get_all_lines)
add_test(test_get_output_filename Test/test_get_output_file_name)
add_test(test_parse_macro Test/test_parse_macro)
add_test(parse_macro_more_than_one_missing_MEND Test/parse_macro_more_than_one_missing_MEND)
add_test(parse_macro_one Test/parse_macro_one)
add_test(parse_macro_more_than_one_missing_MEND Test/parse_macro_more_than_one_missing_MEND)