project(test_module)

set(SRCS
        "matrix_tests.cpp" trig_tests.cpp trig_tests.h printer.cpp printer.h)

add_library(test_module ${SRCS})
target_link_libraries(test_module mathlib)
target_include_directories(test_module PUBLIC "../math")