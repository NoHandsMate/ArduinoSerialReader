add_library(SERIAL
        SerialInterface.cpp Log.hpp)

set_target_properties(SERIAL PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(SERIAL PUBLIC CppLinuxSerial)
target_link_directories(SERIAL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})