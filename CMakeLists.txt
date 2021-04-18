cmake_minimum_required(VERSION 3.10)
project(ArduinoSerialReader CXX)

set(CORE_DIR Core)
set(IMGUI_LIB Core/ImGui/headers)
add_subdirectory(${IMGUI_LIB})
add_subdirectory(${CORE_DIR})