add_library(lux OBJECT lux.cpp)
target_compile_features(lux PRIVATE cxx_std_20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(lux PRIVATE /interface PUBLIC /ifcSearchDir ${CMAKE_CURRENT_BINARY_DIR})
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lux PUBLIC -fmodules-ts)
else ()
    message(FATAL_ERROR "Compiler not supported: ${CMAKE_CXX_COMPILER_ID}")
endif ()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_custom_target(lux_modules
            COMMAND mkdir -p ${CMAKE_BINARY_DIR}/examples/gcm.cache/
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/gcm.cache/*.gcm ${CMAKE_BINARY_DIR}/examples/gcm.cache/
            DEPENDS lux)
endif ()
