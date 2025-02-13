cmake_minimum_required(VERSION 3.22)

project(CMSIS)
add_library(CMSIS INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# file(GLOB CMSIS_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}//cmsis-device-g0/*.c)

target_include_directories(CMSIS INTERFACE
${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeG0/Drivers/CMSIS/Device/ST/STM32G0xx/Include
${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeG0/Drivers/CMSIS/Include
)

# target_sources(CMSIS PUBLIC
#     ${CMSIS_SRC_FILES}
#     # Add user sources here
# )

target_link_directories(CMSIS INTERFACE
)

target_link_libraries(CMSIS INTERFACE
)

message("Drivers loaded")

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()