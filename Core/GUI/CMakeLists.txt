add_library(GUI
        window_handler.hpp
        window_handler.cpp)

set_target_properties(GUI PROPERTIES LINK_LANGUAGE CXX)
target_link_libraries(GUI PUBLIC IMGUI)
target_link_directories(GUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})