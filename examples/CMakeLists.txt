add_executable(basic_example basic.cpp)
target_link_libraries(basic_example PRIVATE lux)
target_compile_features(basic_example PRIVATE cxx_std_20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_dependencies(basic_example lux_modules)
endif ()