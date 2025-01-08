cmake_minimum_required(VERSION 3.31)

include(F:\\libs\\pico-sdk\\pico_sdk_init.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_BASE_DIR "F:/Code/piko/.cache/" CACHE STRING "Global cache for dependencies")

project(breath)

pico_sdk_init()

add_executable(breath
    breath.cpp
    )

# pull in common dependencies
target_link_libraries(breath pico_stdlib hardware_pwm)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(breath pico_cyw43_arch_none)
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(breath)