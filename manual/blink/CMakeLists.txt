cmake_minimum_required(VERSION 3.31)

include(F:\\libs\\pico-sdk\\pico_sdk_init.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_BASE_DIR "F:/Code/piko/.cache" CACHE STRING "Global cache for dependencies")

project(blink)

pico_sdk_init()

add_executable(blink
    blink.c
    )

# pull in common dependencies
target_link_libraries(blink pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(blink pico_cyw43_arch_none)
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)