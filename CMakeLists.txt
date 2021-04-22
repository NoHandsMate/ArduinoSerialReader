cmake_minimum_required(VERSION 3.10)
project(ArduinoSerialReader CXX)

set(CMAKE_CXX_STANDARD 20)

set(CORE_DIR Core)
set(IMGUI_LIB Core/ImGui/headers)
add_subdirectory(${IMGUI_LIB})
add_subdirectory(${CORE_DIR})
add_subdirectory(${CORE_DIR}/GUI)
add_subdirectory(${CORE_DIR}/Serial)
