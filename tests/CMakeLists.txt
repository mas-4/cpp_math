project(test_module)

set(SRCS
        "matrix_tests.cpp" trig_tests.cpp trig_tests.h harness.cpp harness.h test_funcs.cpp test_funcs.h)

add_library(test_module ${SRCS})
target_link_libraries(test_module mathlib)
target_include_directories(test_module PUBLIC "../math")