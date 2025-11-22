cmake_minimum_required(VERSION 3.10)
project(SortingComparison C)

set(CMAKE_C_STANDARD 99)

# For Windows: ensure we build as console application
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")
endif()

# Include all directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/sorts/bubble_sort
    ${CMAKE_SOURCE_DIR}/sorts/insertion_sort  
    ${CMAKE_SOURCE_DIR}/sorts/heap_sort
)

# Add all source files
add_executable(sorting_comparison
    main.c
    get_time.c
    sorts/bubble_sort/bubble_sort.c
    sorts/insertion_sort/insertion_sort.c
    sorts/heap_sort/heap_sort.c
)