
add_library(stmp_utility stmp_utility.c stmp_utility.h)
add_library(stmp_process stmp_process.c stmp_process.h)
target_link_libraries(stmp_process stmp_utility)

add_executable(stmp main.c)

target_link_libraries(stmp stmp_utility)
target_link_libraries(stmp stmp_process)

install(TARGETS stmp stmp_utility stmp_process
RUNTIME DESTINATION bin
ARCHIVE DESTINATION lib
LIBRARY DESTINATION lib
)
