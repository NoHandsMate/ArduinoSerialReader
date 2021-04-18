add_library(IMGUI
        imgui.h
        imgui.cpp
        imgui_widgets.cpp
        imgui_tables.cpp
        imgui_draw.cpp)

set_target_properties(IMGUI PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(IMGUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
