cmake_minimum_required(VERSION 3.13...3.27)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(F:\\libs\\pico-sdk\\pico_sdk_init.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(FETCHCONTENT_BASE_DIR "F:/Code/piko/.cache" CACHE STRING "Global cache for dependencies")

project(helloworld)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(helloworld
    helloworld.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(helloworld pico_stdlib)

# 启用USB串口
pico_enable_stdio_usb(helloworld 1)
# 关闭UART
pico_enable_stdio_uart(helloworld 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(helloworld)

# message(STATUS "Using C compiler: ${CMAKE_C_COMPILER}")
# message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER}")