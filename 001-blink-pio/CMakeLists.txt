cmake_minimum_required(VERSION 3.13)
 
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)
 
project(blink_pio C CXX ASM)
 
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
 
pico_sdk_init()
 
add_executable(${PROJECT_NAME} main.c)

# create c header file with the name <pio program>.pio.h
pico_generate_pio_header(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/blink.pio
)
 
pico_add_extra_outputs(${PROJECT_NAME})
 
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_pio)
 
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
