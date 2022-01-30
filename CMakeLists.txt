cmake_minimum_required(VERSION 3.15)

option(BUILD_TESTING "Build tests" OFF)

if (BUILD_TESTING)
    list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif ()

if (NOT VCPKG_ROOT)
    set(VCPKG_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
endif ()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(lux LANGUAGES CXX)

add_subdirectory(examples)